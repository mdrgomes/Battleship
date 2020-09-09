#include "cell.h"

#define C_MSHOOT(Q)  ((Q) -> myshoot)
#define C_RSHOOT(Q)  ((Q) -> rivalShoot)
#define C_BOAT(Q)  ((Q) -> boat)

Cell *newCell(SHIP *b){
	Cell *new = malloc(sizeof(Cell));
	C_MSHOOT(new) = 0;
	C_RSHOOT(new) = 0;
	C_BOAT(new) = b;
	return new;
}

Cell *newEmptyCell( SHIP *b, int value, int v){
	Cell *new = malloc(sizeof(Cell));
	C_MSHOOT(new) = value;
	C_RSHOOT(new) = v;
	C_BOAT(new) = b;
	return new;
}

void destroy_cell(Cell *c){
	free(c);
}