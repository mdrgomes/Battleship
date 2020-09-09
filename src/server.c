#include "server.h"


static void copy_array(char dest[],char *source);
//static void copy_point(char dest[],Coordinate c);

static void copy_array(char dest[],char *source) {
  for (int i = 0; i < MAX; ++i){ 
    dest[i] = source[i];
  }
}
/*
static void copy_point(char dest[],Coordinate c){
  dest[1]=c.row+48;
  dest[2]=c.column+48;
}
int handlerBuffer(char buffe[MAX]){
	for (int n = 0; n < MAX; ++n)
	{
		if(buffe[n]=='0'){ //attack received
			char a=buffe[n+1];
			char b=buffe[n+2];
			int x = a-48;
			int y = b-48;
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

char *handlerinput(int handler){
  char s[MAX];
  char str[6];
  sprintf( s, "%d",handler );
  char *new=NULL;
  if(s[0] == '1'){//change may board and send Ack
    str[0]=s[0];
    if(s[1]=='1'){
      str[1]=s[1];
      //Node = changeMyBoard(Node,c,middle,size/2,HIT);
      //enviar hit
    }
    else if(s[1]=='2'){
      //Node = changeMyBoard(Node,c,middle,size/2,MISS)
      str[1]=s[1];
      //enviar miss
    }
    else if(s[1]=='3'){
      str[1]=s[1];          //enviar error
    }
  }
  else if (s[0] == '2')//change my board and send Shoot
  {
    str[0]=s[0];
    if(s[1]=='1'){
      //changeRivalBoard(playerTwo,c,middle,size/2,a);
      Coordinate c =createCoordAtack();
      char ss[3];
      if(c.row<10){
        sprintf( ss, "%d",c.row );
        ss[1]=ss[0];
        ss[0]="0";
      }
      else
        sprintf( ss, "%d",c.row );
      strcat(str,ss);
      if(c.row<10){
        sprintf( ss, "%d",c.column );
        ss[1]=ss[0];
        ss[0]="0";
      }
      else
        sprintf( ss, "%d",c.column );
      strcat(str,ss);
    }
    else if(s[1]=='2'){
      //changeRivalBoard(playerTwo,c,middle,size/2,a);
      Coordinate c =createCoordAtack();
      char ss[3];
      if(c.row<10){
        sprintf( ss, "%d",c.row );
        ss[1]=ss[0];
        ss[0]="0";
      }
      else
        sprintf( ss, "%d",c.row );
      strcat(str,ss);
      if(c.row<10){
        sprintf( ss, "%d",c.column );
        ss[1]=ss[0];
        ss[0]="0";
      }
      else
        sprintf( ss, "%d",c.column );
      strcat(str,ss);
      
    }
    else if(s[1]=='3'){
      Coordinate c =createCoordAtack();
      new = c.row +48;
      new++;
      new = c.column +48;
    }
  }
  else if (handler == 3)
  {
    new='3';
    //the other player won
  }
  new =head;
  return new;
}

Coordinate createCoordAtack(){
	Coordinate atack;
	printf("Choose Coordinates to atack\n");
	int x, y;
	scanf("%d%d",&x,&y);
	atack = make_point(x,y);
	return atack;
}
*/
// Function designed for chat between client and server. 
void func(int sockfd) 
{ 
  char buff[MAX];
  int n; 
  // infinite loop for chat 
  for (;;) { 
      bzero(buff, MAX); 

      // read the message from client and copy it in buffer 
      read(sockfd, buff, sizeof(buff)); 
      // print buffer which contains the client contents 

       //int handler = handlerBuffer(buff);
      //se ataque realizado a mim, tratar coordenadas minhas cordenadas e enviar ack
      //se recebido ack tratar coordenadas do adversario e esperar por ataque, 
      //se ack = error fazer novo ataque

      printf("From client: %s\t To client : ", buff); 
      bzero(buff, MAX); 
      n = 0; 
      // copy server message in the buffer 
      while ((buff[n++] = getchar()) != '\n') 
          ; 
      // char *str = NULL;
      //str = handlerinput(handler);
      //copy_array(buff,str);
      // copy server message in the buffer 

      // and send that buffer to client 
      write(sockfd, buff, sizeof(buff)); 

      // if msg contains "Exit" then server exit and chat ended. 
      if (strncmp("exit", buff, 4) == 0) { 
          printf("Server Exit...\n"); 
          break; 
      }
  } 
} 
 

void sendSizeToClient(int sockfd, int size){
  char buff[MAX];
  bzero(buff, MAX);
  sprintf(buff,"%d",size);

  write(sockfd, buff, sizeof(buff));
  printf("to client %s\n",buff );
}

void sendNameToClient(int sockfd, char *name){
  char buff[MAX];
  bzero(buff, MAX);
  copy_array(buff,name);

  write(sockfd, buff, sizeof(buff));
  //printf("to client %s\n",buff );
}
// Driver function 
int inicializeServer(int size) 
{ 
    int sockfd, connfd;//, len; 
    struct sockaddr_in servaddr, cli; 
    socklen_t peer_addr_size;
    // socket create and verification 
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
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY); 
    servaddr.sin_port = htons(PORT); 
  
    // Binding newly created socket to given IP and verification 
    if ((bind(sockfd, (SA*)&servaddr, sizeof(servaddr))) != 0) { 
        printf("socket bind failed...\n"); 
        exit(0); 
    } 
    else
        printf("Socket successfully binded..\n"); 
  
    // Now server is ready to listen and verification 
    if ((listen(sockfd, 5)) != 0) { 
        printf("Listen failed...\n"); 
        exit(0); 
    } 
    else
        printf("Server listening..\n"); 
    //len = sizeof(cli); 
    peer_addr_size = sizeof(struct sockaddr_in);
    // Accept the data packet from client and verification 
    connfd = accept(sockfd, (SA*)&cli, &peer_addr_size); 
    if (connfd < 0) { 
        printf("server acccept failed...\n"); 
        exit(0); 
    } 
    else
        printf("server acccept the client...\n"); 
    
    //sendSizeToClient(con 32)
    // Function for chatting between client and server 
    //func(connfd); 
  
    // After chatting close the socket 
    //close(sockfd); 
    return connfd;
} 
void closeSocket(int sockfd){
  close(sockfd);
}

