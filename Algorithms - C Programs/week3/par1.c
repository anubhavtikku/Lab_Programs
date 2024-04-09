#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void intbin(int x,int arr[],int n)
{ int i;

  for(i=0;i<n;i++)
  {arr[i]=x%2;
   x=x/2;
   }
}

int ischeckpart(int a[],int arr[],int n)
{ int s0=0,s1=0,i;
  for(i=0;i<n;i++)
  { if(arr[i]==1)
    s1+=arr[i];
    else
    s0+=arr[i];
   }
   
   if(s1==s0)
   return 1;
   
   return 0;

}

int main()
{ int i,n,k=0;
  int a[100],arr[100];
  
  printf("Enter no. of numbers ");
  scanf("%d",&n);
  
  printf("Enter numbers ");
  for(i=0;i<n;i++)
  scanf("%d",&a[i]);
  
  for(i=0;i<pow(2,n);i++)
  { intbin(i,arr,n);
    k=ischeckpart(a,arr,n);
    if(k==1)
    { break;
    } 
  }
   
   if(k==1)
     printf("Partition possible");
    
    else
     printf("Partition not possible");
}
