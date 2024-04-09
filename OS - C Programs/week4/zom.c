#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
#include<unistd.h>

int main()
{
	pid_t pid;
	pid=fork();

	if(pid<0)
	{
		printf("Fork failed ");
	}

	else if(pid==0)
	{	printf("HELLO\n");	
		exit(0);
	}

	else
	{	sleep(10);
		printf("Hello");
		printf("World");
	}
}
