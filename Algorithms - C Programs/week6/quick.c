#include<stdio.h>
#include<stdlib.h>

int op=0;
void swap(int *a,int *b)
{ int t=*a;
  *a=*b;
  *b=t;
}

int partition(int a[],int l,int r)
{ int i=l,j=r,p=a[l];
   
  while(i<j)
{ while(a[i]<=p )
  {i++;op++;}
  op++;
  
  while(a[j]>p )
  {j--;op++;}
  op++;

  swap(&a[i],&a[j]);
 
}

swap(&a[i],&a[j]);
swap(&a[l],&a[j]);
return j;

}

int quicksort(int a[],int l,int r)
{ if(l<r)
  {int p=partition(a,l,r);
  op++;
  quicksort(a,l,p-1);
  quicksort(a,p+1,r);
  }
 }
 
int main()
{
  int a[20];
  int i,n;
  
  printf("Enter no. of numbers ");
  scanf("%d",&n);

  printf("Enter numbers ");
  for(i=0;i<n;i++)
  scanf("%d",&a[i]);
  
  quicksort(a,0,n-1);

  
  for(i=0;i<n;i++)
  printf("%d\t",a[i]);
 printf("\nThe opcode is %d",op);
 }
