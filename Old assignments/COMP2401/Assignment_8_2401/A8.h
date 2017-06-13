//A8.h
#ifndef CLIENT_H_INCLUDED
#define CLIENT_H_INCLUDED

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define MAX_STR 64
#define PORT 60002
#define SERVER_IP "127.0.0.1"

extern struct sockaddr_in  myAddr, clientAddr, addr;

//client.c prototypes
void createSocket(int *);
void connectTo(int *);
void talk(int *);

//server.c prototypes
void createSrvSocket(int *);
void setSrvAddress();
void bindSocket(int *);
void waitForConnection(int *, int *);
void listenTo(int *);

//chat.c prototypes
void initChat(int *);
int verifyChoice(char *);
void toLowerCase(char *);
void readString(char *);
void start(int *);

#endif
