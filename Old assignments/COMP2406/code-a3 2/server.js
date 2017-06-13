/*SocketIO based chat room. */
//simple server listens on the provided port and responds with requested files
//updated to use asynchronous callback style.

// load necessary modules
const http = require('http').createServer(handleRequest);
const fs = require('fs');
const mime = require('mime-types');
const url = require('url');
const ROOT = "./files";
const io = require('socket.io')(http);

http.listen(2406);

console.log('Chat server listening on port 2406');
//process the request
function handleRequest(req, res) {

    //log the request
    console.log(req.method + " request for: " + req.url);

    //parse the url
    var urlObj = url.parse(req.url);
    var filename = ROOT + urlObj.pathname;

    //the callback sequence for static serving...
    fs.stat(filename, function(err, stats) { //async
        if (err) { //try and open the file and handle the error
            respondErr(err);
        } else if (stats.isDirectory()) {
            fs.readFile(filename + "index.html", function(err, data) { //async
                if (err) {
                    respondErr(err);
                } else {
                    respond(200, data, mime.lookup(filename + "index.html"));
                }
            });
            //handle the serving of data
        } else {
            fs.readFile(filename, function(err, data) {
                if (err) {
                    respondErr(err);
                } else {
                    respond(200, data, mime.lookup(filename));
                }
            });
        }

        //locally defined helper function
        //serves 404 files
        function serve404() {
            fs.readFile(ROOT + "/404.html", function(err, data) { //async
                if (err) respond(500, err.message, null);
                else respond(404, data, mime.lookup(filename));
            });
        }

        //locally defined helper function
        //responds in error, and outputs to the console
        function respondErr(err) {
            console.log("Handling error: ", err);
            if (err.code === "ENOENT") {
                serve404();
            } else {
                respond(500, err.message, null);
            }
        }
        //locally defined helper function
        //sends off the response message
        function respond(code, data, contentType) {
            // content header
            res.writeHead(code, {
                'content-type': contentType || 'text/html'
            });
            // write message and signal communication is complete
            res.end(data);
        }
    }); //end handle request
}

var users = [];

io.on("connection", function(socket) {
    socket.on("intro", function(username) {
        console.log("Got a connection from: " + username);
        socket.username = username;
        users.push(this);
        socket.broadcast.emit("message", timestamp() + ": " + socket.username + " has entered the chatroom.");
        socket.emit("message", "Hi " + socket.username + "!");
        socket.blockedUsers = [];
        io.emit("userList", users.map(function(user) {
            return user.username;
        }));
    });

    socket.on("message", function(data) {
        console.log("got message: " + data);
        socket.broadcast.emit("message", timestamp() + ", " + socket.username + ": " + data);
    });

    socket.on("disconnect", function() {
        console.log(socket.username + " disconnected");
        users = users.filter(function(user) {
            return user !== socket;
        });
        io.emit("message", timestamp() + ": " + socket.username + " disconnected.");
        io.emit("userList", users.map(function(user) {
            return user.username;
        }));
    });

    //broken code, could not implement user receival filtration from client side script
    socket.on("blockUser", function(user) {
        const blocked = socket.blockedUsers.indexOf(user); //create user object to work with
        //console.log(blocked);
        if (blocked > -1) { //otherwise we will unblock him
            socket.blockedUsers.splice(blocked, 1);
            socket.emit("message", user + " is now unblocked"); //only let the user un-blocking other user know the work done
        } else { //if the user was not blocked we will now block him
            socket.blockedUsers.push(user);
            socket.emit("message", user + " is now blocked"); //only let the user blocking other user know the work done
        }
    });
    /* //This section is incomplete, I could not query the the array of sockets properly to pull up the right socket.
    socket.on("privateMessage", function(inPM){
    		var outPM;
    		var sendee = users.find(function(user){
    			return user.username === inPM.user;
    		});
    		if (sendee !== undefined) {
    			if (sendee.blockedUsers.find(function(blockedUser){return blockedUser === socket.username;}) === undefined){
    				outPM.sender = socket.username;
    				outPM.message = (inPM.pm);
    			}
    			sendee.emit("privateMessage", outPM);
    		}
    });*/
});

function timestamp() {
    return new Date().toLocaleTimeString();
}
