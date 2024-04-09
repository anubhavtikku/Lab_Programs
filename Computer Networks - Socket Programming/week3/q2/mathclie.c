#include<sys/types.h>
#include<sys/socket.h>
#include<stdio.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

int main()
{ int len,result,sockfd,n=1;
  int a,b,s,i,d;
  char c;
  struct sockaddr_in address;

  sockfd=socket(AF_INET,SOCK_STREAM,0);
  
  address.sin_family=AF_INET;
  address.sin_addr.s_addr=htonl(INADDR_ANY);
  address.sin_port=htons(10200);
  len=sizeof(address);
  result=connect(sockfd,(struct sockaddr *)&address,len);
  if(result==-1)
  { perror("\nCLIENT ERROR");
    exit(1);
   }
 
  printf("Enter two numbers ");
  scanf("%d",&a);
  scanf("%d",&b);
  
  printf("Enter operand ");
  scanf(" %c",&c);

  write(sockfd,&a,sizeof(a));
  write(sockfd,&b,sizeof(b));
  write(sockfd,&c,sizeof(c));
  
   read(sockfd,&d,sizeof(d));
   printf("\nMessage from Server \n");
   printf("Result is %d",d);
 
 }
