#include "A8.h"

struct sockaddr_in  myAddr, clientAddr, addr;
/*int main()
{
    int mySocket;
    struct sockaddr_in addr;
    
    createSocket(&mySocket);
    setAddress(&addr);
    connectTo(&mySocket, &addr);
    talk(&mySocket);
    close(mySocket);
    return 0;
}*/
    
/* create socket */
void createSocket(int *sock){
  *sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
  if (sock < 0) {
    printf("Couldn't open socket: Program will quit\n");
    exit(-1);
  }
/* setup address */

    memset(&addr, 0, sizeof(addr));
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(SERVER_IP);
    addr.sin_port = htons((unsigned short) PORT);
}
/* connect to server */
 
void connectTo(int *sock){
    int i;
    i = connect(*sock, (struct sockaddr *) &addr,sizeof(addr));
    if (i<0) {
        printf("Client could not connect: Program will quit\n");
        exit(-1);
    }
}
 
/* get input from user and send to server */
void talk(int *sock){
 
    char inStr[100];
    char buffer[100];
        printf("what is your message?");
        fgets(inStr, sizeof(inStr), stdin);
        inStr[strlen(inStr)-1] = 0;
        strcpy(buffer, inStr);
        send(*sock, buffer, strlen(buffer), 0);
 
        if(strcmp(inStr, "quit") == 0){return;}
        printf("Waiting for response please wait...\n");
        listenTo(sock);         
}
