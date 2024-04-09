#include<sys/types.h>
#include<sys/socket.h>
#include<stdio.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<time.h>

int main()
{ int len,result,sockfd,n=1;
  struct sockaddr_in address;
  char buf[256];

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

  char ch[] = "Message sent";
  write(sockfd,ch,sizeof(ch));

    printf("Date is ");
 
    read(sockfd,buf,sizeof(buf));
    puts(buf);
   
 }
