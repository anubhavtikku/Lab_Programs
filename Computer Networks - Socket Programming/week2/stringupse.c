#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include<arpa/inet.h>
#include <ctype.h>
#define PORTNO 10200

int main()
{ int sockfd,newsockfd,portno,clilen,n=1;
  struct sockaddr_in seraddr,cliaddr;
  char servertime[250],pid[10]; 
  int i,value;
  sockfd=socket(AF_INET,SOCK_STREAM,0);
  seraddr.sin_family=AF_INET;
  seraddr.sin_addr.s_addr=htonl(INADDR_ANY);
  seraddr.sin_port=htons(PORTNO);
  bind(sockfd,(struct sockaddr *)&seraddr,sizeof(seraddr));
  

  listen(sockfd,5);

    char buf[256];
    printf("server waiting");
    clilen=sizeof(cliaddr);
    newsockfd=accept(sockfd,(struct sockaddr *)&cliaddr,&clilen);
    while(1)
   {for(i=0;i<256;i++)
     buf[i]='\0'; 
    n=read(newsockfd,buf,sizeof(buf));
    if(strcmp(buf,"QUIT")==0)
    break;
    printf("\nMessage from client %s \n",buf);

    printf("%s",/*inet_ntoa(*/seraddr.sin_addr);//);//seraddr.sin_addr.s_addr);
    printf("\n %d \n",ntohs(cliaddr.sin_port));
    for(i=0;buf[i]!='\0';i++)
    buf[i]=toupper(buf[i]);
    n=write(newsockfd,buf,sizeof(buf));
    }
    return 0;
 }

