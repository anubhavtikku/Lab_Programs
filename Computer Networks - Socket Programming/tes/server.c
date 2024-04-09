#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<string.h>
#include<unistd.h>

int main()
{int res,sockfd,newsockfd,len,selen;
struct sockaddr_in seraddr,cliaddr;
sockfd=socket(AF_INET,SOCK_STREAM,0);

seraddr.sin_family=AF_INET;
seraddr.sin_port=htons(10200);
seraddr.sin_addr.s_addr=htonl(INADDR_ANY);

bind(sockfd,(struct sockaddr *)&seraddr,sizeof(seraddr));
listen(sockfd,5);

len=sizeof(cliaddr);
newsockfd=accept(sockfd,(struct sockaddr *)&cliaddr,&len);

char a[250];
char b[]="Welcome";

read(newsockfd,a,sizeof(a));
printf("Message from client");
puts(a);
write(newsockfd,b,strlen(b));
return 0;
}
