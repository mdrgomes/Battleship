#ifndef STATS_H
#define STATS_H

#include <stdio.h>
#include <stdlib.h>
#include "player.h"
#include "battleship.h"
#include "database.h"

/*struct Stats{
	Player *nick;
	int points;
    struct Stats *next; 
};
*/
struct gameStat{
	int player;
	int points;
};

/*void insertAtTheBegin(struct Stats **start, int data, Player *name);
void bubbleSort(struct Stats *start);*/
//Boolean checkGame(int player);
#endif