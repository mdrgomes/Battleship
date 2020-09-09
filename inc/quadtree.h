#ifndef QUADTREE_H
#define QUADTREE_H

#include "cell.h"
#include "point.h"
#include "ship.h"
#include "battleship.h"


typedef enum {NW, NE, SW, SE, MAX_Q} Quadrant;

typedef enum {QDNODE, QDLEAF} QD_TNODE;

typedef struct QD_NODE_
{
	QD_TNODE type;

	union {
		struct QD_NODE_ *quadrants[4];
		struct{
			Coordinate p;
			Cell *Cel;
		}leaf;
	}node;
	
}QD_NODE;


QD_NODE *newLeaf(Coordinate cord, Cell *value);
int searchShipPoint(QD_NODE *quadtree, Coordinate point, Coordinate middle, int size);
QD_NODE *insertPoint(QD_NODE *Node, Cell *celula, Coordinate point, Coordinate middle, int size);
void printLeaf(QD_NODE *Node);
QD_NODE *addShipOnQuad(QD_NODE *Node,SHIP *b, Coordinate cord, Coordinate middle,int size);
void printQuadTree(QD_NODE *Node, Coordinate middle,int size);
int searchCell(QD_NODE *quadtree, Coordinate point, Coordinate middle, int size);
Boolean searchPoint(QD_NODE *quadtree, Coordinate point, Coordinate middle, int size);
Boolean verifyCoordQuad(QD_NODE *Node, int bitmap[], Coordinate point, Coordinate middle, int size);
QD_NODE *RandomPlaceOnQuad(QD_NODE *Node, Coordinate middle, int size);
Coordinate getMiddle(Coordinate pos, Quadrant quad, int size);
Quadrant getQuadrant(Coordinate middle, Coordinate pos);
QD_NODE *buildQuadTree(QD_NODE *Node, Coordinate middle, int size, int player);


void createQuad(Coordinate middle, int size);
//RandomPlaceOnQuad

//verificar na intruduçao manual os limites
#endif