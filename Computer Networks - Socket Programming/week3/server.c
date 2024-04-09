#include<sys/types.h>
#include<sys/socket.h>
#include<stdio.h>
#include<stdlib.h>
#include<netinet/in.h>
#include<time.h>
#include<string.h>
#include<sys/ioctl.h>
#include<unistd.h>
#define PORTNO 10200

int main()
{
int server_sockfd,client_sockfd;
int server_len,client_len;
struct sockaddr_in server_address;
struct sockaddr_in client_address;
int result;
fd_set readfds,testfds;

server_sockfd=socket(AF_INET,SOCK_STREAM,0);
server_address.sin_family=AF_INET;
server_address.sin_addr.s_addr=htonl(INADDR_ANY);
server_address.sin_port=htons(10200);
server_len=sizeof(server_address);
bind(server_sockfd,(struct sockaddr *)&server_address,server_len);
listen(server_sockfd,5);
FD_ZERO(&readfds);
FD_SET(server_sockfd,&readfds);

while(1)
{ int fd,nread;
  testfds=readfds;
  printf("Server waiting\n");
  result=select(FD_SETSIZE,&testfds,0,0,0);
  if(result < 1)
  { perror("server error");
    exit(1);
   }
  
  for(fd=0;fd<FD_SETSIZE;fd++){
   if(FD_ISSET(fd,&testfds)){
   if(fd==server_sockfd){
   client_len=sizeof(client_address);
   client_sockfd=accept(server_sockfd,(struct sockaddr *)&client_address,&client_len);
   FD_SET(client_sockfd,&readfds);
   printf("adding client on fd %d\n",client_sockfd);}
   else
 { ioctl(fd,FIONREAD,&nread);
   if(nread==0){
     close(fd);
     FD_CLR(fd,&readfds);
     printf("removing client on fd %d\n",fd);
   }
  else
  { char str[256];
    read(fd,str,sizeof(str));
    time_t t;
    t=time(NULL);
    strcpy(str,ctime(&t));
    sleep(5);
    printf("server client in fd %d \n",fd);
    printf("%s",str);
    write(fd,str,sizeof(str));
  }
}
}}}}
 

