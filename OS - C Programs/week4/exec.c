#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<sys/wait.h>

int main()
{
	pid_t pid;

	pid=fork();

	if(pid<0)
	{
		printf("Error");
	}

	else if(pid==0)
	{
		printf("Child process \n");
		execlp("./wait.out","wait.out",NULL);
	}

	else
	{   wait(NULL);
		printf("Parent process\n");
	}


}
