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
  
  printf("Enter number ");
  scanf("%d",&message.m);

  if(msgid==-1)
  {printf("Message failed ");
   exit(1);
  }

 int status;
 status=msgsnd(msgid,(void *)&message,sizeof(int),0);
 if(status==-1)
 {
  printf("Message send failed ");
 }

}
