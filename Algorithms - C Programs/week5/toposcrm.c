#include<stdio.h>
#include<stdlib.h>

int s(int a[10][10],int i,int n)
{ int j,sum=0;
  for(j=0;j<n;j++)
    if(i!=j)
    sum+=a[i][j];
 return sum;  
}

void ze(int a[10][10],int i,int n,int v[10])
{ v[i]=1;
  int l,j; 
  printf("%d\t",i+1);
  for(l=0;l<n;l++)
  for(j=0;j<n;j++)
  if(l==i || j==i)
   a[l][j]=0;
}


void rm(int a[10][10],int n,int v[10])
{ int i,j,k;
  for(i=0;i<n;i++)
  for(j=0;j<n;j++)
  { if(v[i]==0 && s(a,i,n)==0)
    ze(a,i,n,v);
  }
}

int main()
{ int a[10][10];
  int n;
  printf("Enter no. of vertices ");
  scanf("%d",&n);

  int i,j;
  printf("Enter Adjacency Matrix\n");
  for(i=0;i<n;i++)
  for(j=0;j<n;j++)
  scanf("%d",&a[i][j]);
  
  int v[10];
  for(i=0;i<n;i++)
  v[i]=0;
  
  rm(a,n,v);
}

