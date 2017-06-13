$(document).ready(function() {
    const userName = prompt("What's your name?") || "User";
    const socket = io(); //connect to the server that sent this page

    socket.on("connect", function() {
        socket.emit("intro", userName);
    });

    $("#inputText").keypress(function(ev) {
        if (ev.which === 13) {
            //send message
            socket.emit("message", $(this).val());
            ev.preventDefault(); //if any
            $("#chatLog").append((new Date()).toLocaleTimeString() + ", " + userName + ": " + $(this).val() + "\n");
            $(this).val(""); //empty the input
        }
    });

    socket.on("message", function(data) {
        $("#chatLog").append(data + "\n");
        $("#chatLog")[0].scrollTop = $("#chatLog")[0].scrollHeight; //scroll to the bottom
    });

    socket.on("userList", function(currUsers) {
        $("#userList").empty(); //empty list for ease of update
        currUsers.forEach(function(user) { //simple for loop -> go through each user with socket
            const element = $('<li>' + user + '</li>'); // create list item

            element.dblclick(function(val) { //this event is added before appending to the parent node otherwise it is ignored
                if (val.shiftKey) { //http://stackoverflow.com/questions/19521596/ctrl-click-in-javascript <- found event here
                    const BlockedUser = $(this).text(); //get text node of the list item *DOM
                    socket.emit("blockUser", user); //send text node to server to add to sockets blocked list
                }
            });

            /*
            element.dbclick(function() {
                const user = $(this).text();
                prepMessage(("Send a PM to " + user), user);
            });*/

            $("#userList").append(element); //then add list item
        });
    });

    /*
    function prepMessage(fromMessage, user) {
        var toMessage = prompt(fromMessage);
        var data;
        if (toMessage) {
            data.username = user;
            data.message = toMessage;
            socket.emit("privateMessage", data);
        }
    }

    socket.on("privateMessage", function(data) {
        prepMessage(data.message, data.username);
    });*/
});
