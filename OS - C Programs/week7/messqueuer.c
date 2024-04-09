#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<errno.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>

struct msg
{
long int msqid;
int m;
};


int main()
{ int msgid;
  struct msg message;
  msgid=msgget((key_t)1234,0666|IPC_CREAT);
  
  if(msgid==-1)
  {printf("Message failed ");
   exit(1);
  }

 int status;
 long int msg_to_rcv;
 status=msgrcv(msgid,(void *)&message,sizeof(int),msg_to_rcv,0);
 if(status==-1)
 {
  printf("Message receive failed ");
 }

 int x=message.m,y=0,rem;

 while(x>0)
 {rem=x%10;
  y=y*10+rem;
  x=x/10;
 }
 
 if(y==message.m)
 printf("%d is palindrome",message.m);
 else
 printf("%d is not a palindrome",message.m);
}
