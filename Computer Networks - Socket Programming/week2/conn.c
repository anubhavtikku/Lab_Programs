#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <time.h>
#define PORTNO 10200

int main()
{ int sockfd,newsockfd,portno,clilen,n=1;
  struct sockaddr_in seraddr,cliaddr;
  char servertime[250],pid[10]; 
  int i,value;
  sockfd=socket(AF_INET,SOCK_STREAM,0);
  seraddr.sin_family=AF_INET;
  //seraddr.sin_addr.s_addr=inet_addr("172.16.58.152");
  seraddr.sin_addr.s_addr=htonl(INADDR_ANY); 
  seraddr.sin_port=htons(PORTNO);
  bind(sockfd,(struct sockaddr *)&seraddr,sizeof(seraddr));
  time_t t;
  t=time(NULL);
  strcpy(servertime,ctime(&t));
  sprintf(pid,"%i",getpid());
  strcat(servertime,pid);

  listen(sockfd,5);
  while(1)
  { char buf[256]={'\0'};
    printf("server waiting");
    clilen=sizeof(cliaddr);
    newsockfd=accept(sockfd,(struct sockaddr *)&cliaddr,&clilen);
    n=read(newsockfd,buf,sizeof(buf));
    printf("\nMessage from client %s \n",buf);
    n=write(newsockfd,servertime,sizeof(servertime));
    }
 
 }

