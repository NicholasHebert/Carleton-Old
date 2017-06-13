
OPTIONS = -g -Wall
OBJ = chat.o client.o server.o

a8: $(OBJ)
	gcc -o a8 $(OPTIONS) chat.o client.o server.o
    
chat.o: chat.c A8.h
	gcc -c $(OPTIONS) chat.c

client.o: client.c A8.h
	gcc -c $(OPTIONS) client.c

server.o: server.c A8.h
	gcc -c $(OPTIONS) server.c
    
clean:
	rm $(OBJ) a8
