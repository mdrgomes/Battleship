#include "battleship.h"

/*imprimir ecra pincipal*/
void initscreen () {
	printf ("XXXXX   XXXX  XXXXXX XXXXXX XX     XXXXXX  XXXXX XX  XX XX XXXX\n");
	printf ("XX  XX XX  XX   XX     XX   XX     XX     XX     XX  XX XX XX  XX\n");
	printf ("XXXXX  XX  XX   XX     XX   XX     XXXX    XXXX  XXXXXX XX XXXX\n"); 
	printf ("XX  XX XXXXXX   XX     XX   XX     XX         XX XX  XX XX XX\n");
	printf ("XXXXX  XX  XX   XX     XX   XXXXXX XXXXXX XXXXX  XX  XX XX XX\n");
	printf ("\n\n");
	printf ("RULES OF THE GAME:\n");
	printf ("1. This is a two player game.\n");
	printf ("2. You can choose to insert the ship coordinates manually or\n");
	printf ("   or have the computer randomly generate the location of the ships\n");
	printf ("3. There are five types of ships to be placed\n"); 
	printf ("4. The game begins as each player tries to guess the location of the ships\n");
	printf ("   of the opposing player's game board; [*] hit and [m] miss\n");
	printf ("5. First player to guess the location of all ships wins\n\n");
	printf("GOOD LUCK\n");
}

void menuChoose(int player){
	printf("Player %d it's your turn\n",player);
	printf ("> Please select from the following menu:\n");
	printf ("> [1] Manually\n");
	printf ("> [2] Randomly\n");
	printf ("> Enter Option: ");
}

/*imprimir menu inicial*/
void print_menu_init(){
	printf("Welcome\n");
	printf("1)Log In\n");
	printf("2)Sign Up\n");
}

int getSize(){
	printf("Definde the board size, between 20 and 40\n");
 	scanf("%d",&ROWS);
 	while(ROWS<20 || ROWS>40){
 		printf("Wrong Number, choose again a number between 20 and 40\n");
 		scanf("%d",&ROWS);
 	}
 	COLS = ROWS;
 	if(ROWS >32)
 		return 64;
 	else
 		return 32;
}

int chooseServer(){
	printf("Are you a client or a server\n");
	printf("Chose 1) ofr server and 2 for client\n");
	int comand;
	scanf("%d",&comand);
 	if(comand==1){
 		return 1;
 	}
 	else{
 		return 2;
 	}
}

void menuName(){
	printf("Hi You're currently playing battleship\n");
	printf("Please choose a nick name (NO SPACES)\n");
	printf("nick: ");
}