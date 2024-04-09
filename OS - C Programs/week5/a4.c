#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int odd=0,even=0,n;
int a[100];

void *eve(void *p)
{ int i;
   for(i=0;i<n;i++)
   if(a[i]%2==0)
   even+=a[i];
 }

void *od(void *p)
{ int i;
   for(i=0;i<n;i++)
   if(a[i]%2==1)
   odd+=a[i];
 }  

int main()
{pthread_t t1,t2;
 int i;

 printf("Enter numbers ");
 scanf("%d",&n);
 
 for(i=0;i<n;i++)
 scanf("%d",&a[i]);

 pthread_create(&t1,0,&eve,0);
 pthread_join(t1,0);
 printf("Sum of even no. is %d",even);
 
 pthread_create(&t2,0,&od,0);
 pthread_join(t2,0);
 printf("\nSum of odd no. is %d",odd);

}
