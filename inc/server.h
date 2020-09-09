#ifndef SERVER_H
#define SERVER_H

#include <stdio.h> 
#include <netdb.h> 
#include <netinet/in.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h>
#include <sys/socket.h> 
#include <sys/types.h>
//#include "quadtree.h"
#include "game.h"
#include "battleship.h"
#include "point.h"


#define MAX 80 
#define PORT 8080 
#define SA struct sockaddr 


int inicializeServer(int size);
void func(int sockfd);
Coordinate createCoordAtack();
int handlerBuffer(char buffe[]);
void closeSocket(int sockfd);
void sendSizeToClient(int sockfd, int size);
void sendNameToClient(int sockfd, char *name);
#endif