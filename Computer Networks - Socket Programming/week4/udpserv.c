#include<stdio.h>
#include<fcntl.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>

int main()
{int sockfd;
struct sockaddr_in servaddr,cliaddr;
sockfd=socket(AF_INET,SOCK_DGRAM,0);

servaddr.sin_family=AF_INET;
servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
servaddr.sin_port=htons(10200);

int result=bind(sockfd,(struct sockaddr*)&servaddr,sizeof(servaddr));

int len=sizeof(cliaddr);
int a[100][100];
int m,n,i,j;
recvfrom(sockfd,&m,sizeof(int),0,(struct sockaddr *)&cliaddr,&len);
recvfrom(sockfd,&n,sizeof(int),0,(struct sockaddr *)&cliaddr,&len);

for(i=0;i<m;i++)
recvfrom(sockfd,&a[i],sizeof(a[i]),0,(struct sockaddr *)&cliaddr,&len);

for(i=0;i<m;i++)
{for(j=0;j<n;j++)
printf("%d \t",a[i][j]);
printf("\n");
}

char buf[]="Message received";

int y=sendto(sockfd,buf,sizeof(buf),0,(struct sockaddr*)&cliaddr,len);
return 0;
}
