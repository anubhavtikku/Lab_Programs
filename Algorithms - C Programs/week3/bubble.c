#include<stdio.h>
#include<stdlib.h>

int main()
{ int a[100],n,i,j,temp;
  printf("Enter no. of numbers ");
  scanf("%d",&n);
  printf("Enter numbers ");
  for(i=0;i<n;i++)
  scanf("%d",&a[i]);
  
  for(i=0;i<n-1;i++)
  for(j=0;j<n-i-1;j++)
  { if(a[j]>a[j+1])
     {temp=a[j];
      a[j]=a[j+1];
      a[j+1]=temp;
     }
  }
  printf("\nThe sorted array is ");
  for(i=0;i<n;i++)
  printf("%d \t",a[i]);
  
 }
