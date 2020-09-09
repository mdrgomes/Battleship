#ifndef PLAYER_H
#define PLAYER_H

#include <stdio.h>
#include <stdlib.h>

typedef struct player {
	int player_id;
	char name[20];
	int password;
	int active;
}Player;

int MAX_USERS;
Player users[200];

int search_user(char username[], char pass[]);
int log_in();
int log_in();
void LoadPlayers();

#endif
