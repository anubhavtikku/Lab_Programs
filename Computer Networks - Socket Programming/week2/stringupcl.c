#include<sys/types.h>
#include<sys/socket.h>
#include<stdio.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<stdlib.h>
#include<string.h>

int main()
{ int len,result,sockfd,n=1,k=0,i;
  struct sockaddr_in address;
  char ch[256],buf[256];

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
  
  while(1)
  {for(i=0;i<256;i++)
    {ch[i]='\0';
     buf[i]='\0';
    }
   printf("\nEnter string\n");
   scanf(" %s",ch);
   ch[strlen(ch)]='\0';
   if(strcmp(ch,"QUIT")==0)
   break;
   write(sockfd,ch,strlen(ch));
   
    n=read(sockfd,buf,sizeof(buf));
    
     if(strcmp(buf,"QUIT")==0)
     { k=1;
       break;
      }
     printf("\nMessage from server %s \n",buf);
    
   
   
   if(k==1)
   break;  
  }
  return 0;
 }
