#include <string.h>
#include <stdio.h>

#include "quadtree.h"
#include "cell.h"
#include "game.h"
#include "server.h"
#include "client.h"

int main(int argc, char const *argv[]){
	LoadShips();
	system("clear");
	initscreen();
	printf("Press enter to continue\n");
	getchar();
	system("clear");
	
	int size = getSize();

 	Coordinate middle = make_point(size/2,size/2);

 	QD_NODE *playerOne = NULL;
 	QD_NODE *playerTwo = NULL;
 	
 	playerOne = buildQuadTree(playerOne,middle,size,PLAYER_ONE);
	printQuadTree(playerOne,middle,size);

	printf("Press enter to continue\n");
	getchar();
	getchar();
	system("clear");

 	playerTwo = buildQuadTree(playerTwo,middle,size,PLAYER_TWO);
	printQuadTree(playerTwo,middle,size);

	printf("Press enter to continue\n");
	getchar();
	getchar();
	system("clear");

	playGame(playerOne,playerTwo,middle,size);
	free(playerOne);
	free(playerTwo);
	printf("CONGRATS!!!!!\n");
	return 0;
}
//version to Work with tcp socket connection 
//still in progress
/*
	char playerN[20];
	char *playerName=NULL;
	char *rivalName=NULL;
	int size;
	int socket;
	int comand;
	menuName();
	scanf("%s",playerN);
	playerName = playerN;
	comand = chooseServer();
	if(comand==1){
		size = getSize();
		socket = inicializeServer(size);
		sendSizeToClient(socket,size);
		sendSizeToClient(socket,ROWS);
		sendNameToClient(socket, playerName);
		//rivalName = receibeRivalName(socket);
		//func(socket);
	}
	else{
		socket = inicializeClient();
		//funcCli(socket);
		size = getSizeFromServer(socket);
		printf("%d\n", size);
		ROWS = getSizeFromServer(socket);
		COLS =ROWS; 
		rivalName = getRivalName(socket);
		printf("%s\n", rivalName); 
		//sendNameToServer(socket,playerName);
	}
 	//Coordinate middle = make_point(size/2,size/2);
 	//QD_NODE *playerOne = NULL;
 	//QD_NODE *playerTwo = NULL;
 	
 	//playerOne = buildQuadTree(playerOne,middle,size,PLAYER_ONE);
	//printQuadTree(playerOne,middle,size);

	//playGame(playerOne,playerTwo,middle,size);
	int player ;
	if(comand==1){
		player = inicializeServer(playerOne, middle, size, PLAYER_ONE);
	}
	else
		player = inicializeClient(playerOne, middle, size, PLAYER_ONE);
	//free(playerOne);
	//free(playerTwo);
	if(comand==1){
		closeSocket(socket);
	}
	else{
		closeCliSocket(socket);
	}
	
	printf("CONGRATS!!!!!\n");*/