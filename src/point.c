#include "point.h"

//create point 
Coordinate make_point(int x,int y){
	Coordinate new;
	new.row=x;
	new.column=y;
	return new;
}

//check if number is power of two
Boolean isPowerOfTwo(int x) 
{ 
	if (x == 0 && x==1)
      return FALSE;
   while( x != 2)
   {
		if(x % 2 != 0)
        	return FALSE;
        
        x /= 2;
   }
   return TRUE;
} 


//print coordinates
void printCord(Coordinate cord){
	int x = cord.row;
	int y = cord.column;
	printf("(%d,%d)",x,y );

}

//check if coordinates are equal
int isEqual(Coordinate pont, Coordinate point){
	if(pont.row == point.row && pont.column==point.column)
		return 1;
	else 
		return 0;
}
