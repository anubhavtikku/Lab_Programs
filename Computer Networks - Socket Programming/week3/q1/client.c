#include<sys/types.h>
#include<sys/socket.h>
#include<stdio.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

int main()
{ int len,result,sockfd;
  int a[100],i,n;
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
  printf("Enter no. of numbers ");
  scanf("%d",&n);
  printf("Enter numbers ");
  for(i=0;i<n;i++)
  scanf("%d",&a[i]);
  write(sockfd,&n,sizeof(int));
  write(sockfd,a,sizeof(a));
  
   read(sockfd,a,sizeof(a));
   printf("\nMessage from Server \n");
   for(i=0;i<n;i++)
   printf("%d\t",a[i]);
   printf("\nProcess id is %d ",a[n]);
 
 }
