#ifndef CELL_H
#define CELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ship.h"

typedef struct cell {
	int       myshoot;
	int 	  rivalShoot;
	SHIP      *boat; 
} Cell;

Cell *newCell(SHIP *b);
Cell *newEmptyCell(SHIP *b, int value, int n);
void destroy_cell(Cell *c);

#endif