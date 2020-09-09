#ifndef GAME_H
#define GAME_H

#include "quadtree.h"
#include "point.h"
#include "battleship.h"

#include <stdio.h>
#include <stdlib.h>



void playGame(QD_NODE *playerOne,QD_NODE *playerTwo,Coordinate middle, int size);
int search_MY_Point(QD_NODE *quadtree, Coordinate point, Coordinate middle, int size);
int search_R_Point(QD_NODE *quadtree, Coordinate point, Coordinate middle, int size);
int search_Point(QD_NODE *quadtree, Coordinate point, Coordinate middle, int size);
void printTree(QD_NODE *Node, Coordinate middle,int size, int flag);
QD_NODE *changeRivalBoard(QD_NODE *Node,Coordinate point, Coordinate middle, int size, int value);
QD_NODE *changeMyBoard(QD_NODE *Node,Coordinate point, Coordinate middle, int size, int value);
#endif