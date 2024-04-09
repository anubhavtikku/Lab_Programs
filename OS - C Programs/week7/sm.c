#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<sys/shm.h>

int main()
{ int sid = shmget(IPC_PRIVATE,sizeof(char *),0666|IPC_CREAT);
char *a= (char *)shmat(sid,(void *)0,0); 
printf("Enter character ");
scanf("%s",a);
int pid=fork();

if(pid==0)
{
  if(*a==90)
  *a=65;
  else if(*a==122)
  *a=97;
  else
  *a=*a+1;
}

else
{wait(NULL);
 printf("Parent process  %c",*a);
}

}
