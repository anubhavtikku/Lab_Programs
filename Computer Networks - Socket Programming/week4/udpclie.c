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
struct sockaddr_in address;
sockfd=socket(AF_INET,SOCK_DGRAM,0);
address.sin_family=AF_INET;
address.sin_port=htons(10200);
address.sin_addr.s_addr=htonl(INADDR_ANY);
int a[100][100];
int m,n,i,j;
printf("Enter dimensions of matrix ");
scanf("%d",&m);
scanf("%d",&n);

printf("Enter matrix ");
for(i=0;i<m;i++)
for(j=0;j<n;j++)
scanf("%d",&a[i][j]);


int len=sizeof(address);
sendto(sockfd,&m,sizeof(int),0,(struct sockaddr *)&address,len);
sendto(sockfd,&n,sizeof(int),0,(struct sockaddr *)&address,len);

for(i=0;i<m;i++)
sendto(sockfd,&a[i],sizeof(a[i]),0,(struct sockaddr *)&address,len);


char buf[25];
int y=recvfrom(sockfd,buf,sizeof(buf),0,(struct sockaddr *)&address,&len);
puts(buf);

return 0;
}
