#include<stdio.h>
#include<stdlib.h>

int min(int a,int b)
{
	if(a<b)
		return a;
	return b;
}

void floyd(int a[100][100],int n)
{ int i,j,k;

  for(k=0;k<n;k++)
  for(i=0;i<n;i++)
  for(j=0;j<n;j++)
  a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
}

int main()
{int a[100][100];
 int i,j;
 int n,x,y,e,w;

printf("Enter no. of vertices ");
scanf("%d",&n);

for(i=0;i<n;i++)
for(j=0;j<n;j++)
if(i!=j)
a[i][j]=32000;
else
a[i][j]=0;

printf("\nEnter no. of edges ");
scanf("%d",&e);

printf("\nEnter edges with their weights ");
for(i=0;i<e;i++)
{ scanf("%d %d %d",&x,&y,&w);
  a[x-1][y-1]=w;
}

floyd(a,n);
printf("\nThe distance matrix is\n");

for(i=0;i<n;i++)
{for(j=0;j<n;j++)
printf("%d\t",a[i][j]);
printf("\n");
}

}
