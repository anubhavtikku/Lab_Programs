#include<stdio.h>
#include<stdlib.h>

void warshall(int a[100][100],int n)
{int i,j,k;
	for(k=0;k<n;k++)
	for(i=0;i<n;i++)
	for(j=0;j<n;j++)
	a[i][j]=a[i][j] | (a[i][k] & a[k][j]);

}

int main()
{ int a[100][100]={0};
  int n,e,i,j;
  int c,b;
  printf("Enter no. of vertices ");
  scanf("%d",&n);
  printf("\nEnter no. of edges ");
  scanf("%d",&e);
  printf("\nEnter edges ");
  for(i=0;i<e;i++)
  {
  	scanf("%d %d",&c,&b);
  	a[c-1][b-1]=1;
  }

  warshall(a,n);

 printf("\nThe matrix is\n");
 for(i=0;i<n;i++){
 	for(j=0;j<n;j++)
    printf("%d\t",a[i][j]);
 	printf("\n");
 }

}