#include "game.h"

#define QT_TYPE(Q)  ((Q) -> type)
#define QT_LEAFPOINT(Q)  ((Q) -> node.leaf.p)
#define QT_LEAFCELL(Q)  ((Q) -> node.leaf.Cel)
#define QT_QUADRANT(Q,I)  ((Q) -> node.quadrants[(I)])

static void insertQDNODE(QD_NODE *Node, Cell *celula, Coordinate point, Coordinate middle, int size);

int search_R_Point(QD_NODE *quadtree, Coordinate point, Coordinate middle, int size){
	if(quadtree==NULL)
		return WATER;
	else if(quadtree->type==QDLEAF){

		if(isEqual(QT_LEAFPOINT(quadtree), point)==TRUE){
			if(QT_LEAFCELL(quadtree)->rivalShoot==0)
				return WATER;
			else
				return QT_LEAFCELL(quadtree)->rivalShoot;
		}
		else
			return WATER;
	}
	else{
		Quadrant quad = getQuadrant(middle,point);
		Coordinate c = getMiddle(middle, quad,size);
		return search_R_Point(QT_QUADRANT(quadtree,quad), point, c,size/2);
	}
}

int search_Point(QD_NODE *quadtree, Coordinate point, Coordinate middle, int size){
	if(quadtree==NULL)
		return MISS;
	else if(quadtree->type==QDLEAF){

		if(isEqual(QT_LEAFPOINT(quadtree), point)==TRUE){
			if(QT_LEAFCELL(quadtree)->rivalShoot==0)
				return HIT;
			else
				return ERROR;
		}
		else
			return MISS;
	}
	else{
		Quadrant quad = getQuadrant(middle,point);
		Coordinate c = getMiddle(middle, quad,size);
		return search_Point(QT_QUADRANT(quadtree,quad), point, c,size/2);
	}
}

int search_MY_Point(QD_NODE *quadtree, Coordinate point, Coordinate middle, int size){
	if(quadtree==NULL)
		return WATER;
	else if(quadtree->type==QDLEAF){

		if(isEqual(QT_LEAFPOINT(quadtree), point)==TRUE){
			if(QT_LEAFCELL(quadtree)->myshoot==0)
				if(QT_LEAFCELL(quadtree)->boat!=NULL)
					return QT_LEAFCELL(quadtree)->boat->type;
				else
					return WATER;
			else
				return QT_LEAFCELL(quadtree)->myshoot;
		}
		else
			return WATER;
	}
	else{
		Quadrant quad = getQuadrant(middle,point);
		Coordinate c = getMiddle(middle, quad,size);
		return search_MY_Point(QT_QUADRANT(quadtree,quad), point, c,size/2);
	}
}

//print quadtree
void printTree(QD_NODE *Node, Coordinate middle,int size, int flag){
	for (int i = 1; i <= ROWS; ++i)
	{
		for (int j = 1; j <= COLS; ++j)
		{
			Coordinate c =make_point(i,j);
			int x;
			if(flag==1)
				x = search_MY_Point(Node,c,middle,size/2);
			else
				x = search_R_Point(Node,c,middle,size/2);
			if(x !=WATER)
				printf("%c ", suportLanguage(x));
			else
				printf("~ " );
		}
		printf("\n");
	}
}

static void insertQDNODE(QD_NODE *Node, Cell *celula, Coordinate point, Coordinate middle, int size){
  // Node not NULL
  Quadrant quad = getQuadrant(middle,point);
  Coordinate c = getMiddle(middle,quad, size);
  QT_QUADRANT(Node,quad) = insertPoint(QT_QUADRANT(Node,quad), celula, point,c,size/2);
}

QD_NODE *changeMyBoard(QD_NODE *Node,Coordinate point, Coordinate middle, int size, int value){
	if(Node == NULL){
		Cell *c =newEmptyCell(NULL,value,0);
		return newLeaf(point,c); 
	}
	else if(QT_TYPE(Node) ==QDLEAF){
		if(isEqual(point,QT_LEAFPOINT(Node))){
			QT_LEAFCELL(Node)->myshoot = value;
		}
		else{
			Cell *c = QT_LEAFCELL(Node);
			Coordinate p = QT_LEAFPOINT(Node);
			QT_TYPE(Node) =QDNODE;
		    for (int i = 0; i < 4; ++i)
				QT_QUADRANT(Node,i) =NULL;

			insertQDNODE(Node,c,p,middle,size);
			Cell *ct = newEmptyCell(NULL,value,0);
			insertQDNODE(Node,ct,point,middle,size);
			
		}
	}
	else{
		Quadrant quad = getQuadrant(middle,point);
		Coordinate c = getMiddle(middle, quad,size);
		QT_QUADRANT(Node,quad) = changeMyBoard(QT_QUADRANT(Node,quad),point,c,size/2, value); 
	}
	return Node;
}


//corrigir esta funçao
QD_NODE *changeRivalBoard(QD_NODE *Node,Coordinate point, Coordinate middle, int size, int value){
	if(Node == NULL){
		Cell *c =newEmptyCell(NULL,0,value);
		return newLeaf(point,c); 
	}
	else if(QT_TYPE(Node) ==QDLEAF){
		if(isEqual(point,QT_LEAFPOINT(Node))){
			QT_LEAFCELL(Node)->rivalShoot = value;
		}
		else{
			Cell *c = QT_LEAFCELL(Node);
			Coordinate p = QT_LEAFPOINT(Node);
			QT_TYPE(Node) =QDNODE;
		    for (int i = 0; i < 4; ++i)
				QT_QUADRANT(Node,i) =NULL;

			insertQDNODE(Node,c,p,middle,size);
			Cell *ct = newEmptyCell(NULL,0,value);
			insertQDNODE(Node,ct,point,middle,size);
		}
	}
	else{
		Quadrant quad = getQuadrant(middle,point);
		Coordinate c = getMiddle(middle, quad,size);
		QT_QUADRANT(Node,quad) = changeRivalBoard(QT_QUADRANT(Node,quad),point,c,size/2, value); 
	}
	return Node;
}

void playGame(QD_NODE *playerOne,QD_NODE *playerTwo,Coordinate middle, int size){
	int Game=TRUE;
	int player=PLAYER_ONE;
	int pOnePontos=0, pTwoPontos=0;
	
	while(Game==TRUE){
		printf("Player %d, Choose coordinates to attack\n",player);
		int x,y;
		scanf("%d%d",&x,&y);
		Coordinate c =make_point(x,y);
		if(PLAYER_ONE ==player){
			int a = search_Point(playerTwo,c,middle,size/2);
			if(a==ERROR){
				printf("Boat already Shoot, Try again\n");
				player=PLAYER_TWO;
			}
			else{
				playerTwo = changeRivalBoard(playerTwo,c,middle,size/2,a); 
				playerOne = changeMyBoard(playerOne,c,middle,size/2,a);
			if(a==HIT)
				pOnePontos++;	
			}
			printQuadTree(playerOne,middle,size);
		}
		else{
			int a = search_Point(playerOne,c,middle,size/2);
			if(a==2){
				printf("Boat already Shoot, Try again\n");
				player=PLAYER_ONE;
			}
			else{
				playerTwo = changeMyBoard(playerTwo,c,middle,size/2,a);
				playerOne = changeRivalBoard(playerOne,c,middle,size/2,a);
			}
			if(a==HIT)
				pTwoPontos++;
			printQuadTree(playerTwo,middle,size);
		}
		if(pOnePontos==NUM_SHIPS_CELL || pTwoPontos ==NUM_SHIPS_CELL){
			printf("Congratss won player %d\n", player);
			break;
		}
		if(PLAYER_ONE ==player){
			player=PLAYER_TWO;
		}
		else{
			player=PLAYER_ONE;
		}

	}
}