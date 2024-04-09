#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

void *child_thr(void *a)
{
 int *x=(int *)a;
 int i,n=x[0],s=0;
  
 for(i=1;i<=n;i++)
 if(x[i]>0)
   s+=x[i];   

 x[n+1]=s; 
}

int main()
{ pthread_t thread;
  int *a=(int *)malloc(sizeof(int)*100);
  int i,n;
  printf("Enter no to be input ");
  scanf("%d",&a[0]);
  
  n=a[0];
  printf("Enter numbers ");
  for(i=1;i<=n;i++)
  scanf("%d",&a[i]);
  
  pthread_create(&thread,0,&child_thr,(void*)a);
  pthread_join(thread,0);
  
  printf("Sum of non negative no is %d",a[n+1]);
}
