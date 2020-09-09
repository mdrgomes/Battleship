#include "ship.h"

const char *BNames[] = {"Boat Carrier","Boat Battleship","Boat Cruiser","Boat Submarine","Boat Destroyer","OTHER"};

#define S_NSHOOT(Q)  ((Q) -> nshoot)
#define S_TYPE(Q)  ((Q) -> type)
#define S_SHAPE(Q)  ((Q) -> shape)

//  =======    protoptipos de funções auxiliares =====================================
static void fatalError(char msg[]);
static void copy_array(int dest[],int source[], int n);
static void print_table(int str[], int n, int ncols);
//======================================================================================


void printBoatName(int value){ 
  printf("%s\n",BNames[value]);
}

char suportLanguage(int value){
	int array[MAX_STRING_SIZE]={'~','x','m','a','b','c','d','e','f','g','h','i','j','k','l','n','o','p','q','r','s','t','u','v','z'};
	return array[value];
}

void printShip(int str[], int value){//Print Ship with modification
  printBoatName(value);
  print_table(str,  MAX_STRING_SIZE, 5);
  printf("\n");	
}

void destroy_ship(SHIP *s){
	free(s);
}

int Rotate(int px, int py, int r)
{
	int pi = 0;
	switch (r % 5)
	{
	case 0: // 0 degrees			// 0  1  2  3
		pi = py * 5 + px;			// 4  5  6  7
		break;						// 8  9 10 11
									//12 13 14 15

	case 1: // 90 degrees			//12  8  4  0
		pi = 20 + py - (px * 5);	//13  9  5  1
		break;						//14 10  6  2
									//15 11  7  3

	case 2: // 180 degrees			//15 14 13 12
		pi = 24 - (py * 5) - px;	//11 10  9  8
		break;						// 7  6  5  4
									// 3  2  1  0

	case 3: // 270 degrees			// 3  7 11 15
		pi = 4 - py + (px * 5);		// 2  6 10 14
		break;						// 1  5  9 13
	}								// 0  4  8 12

	return pi;
}

SHIP *newShip(int bitmap[], int value, int n){
  SHIP *nova=malloc(sizeof(SHIP));
  if (nova == NULL) 
    fatalError("Cannot allocate memory for a new ship\n");
  
  S_NSHOOT(nova)=n;
  S_TYPE(nova)=value;
  copy_array(S_SHAPE(nova),bitmap,MAX_STRING_SIZE);
  
  return nova;
}
static void copy_array(int dest[],int source[], int n) {
  for (int i = 0; i < n; ++i) 
    dest[i] = source[i];
}

static void fatalError(char msg[]){
  fprintf(stderr,"%s", msg);
  exit(EXIT_FAILURE);
}


static void print_table(int str[], int n, int ncols){
  for (int j = 0; j < n-1; ++j)
    {
      //printf("%c",);
      printf("%d ", str[j]);
      if((j+1)%ncols==0)
	printf("\n");
    }
}