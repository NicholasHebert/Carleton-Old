#include "A8.h"

struct sockaddr_in  myAddr, clientAddr, addr;

/*int main()
{  
  int myListenSocket, clientSocket, mySocket;
  struct sockaddr_in  myAddr, clientAddr;
  
  createSrvSocket(&myListenSocket);
  setSrvAddress(&myAddr);
  bindSocket(&myListenSocket, &myAddr);
  waitForConnection(&myListenSocket, &clientAddr, &clientSocket);
  listenTo(&clientSocket);
 
  close(myListenSocket);
  close(clientSocket);
 
  return 0;
}*/

/* create socket */
void createSrvSocket(int *sock){ 
    *sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (*sock < 0) {
        printf("Couldn't open socket: Program will quit.\n");
        exit(-1);
    }
}
 
/* setup my server address */
void setSrvAddress(){
    memset(&myAddr, 0, sizeof(myAddr));
    myAddr.sin_family = AF_INET;
    myAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    myAddr.sin_port = htons((unsigned short) PORT);
}

/* bind my listen socket */
void bindSocket(int *sock){ 
    int i;
    i = bind(*sock,(struct sockaddr *) &myAddr,
        sizeof(myAddr));
    if (i < 0) {
        printf("Couldn't bind socket: Program will quit\n");
        exit(-1);
    }
}

/* listen */
void waitForConnection(int *sock, int *cSocket){
  int i; 
  unsigned int addrSize;
  i = listen(*sock, 5);
  if (i < 0) {
    printf("Couldn't listen: Program will quit\n");
    exit(-1);
  }
  
/* wait for connection request */
    addrSize = sizeof(clientAddr);
 
    *cSocket = accept(*sock,(struct sockaddr *) &clientAddr, &addrSize);
    if (cSocket < 0) {
        printf("Couldn't accept the connection: Program will quit\n");
        exit(-1);
    }
}
 
/* read message from client and do something with it */
void listenTo(int *cSocket) {
    int bytesRcv = 0;
    char buffer[100];
    while (1) {
        bytesRcv = recv(*cSocket, buffer, sizeof(buffer), 0);
        if (bytesRcv > 0) {
            break;
        }
    }

    buffer[bytesRcv] = 0;
    printf("this is what the client sent: %s\n", buffer);

    if(strcmp(buffer, "quit") == 0)
        return;
        
    talk(cSocket);
}
