//For a given set of numbers, find the subsets whose sum is equal to a given number
#include<stdio.h>
#include<stdlib.h>
#include<math.h>

int bin(int a[],int n,int s,int i)
{int b[100]={0};
 
 int x=i,rem,k=0;
 
 while(x>0)
 { rem=x%2;
   b[k++]=rem;
   x=x/2;
 }

int j;
int s0=0,s1=0;

for(j=0;j<n;j++)
{
 if(b[j]==0)
 s0+=a[j];
 
 else
 s1+=a[j];
}
/*
if(s0==s)
{printf("Partition possible for ");
 for(j=0;j<n;j++)
 if(b[j]==0)
 printf("%d \t",a[j]);
 printf("\n");
}
*/
if(s1==s)
{printf("Partition possible for ");
 for(j=0;j<n;j++)
 if(b[j]==1)
 printf("%d \t",a[j]);
 printf("\n");
}

return 0;
}

int main()
{int a[100];
int n,i,k=0,s;

printf("Enter no. of numbers ");
scanf("%d",&n);

printf("Enter numbers ");
for(i=0;i<n;i++)
scanf("%d",&a[i]);

printf("Enter sum to be equalled to ");
scanf("%d",&s);

for(i=0;i<pow(2,n);i++)
{
   k=bin(a,n,s,i);
   
}
}
