#include "A8.h"

struct sockaddr_in  myAddr, clientAddr, addr;
int main(){
    int choice = 0;
    while(1){
        initChat(&choice);
    }
    return 0;
}

void initChat(int *c){
    char strIn[MAX_STR];
    printf ("\n\n**************************************************\n");
    printf ("*****    Welcome to the assignment 8 Menu    *****\n");
    printf ("**************************************************\n");
    printf("\n\n Please select one of the following \n");
    printf(" 1. Talk (select this to connect to a server.)\n");
    printf(" 2. Wait (select this to allow someone else to talk to you.)\n");
    printf(" 3. Exit (select this to close the application)\n"); 
    printf("\n Waiting for your choice here: ");
    readString(strIn);
    toLowerCase(strIn);
    *c = verifyChoice(strIn);
    start(c);
}    

void start(int *c){   
    if(*c == 1){
        printf("\nYou selected \"Talk\", starting client...\n");
        int mySocket;
    
        createSocket(&mySocket);
        printf("Socket created!\n");
        printf("Trying to connect now...\n");
        connectTo(&mySocket);
        printf("To quit to main menu, enter \"quit\".\n");
        talk(&mySocket);
        close(mySocket);
        
    } else if(*c == 2) {
        printf("\nYou selected \"Wait\", starting server...\n");  
        int myListenSocket, clientSocket;
        createSrvSocket(&myListenSocket);
        printf("Socket created!\n");
        setSrvAddress();
        bindSocket(&myListenSocket);
        printf("Socket binded!\n");
        printf("Waiting for someone to connect...\n");
        waitForConnection(&myListenSocket, &clientSocket);
        printf("Someone connected! To quit, enter \"quit\" on your turn to talk\n");
        listenTo(&clientSocket);
        
        close(myListenSocket);
        close(clientSocket);
    
    }
    else if(*c == 3){
        printf("\nYou selected \"Exit\", Goodbye :)\n");
        exit(0);
    }
    else{
        printf("What? Something went wrong :S");
        exit(-1);
    }
}

int verifyChoice(char *str){
    do{
        if(strcmp(str,"1")==0 || strcmp(str,"talk")==0){
            return 1;
        } else if(strcmp(str,"2")==0 || strcmp(str,"wait")==0){
            return 2;
        } else if(strcmp(str,"3")==0 || strcmp(str,"exit")==0){
            return 3;
        } else {
            printf("Value entered was incorrect, re-enter: ");
            readString(str);
            toLowerCase(str);
        } 
    }while(1);
}

void toLowerCase(char *str){
    int i;
    for(i = 0; i < MAX_STR; i++){
        str[i] = tolower(str[i]);
    }
}
void readString(char *str){
  char tmpStr[MAX_STR];

  fgets(tmpStr, sizeof(tmpStr), stdin);
  tmpStr[strlen(tmpStr)-1] = '\0';
  strcpy(str, tmpStr);
}

