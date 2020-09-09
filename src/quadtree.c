#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "quadtree.h"


//=================================================

#define QT_TYPE(Q)  ((Q) -> type)
#define QT_LEAFPOINT(Q)  ((Q) -> node.leaf.p)
#define QT_LEAFCELL(Q)  ((Q) -> node.leaf.Cel)
#define QT_QUADRANT(Q,I)  ((Q) -> node.quadrants[(I)])

static void fatalError(char msg[]);
static void copy_array(int dest[],int source[], int n);

static void fatalError(char msg[]){
  fprintf(stderr,"%s", msg);
  exit(EXIT_FAILURE);
}

static void copy_array(int dest[],int source[], int n) {
  for (int i = 0; i < n; ++i) 
    dest[i] = source[i];
}

//create leaf
QD_NODE *newLeaf(Coordinate cord, Cell *value){
	QD_NODE *new = malloc(sizeof(QD_NODE));
	//Cell *celula = 
	if (new == NULL)
	  fatalError("quadtree: cannot allocate new leaf\n");

	QT_TYPE(new) = QDLEAF;
	QT_LEAFPOINT(new) = cord;
	QT_LEAFCELL(new) = value;

	return new;
}

//get middle point for each quadrant
Coordinate getMiddle(Coordinate pos, Quadrant quad, int size){

	Coordinate new;
	int x=pos.row;
	int y=pos.column;

	switch(quad){
		case NW:
			new =make_point(x - (size/2),y - (size/2));
			//new.row = x - (size/2);
			//new.column = y - (size/2);
			break;
		case NE:
			new =make_point(x - (size/2),y + (size/2));
			//new.row = x - size/2;
			//new.column = y + size/2;
			break;
		case SW:
			new =make_point(x + (size/2),y - (size/2));
			//new.row = x + size/2;
			//new.column = y - size/2;
			break;
		case SE:
			new =make_point(x + (size/2),y + (size/2));
			//new.row = x + size/2;
			//new.column = y + size/2;
			break;
		default:
			new=make_point(0,0);
			fatalError("quadteee: quadrant %d does not exist\n");
			break;
	}
	return new;
}

//search for quadrant //works
Quadrant getQuadrant(Coordinate middle, Coordinate pos){
	if(middle.row>=pos.row && middle.column>pos.column){
		return NW;
	}
	else if(middle.row>=pos.row && middle.column<=pos.column){
		return NE;
	}
	else if(middle.row<=pos.row && middle.column>pos.column){
		return SW;
	}
	else if(middle.row<=pos.row && middle.column<=pos.column){
		return SE;
	}
	return MAX_Q;
}

static void insertQDNODE(QD_NODE *Node, Cell *celula, Coordinate point, Coordinate middle, int size){
  // Node not NULL
  Quadrant quad = getQuadrant(middle,point);
  Coordinate c = getMiddle(middle,quad, size);
  QT_QUADRANT(Node,quad) = insertPoint(QT_QUADRANT(Node,quad), celula, point,c,size/2);
}

//insert point
QD_NODE *insertPoint(QD_NODE *Node, Cell *celula, Coordinate point, Coordinate middle, int size){ 
  //loop corrigir

  if(Node==NULL)
    return newLeaf(point,celula);

  if(QT_TYPE(Node) ==QDLEAF){
    
    if(isEqual(QT_LEAFPOINT(Node), point)==1) {
      printf("Ja existe\n");
      //  APT COMENTARIO    para rever ...
    }  else{
      Cell *new = QT_LEAFCELL(Node); 
      Coordinate pont = QT_LEAFPOINT(Node);
      
      QT_TYPE(Node) =QDNODE;
      for (int i = 0; i < 4; ++i)
	  QT_QUADRANT(Node,i) =NULL;
      insertQDNODE(Node,new,pont,middle,size);
      insertQDNODE(Node,celula,point,middle,size);
    }
  } else
    insertQDNODE(Node,celula,point,middle,size);

  return Node;
}

//search point
Boolean searchPoint(QD_NODE *quadtree, Coordinate point, Coordinate middle, int size){
	if(quadtree==NULL)
		return 0;
	else if(quadtree->type==QDLEAF){
		
		return isEqual(quadtree->node.leaf.p, point);
	}
	else{
		Quadrant quad = getQuadrant(middle,point);
		Coordinate c = getMiddle(middle, quad,size);
		return searchPoint(quadtree->node.quadrants[quad], point, c,size/2);
	}
}

int searchShipPoint(QD_NODE *quadtree, Coordinate point, Coordinate middle, int size){
	if(quadtree==NULL)
		return FALSE;
	else if(quadtree->type==QDLEAF){
		if(isEqual(quadtree->node.leaf.p, point)==TRUE)
			return QT_LEAFCELL(quadtree)->boat->type;
		else
			return FALSE;
	}
	else{
		Quadrant quad = getQuadrant(middle,point);
		Coordinate c = getMiddle(middle, quad,size);
		return searchShipPoint(quadtree->node.quadrants[quad], point, c,size/2);
	}
}
//search cell
int searchCell(QD_NODE *quadtree, Coordinate point, Coordinate middle, int size){
	if(quadtree==NULL)
		return MISS;
	else if(quadtree->type==QDLEAF){
		//printf("aleret\n");
		if(isEqual(point,quadtree->node.leaf.p)==TRUE){
			if(quadtree->node.leaf.Cel->myshoot==0){
				//printf("alt " );
				return HIT;
			}
			else{
				return ERROR;
			}
		}
		else
			return MISS;
	}
	else{
		Quadrant quad = getQuadrant(middle,point);
		Coordinate c = getMiddle(middle, quad,size);
		return searchCell(quadtree->node.quadrants[quad], point, c,size/2);
	}
}

//print quadtree
void printQuadTree(QD_NODE *Node, Coordinate middle,int size){

	for (int i = 1; i <= ROWS; ++i)
		if(i<10)
			printf("0%d ",i );
		else
			printf("%d ",i );
	printf("\n");
	for (int i = 1; i <= ROWS; ++i)
	{

		for (int j = 1; j <= COLS; ++j)
		{
			Coordinate c =make_point(i,j);

			int x = searchShipPoint(Node,c,middle,size/2);
			if(x !=WATER)
				printf("%c  ", suportLanguage(x));
			else
				printf("~  " );
		}
		printf("%d\n",i);
	}
}

//add ship on quadtree
//corrigir função para receber SHIP
QD_NODE *addShipOnQuad(QD_NODE *Node, SHIP *b, Coordinate cord, Coordinate middle,int size){
	
	int x = cord.row;
	int y = cord.column;
	int j=1;
	for (int i = 0; i < MAX_STRING_SIZE; ++i)
	{
		if(b->shape[i]!=0){
			NUM_SHIPS_CELL++;
			Coordinate pos =make_point(x,y);
			Cell *c =newCell(b);
			Node = insertPoint(Node,c, pos,middle,size);
		}
		if(j%5==0){
			x++;
			y=cord.column;
		}

		else
			y++;
		j++;
	}
	return Node;
}

Boolean verifyCoordQuad(QD_NODE *Node, int bitmap[], Coordinate point, Coordinate middle, int size){
	int x = point.row;
	int y = point.column;
	int j=1;
	for (int i = 0; i < MAX_STRING_SIZE; ++i)
	{
		if(bitmap[i]!=0){
			Coordinate pos =make_point(x,y);
			Boolean b =searchPoint(Node,pos,middle,size/2);
			if(b==TRUE)
				return FALSE;
		}
		if(j%5==0){
			x++;
			y=point.column;
		}
		else
			y++;
		j++;
	}
	return TRUE;
}

QD_NODE *RandomPlaceOnQuad(QD_NODE *Node, Coordinate middle, int size){
	Coordinate position;

	for (int i = 0; i < NUM_SHIPS; ++i)
	{
		int c_boat[MAX_STRING_SIZE];
		int i_boat=i;
		while(TRUE){
			position.row =rand() % ROWS;
			position.column = rand() % COLS;
			if(position.row + 5< ROWS && position.row -5 >0 && position.column +5 <COLS && position.column-5>0){
				Boolean b = verifyCoordQuad(Node,boats[i].shape,position,middle,size);
				if(b==TRUE){
					int command = rand() % 3;
					int x=0, y=0, cont=1;
					if(command !=0){//falta o querer rodar ou nao
						for (int i = 0; i < 25; ++i)
						{
							int a =Rotate(x,y,command);
							c_boat[i]=boats[i_boat].shape[a];
							x++;
							if(cont%5==0){
								x=0;
								y++;
								cont=1;
							}
							else
								cont++;
						}
						SHIP *b = newShip(c_boat,boats[i_boat].type,boats[i_boat].nshoot);
						Node = addShipOnQuad(Node,b,position, middle, size/2);
					}
					else{
						SHIP *b = newShip(boats[i_boat].shape,boats[i_boat].type,boats[i_boat].nshoot);
						Node = addShipOnQuad(Node,b,position, middle, size/2);
					}
					break;
				}

			}
		}
		
	}
	return Node;
}


QD_NODE *buildQuadTree(QD_NODE *Node, Coordinate middle, int size, int player){
	menuChoose(player);
	int com;
	scanf("%d",&com);
	if(com==2){
		Node = RandomPlaceOnQuad(Node, middle,size);
	}
	else{
		for (int i = 0; i < NUM_SHIPS; ++i)
		{
			int i_boat=i;
			printQuadTree(Node,middle,size);
			printf("Choose the coordinates. Ex(x y)\n");
			int x_X, y_Y;
			scanf("%d %d", &x_X, &y_Y);
			Coordinate point = make_point(x_X,y_Y);
			Boolean b = verifyCoordQuad(Node,boats[i_boat].shape,point,middle,size);
			if(x_X ==0 || y_Y ==0)
				b=FALSE;
			while(b ==FALSE){
				printf("Wrong coordinates, choose again\n");
				printf("Choose the coordinates. Ex(x y)\n");
				int x_X, y_Y;
				scanf("%d %d", &x_X, &y_Y);
				point = make_point(x_X,y_Y);
				b = verifyCoordQuad(Node,boats[i_boat].shape,point,middle,size);
				if(x_X ==0 || y_Y ==0)
					b=FALSE;
			}
			int c_boat[MAX_STRING_SIZE];
			system("clear");
			copy_array(c_boat,boats[i_boat].shape, MAX_STRING_SIZE);
			int command=1;
			while(command!=0){
				printShip(c_boat,boats[i_boat].type-4);
				printf("Choose the angle of rotation\n1 = 90 degrees\n2 = 180 degrees\n3 = -90 degrees\n0 if you are done\n");
				scanf("%d", &command);
				int x=0, y=0, cont=1;
				if(command==0){
					SHIP *b = newShip(c_boat,boats[i_boat].type,boats[i_boat].nshoot);
					Node = addShipOnQuad(Node,b,point,middle,size/2);
				}
				else{
					for (int i = 0; i < 25; ++i)
					{
						int a =Rotate(x,y,command);
						c_boat[i]=boats[i_boat].shape[a];
						x++;
						if(cont%5==0){
							x=0;
							y++;
							cont=1;
						}
						else
							cont++;
					}
				}
				
				system("clear");
			}
		}
	}
	return Node;
}
