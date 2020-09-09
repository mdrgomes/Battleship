#ifndef SHIP_H
#define SHIP_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_SIZE 26


int NUM_SHIPS;
int NUM_SHIPS_CELL;


typedef struct ship{
  int nshoot;
  int type;
  int shape[MAX_STRING_SIZE];
} SHIP;

SHIP boats[200];


//void copy_array(SHIP *s,int tipo);
void printShip(int str[],int value);
int Rotate(int px, int py, int r);
void printBoatName(int value);
char suportLanguage(int value);
SHIP *newShip(int bitmap[], int value, int n);

#endif