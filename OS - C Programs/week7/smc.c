#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include "s.h"

int main()
{ void *shared_memory=(void *)0;
  struct shared_use_st *shared_stuff;
  int shmid;
  srand((unsigned int)getpid());
  shmid=shmget((key_t)1234,sizeof(struct shared_use_st),0666|IPC_CREAT);
  if(shmid==-1)
  {fprintf(stderr,"shmat failed\n");
   exit(EXIT_FAILURE);
  }
  shared_memory=shmat(shmid,(void *)0,0);

 if(shared_memory==(void *)-1)
 {fprintf(stderr,"shmat failed\n");
  exit(EXIT_FAILURE);
 }

 printf("Memory attached at %lX\n",(long int)shared_memory);
 shared_stuff=(struct shared_use_st *)shared_memory;
 
printf("You wrote %s",shared_stuff->some_text);

if(shmdt(shared_memory)==-1)
{ fprintf(stderr,"shmdt failed\n");
  exit(EXIT_FAILURE);
}

if(shmctl(shmid,IPC_RMID,0)==-1)
{fprintf(stderr,"shmctl(IPC_RMD) failed\n");
 exit(EXIT_FAILURE);
}
exit(EXIT_SUCCESS);
}
