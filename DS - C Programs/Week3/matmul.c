#include <stdio.h>

int mul(int a[10][10],int b[10][10],int c[10][10],int m,int y,int n,int i,int j,int k);

int main()
{ int a[10][10],b[10][10],c[10][10],i,j,k,m,n,x,y;

  printf("Enter dimensions of first matrix ");
  scanf("%d%d",&m,&n);

  printf("\nEnter elements of first matrix ");
  for(i=0;i<m;i++)
  	for(j=0;j<n;j++)
  		scanf("%d",&a[i][j]);

printf("\nEnter dimensions of second matrix ");
scanf("%d%d",&x,&y);

if(x!=n)
    { printf("Matrix multiplication not possible ");
      exit(0);
  }
for(i=0;i<m;i++)
  	for(j=0;j<n;j++)
  		c[i][j]=0;

printf("\nEnter elements of second matrix ");
  for(i=0;i<x;i++)
  	for(j=0;j<y;j++)
  		scanf("%d",&b[i][j]);
  	i=0;
  	j=0;
  	k=0;

mul(a,b,c,m,y,n,i,j,k);

printf("\nMult Matrix is \n");
for(i=0;i<m;i++)
   { for(j=0;j<y;j++)
  		printf("\t %d",c[i][j]);
  		printf("\n");
  	}
return 0;
}

int mul(int a[10][10],int b[10][10],int c[10][10],int m,int y,int n,int i,int j,int k)
{  if(k==n)
	{j++;
	 k=0;	
	  }

  if(j==y)
	  {i++;
	  j=0;
	  k=0;}

  if(i==m)
  	{ return 0;}

    c[i][j]+=a[i][k]*b[k][j];
    ++k;

    mul(a,b,c,m,y,n,i,j,k);    
    }