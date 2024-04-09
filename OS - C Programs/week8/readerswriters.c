#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<semaphore.h>
#include<pthread.h>

sem_t mutex,wrt;
int readcount=0;

void *writer()
{ do
   {sem_wait(&wrt);
    printf("Writing is performed \n");
    sem_post(&wrt);
    sleep(3);
    }while(1);

} 

void *reader()
{ do
   {sem_wait(&mutex);
    readcount++;
    if(readcount==1)
    sem_wait(&wrt);
    sem_post(&mutex);
    printf("Reading is performed \n");
    sem_wait(&mutex);
    readcount--;
    if(readcount==0)
    sem_post(&wrt);
    sem_post(&mutex);
    sleep(3);
   }while(1);

} 

int main()
{
 pthread_t tid1,tid2;
 sem_init(&mutex,0,1);
 sem_init(&wrt,0,1);
 pthread_create(&tid1,NULL,reader,NULL);
 pthread_create(&tid1,NULL,writer,NULL);
 pthread_join(tid1,NULL);
 pthread_join(tid2,NULL);
}
