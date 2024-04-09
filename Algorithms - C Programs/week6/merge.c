#include<stdio.h>
#include<stdlib.h>

int op=0;
void merge(int a[],int l,int m,int r)
{int i=0,j=0,k=0;
 int b[20],c[20];

 int n1=m-l+1;
 int n2=r-m;

 for(i=0;i<n1;i++)
  b[i]=a[l+i];

 for(j=0;j<n2;j++)
 c[j]=a[m+j+1];

 i=0;
 j=0;
 k=l;

 while(i<n1 && j<n2)
 {if(b[i]<c[j])
   {a[k++]=b[i++];op++;}
    
  else
   {a[k++]=c[j++];op++;}
 }

 while(i<n1)
 {a[k++]=b[i++];op++;}


 while(j<n2)
  {a[k++]=c[j++];op++;}
  
}

void mergesort(int a[],int l,int r)
{
   if(l<r)
   { int m=l+(r-l)/2;op++;
     mergesort(a,l,m);
     mergesort(a,m+1,r);
     merge(a,l,m,r);
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
  
  mergesort(a,0,n-1);

  
    for(i=0;i<n;i++)
    printf("%d\t",a[i]);
   printf("\nOpcode is %d",op);
}
