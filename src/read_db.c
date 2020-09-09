#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "database.h"


/*void print_struct(Player users[MAX_USERS]){
	for (int i = 0; i < MAX_USERS; ++i)
	{

		printf("player: %d\n", users[i].player_id);
		printf("name: %s\n", users[i].name);
		printf("password: %d\n",users[i].password );
		printf("active: %d\n", users[i].active);
		printf("-------------------END--------------\n");
	}
}

void LoadPlayers()
{
	FILE *fp = fopen("test.txt", "r");
      if(fp == NULL) {
          perror("Unable to open file!");
          exit(1);
     } 
     int count=0;
     char chunk[128]; 
     while(fgets(chunk, sizeof(chunk), fp) != NULL) {
         char *token = strtok(chunk, ";");
         int i=0;
          while (token != NULL){
         	if (i==0)
	    	{
	    		int a =atoi(token);
	    		users[count].player_id= a;
	    	}
	    	else if (i==1)
	    	{	
	 			strcpy(users[count].name,token);
	    	}
	    	else if (i==2)
	    	{
	    		int a =atoi(token);
	    		users[count].password= a;
	    	}
	    	else if(i==3){
	    		int a =atoi(token);
	    		users[count].active=a;
	    	}
	    	token = strtok(NULL, ";"); 
	    	i++;
         }
         count++;
     }
 
     fclose(fp);

     MAX_USERS=count;

    //print_struct(users);
    
	//return 0;
}
*/
/*Carregar os barcos na base de dados*/
void LoadShips(){

	FILE *fp = fopen("DB/ship.txt", "r");
      if(fp == NULL) {
          perror("Unable to open file!");
          exit(1);
     } 
     int n_boats=0;
     int n_cellBoats=0;
     char chunk[128]; 
     while(fgets(chunk, sizeof(chunk), fp) != NULL) {
     	n_cellBoats=0;
     	 boats[n_boats].type=n_boats+4;
         char *token = strtok(chunk, ";");
         int i=0;
          while (token != NULL){
          	int a =atoi(token);
         	boats[n_boats].shape[i]=a;
         	if(a!=WATER)
         		n_cellBoats++;
	    	token = strtok(NULL, ";"); 
	    	i++;
         }
         boats[n_boats].nshoot=n_cellBoats;
         n_boats++;
     }
 
     fclose(fp);

     NUM_SHIPS=n_boats;
     //NUM_SHIPS_CELL=n_cellBoats;
}

/*int search_user(char username[], char pass[]){
	for (int i = 0; i < MAX_USERS; ++i)
	{
		if(strcmp(username,users[i].name)&& strcmp(pass,users[i].password)){
			return users[i].player_id;
		}
	}
	return 0;
}

int log_in(){
	int new;
	char username[20], pass[20];
	printf("Username: ");
	scanf("%s",username);
	printf("\n" );
	printf("Password: ");
	scanf("%s",pass);
	new = search_user(username, pass);
	return new;
}*/