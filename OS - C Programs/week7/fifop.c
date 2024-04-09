#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<string.h>
#include<fcntl.h>
#include<limits.h>
#include<sys/types.h>
#include<sys/stat.h>

#define FIFO_NAME "/tmp/my_fifo"
//int mkfifo(const char *filename,mode_t mode);

int main()
{int pipe_fd;
 int res;
 int open_mode=O_WRONLY;
 int bytes_sent=0;
 
 int i,n=4;
 int a[PIPE_BUF+1];

 printf("Enter four numbers ");
 for(i=0;i<4;i++)
 scanf("%d",&a[i]);

 if(access(FIFO_NAME,F_OK)==-1)
{res=mkfifo(FIFO_NAME,0777);
 if(res!=0)
 {fprintf(stderr,"FIFO not created \n");exit(EXIT_FAILURE);}
} 

 pipe_fd=open(FIFO_NAME,open_mode);
 bytes_sent=write(pipe_fd,a,PIPE_BUF);

 close(pipe_fd);
 exit(EXIT_SUCCESS);
}
