#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>
#include<sys/wait.h>

int buf[10];
int f,r;
sem_t mutex,full,empty;

void *produce(void *arg)
{int i;
for(i=0;i<10;i++)
{sleep(1);
sem_wait(&empty);
sem_wait(&mutex);
printf("Produced item is %d\n",i);
buf[(++r)%10]=i;
sem_post(&full);
sem_post(&mutex);
int j;//
sem_getvalue(&full,&j);//
printf("Full %u\n",j);//
}
}

void *consume(void *arg)
{int item,i;
for(i=0;i<10;i++)
{
sleep(1);
sem_wait(&full);
sem_wait(&mutex);
item=buf[(++f)%10];
printf("Consumed item is %d\n",item);
int j;//
sem_getvalue(&full,&j);//
printf("Full %u\n",j);//
sleep(1);
sem_post(&mutex);
sem_post(&empty);
}
}

int main()
{pthread_t tid1,tid2;
sem_init(&mutex,0,1);
sem_init(&full,0,0);
sem_init(&empty,0,10);
pthread_create(&tid1,NULL,produce,NULL);
pthread_create(&tid2,NULL,consume,NULL);
pthread_join(tid1,NULL);
pthread_join(tid2,NULL);
}
