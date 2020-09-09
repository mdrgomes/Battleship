#include "client.h"


/*static void copy_array(int dest[],int source[]);
static void copy_point(char dest[],Coordinate c);

static void copy_array(int dest[],int source[]) {
  int si=4;
  for (int i = 0; i < si; ++i) 
    dest[i] = source[i];
}

static void copy_point(char dest[],Coordinate c){
  dest[1]=c.row+48;
  dest[2]=c.column+48;
  //itoa(c.row,dest[0],10);
  //itoa(c.column,dest[1],10);
}
int handlerBuffer(char buffe[MAX]){
	for (int n = 0; n < MAX; ++n)
	{
		if(buffe[n]=='0'){ //attack received
			//printf("%c\n", buffe[n]);
			//make_point x e y
			char a=buffe[n+1];
			char b=buffe[n+2];
			int x = a-48;
			int y = b-48;
			//Coordinates c =make_point(x,y);
			//int a = search_Point(playerTwo,c,middle,size/2);
			if(a==HIT){
				//send hit
				//change my board 
				return 11;
			}
			else if(a==ERROR){
				printf("Boat already Shoot, Try again\n");
				//send error
				return 13;
			}
			else{
				return 12;
				//send miss
			}
		}
		else if(buffe[n]=='1'){ //acknolegement form my attack
			if (buffe[n]=='0')//Miss
			{
				return 21;
				//tratar o miss
			}
			else if (buffe[n+1]=='1')//Shoot
			{
				return 22;
				//tratar send shoot
			}
			else{//error
				return 23;
				//printf("error\n");
			}
		}
		else if(buffe[n]=='3'){
			//the other player won
		}
	}
	
	
}


Coordinate createCoordAtack(){
	Coordinate atack;
	printf("Choose Coordinates to atack\n");
	int x, y;
	scanf("%d%d",&x,&y);
	atack = make_point(x,y);
	return atack;
}

void printee(char buf[]){
	for (int i = 0; i < MAX; ++i)
	{
		if(buf[i]=='0');
		printf("%d ", i);
	}
}
*/
void funcCli(int sockfd) 
{ 
	char buff[MAX]; 
	int n; 
	for (;;) { 
		bzero(buff, sizeof(buff)); 
		printf("Enter the string : "); 
		n = 0; 
		while ((buff[n++] = getchar()) != '\n') 
			; 
		write(sockfd, buff, sizeof(buff)); 
		bzero(buff, sizeof(buff)); 
		read(sockfd, buff, sizeof(buff)); 
		//handlerBuffer(buff);
		//printee(buff);
		printf("From Server : %s", buff); 
		if ((strncmp(buff, "exit", 4)) == 0) { 
			printf("Client Exit...\n"); 
			break; 
		} 
	} 
} 


int getSizeFromServer(int sockfd){
	int size;
	char buff[MAX];
	bzero(buff, sizeof(buff)); 
	read(sockfd, buff, sizeof(buff));
	printf("from server %s\n",buff );
	sscanf(buff,"%d",&size);
	return size;
}

char *getRivalName(int sockfd){
	char *name;
	char buff[MAX];
	bzero(buff, sizeof(buff)); 
	read(sockfd, buff, sizeof(buff));
	printf("from server %s\n",buff );
	name=buff;
	return name;
}

int inicializeClient() 
{ 
	int sockfd;//, connfd; 
	struct sockaddr_in servaddr; 

	// socket create and varification 
	sockfd = socket(AF_INET, SOCK_STREAM, 0); 
	if (sockfd == -1) { 
		printf("socket creation failed...\n"); 
		exit(0); 
	} 
	else
		printf("Socket successfully created..\n"); 
	bzero(&servaddr, sizeof(servaddr)); 

	// assign IP, PORT 
	servaddr.sin_family = AF_INET; 
	servaddr.sin_addr.s_addr = inet_addr("127.0.0.1"); 
	servaddr.sin_port = htons(PORT); 

	// connect the client socket to server socket 
	if (connect(sockfd, (SA*)&servaddr, sizeof(servaddr)) != 0) { 
		printf("connection with the server failed...\n"); 
		exit(0); 
	} 
	else
		printf("connected to the server..\n"); 

	//int size = getSizeFromServer(sockfd);
	//printf("size %d\n", size);
	// function for chat 
	//funcCli(sockfd); 

	// close the socket 
	//close(sockfd); 
	return sockfd;
} 

void closeCliSocket(int sockfd){
  close(sockfd);
}
