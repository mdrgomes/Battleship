#ifndef BATTLESHIP_H
#define BATTLESHIP_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "quadtree.h"
#include "ship.h"
#include "cell.h"
#include "database.h"


#define NUMBER_OF_STRING 5

int ROWS;
int COLS;

#define WATER  0
#define HIT    1
#define MISS   2
#define ERROR  3

#define PLAYER_ONE    0
#define PLAYER_TWO    1


void initscreen();
void print_menu_init();
void menuChoose(int player);
int getSize();
int chooseServer();
void menuName();

#endif