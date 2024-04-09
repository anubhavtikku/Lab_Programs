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
{ int sockfd,newsockfd,portno,clilen;
  int n,temp;
  int buf[256],i,j;
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
 { read(newsockfd,&n,sizeof(int));
   read(newsockfd,buf,sizeof(buf));
  printf("\nMessage from Client \n");
   
  for(i=0;i<n;i++)
  for(j=0;j<n-i-1;j++)
  { if(buf[j]>buf[j+1])
    {temp=buf[j];
     buf[j]=buf[j+1];
     buf[j+1]=temp;}
  }
  buf[n]=getpid();
  write(newsockfd,buf,sizeof(buf));
  close(newsockfd);
  //exit(0);
 }
  
  else
  close(newsockfd);
  }

}
