#ifndef POINT_H
#define POINT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "quadtree.h"

typedef enum {
	FALSE, TRUE
} Boolean;

typedef struct coordinate {
	int        row;
	int        column;
} Coordinate;

int isEqual(Coordinate pont, Coordinate point);
Boolean isPowerOfTwo(int n);
Coordinate make_point(int x,int y);
void printCord(Coordinate cord);

#endif