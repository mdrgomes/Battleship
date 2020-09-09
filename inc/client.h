#ifndef CLIENT_H
#define CLIENT_H

#include <stdio.h> 
#include <netdb.h> 
#include <unistd.h>
#include <netinet/in.h> 
#include <arpa/inet.h>
#include <stdlib.h> 
#include <string.h> 
#include <sys/socket.h> 
#include <sys/types.h>
//#include "quadtree.h"
#include "game.h"
#include "battleship.h"
#include "point.h"


#define MAX 80 
#define PORT 8080 
#define SA struct sockaddr 


int inicializeClient();
void funcCli(int sockfd);
Coordinate createCoordAtack();
int handlerBuffer(char buffe[]);
void closeCliSocket(int sockfd);
int getSizeFromServer(int sockfd);
char *getRivalName(int sockfd);
#endif