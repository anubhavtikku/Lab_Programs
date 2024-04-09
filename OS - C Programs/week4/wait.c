#include<sys/types.h>
#include<sys/wait.h>
#include<stdio.h>
#include<stdlib.h>

void main()
{
	int status;
	pid_t pid;
	pid=fork();

	if(pid==-1)
		printf("\n Error child not created ");

	else if(pid==0)
	{	printf("\n I am the child");
		exit(0);
	}

	else
	{ wait(&status);
	  printf("\n I am the parent ");
	  printf("\n Child returned: %d\n",status);
	}
} 