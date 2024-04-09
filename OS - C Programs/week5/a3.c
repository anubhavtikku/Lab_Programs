#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int a1,a2;

int isprime(int x)
{int i;
int k=0;

for(i=2;i<x;i++)
  if(x%i==0)
   {k=1;
    break;
   }

if(k==0 && x>1)
return 1;

return 0;
}

void *chi(void* param)
{

int i,k;

for(i=a1;i<=a2;i++)
{ k=isprime(i);
  if(k==1)
    printf("%d\t",i);
 }
 
}

int main()
{printf("Enter lower bound of range ");
 scanf("%d",&a1);
 printf("Enter upper bound of range ");
 scanf("%d",&a2);
 
 pthread_t thread;
 pthread_create(&thread,0,&chi,0);
 pthread_join(thread,0);

}
