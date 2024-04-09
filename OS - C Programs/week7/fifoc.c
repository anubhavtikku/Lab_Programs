#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<limits.h>
#include<sys/types.h>
#include<sys/stat.h>

int main()
{int pipe_fd;
 int res;
 int open_mode=O_RDONLY;
 
 int i,n=4;
 int z;
 int a[PIPE_BUF+1];

 pipe_fd=open("/tmp/my_fifo",open_mode);
 z=read(pipe_fd,a,PIPE_BUF);
 
 printf("The four numbers sent are ");
 for(i=0;i<n;i++)
 printf("%d\t",a[i]);

 (void)close(pipe_fd);
}
