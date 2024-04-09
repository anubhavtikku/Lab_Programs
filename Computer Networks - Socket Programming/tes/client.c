#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<netinet/in.h>
#include<string.h>
#include<unistd.h>

int main()
{int res,sockfd,len;
struct sockaddr_in address;
sockfd=socket(AF_INET,SOCK_STREAM,0);

address.sin_family=AF_INET;
address.sin_port=htons(10200);
address.sin_addr.s_addr=htonl(INADDR_ANY);

char a[]="hello";
char b[250];
len=sizeof(address);
res=connect(sockfd,(struct sockaddr *)&address,len);

if(res==-1)
{perror("Connect failed ");
exit(0);
}


write(sockfd,a,strlen(a));
read(sockfd,b,sizeof(b));

printf("Message by server ");
puts(b);

}
