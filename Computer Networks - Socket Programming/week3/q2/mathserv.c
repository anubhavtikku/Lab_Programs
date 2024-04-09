#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<unistd.h>
#define PORTNO 10200

int main()
{ int sockfd,newsockfd,portno,clilen,n=1,temp;
  int a,b,d=0,i,j;
  char c;
  struct sockaddr_in seraddr,cliaddr;

  sockfd=socket(AF_INET,SOCK_STREAM,0);
  seraddr.sin_family=AF_INET;
  seraddr.sin_addr.s_addr=htonl(INADDR_ANY);
  seraddr.sin_port=htons(PORTNO);
  bind(sockfd,(struct sockaddr *)&seraddr,sizeof(seraddr));
  listen(sockfd,5);
  while(1)
  {clilen=sizeof(cliaddr);
   newsockfd=accept(sockfd,(struct sockaddr *)&cliaddr,&clilen);
   
 if(fork()==0)
 { read(newsockfd,&a,sizeof(a));
   read(newsockfd,&b,sizeof(b));
   read(newsockfd,&c,sizeof(c));
  printf("\nMessage from Client \n");
  
  if(c=='+')
  d=a+b;
  else if(c=='-')
  d=a-b;
  else if(c=='*')
  d=a*b;
  else if(c=='/')
  d=a/b;
 
  write(newsockfd,&d,sizeof(d));
  close(newsockfd);
  exit(0);
 }
  
  else
  close(newsockfd);
  }

}
