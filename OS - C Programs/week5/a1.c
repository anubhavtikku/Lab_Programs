#include<stdio.h>
#include<pthread.h>
#include<stdlib.h>

int a[100];

void* child_thread(void* x)
{ int n=(int)x;
  int i;
  a[0]=0;
  a[1]=1;
  for(i=2;i<n;i++)
  a[i]=a[i-1]+a[i-2];

}

int main()
{ int i,n;
  pthread_t thread;
  printf("Enter no. of fib numbers to be printed ");
  scanf("%d",&n);
 
  pthread_create(&thread,0,&child_thread,(void*)n);
  pthread_join(thread,0);
  for(i=0;i<n;i++)
  printf("%d \t",a[i]);

}
