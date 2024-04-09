#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>

void main()
{
   pid_t pid;
   pid=fork();

   if(pid<0)
   {
      printf("Error");
   }

   else if(pid==0)
   {
      printf("Child process : %d ",getpid());
   }

   else
   {
   	 wait(NULL);
   	 printf("\nParent process : %d ",getpid());

   }
}
