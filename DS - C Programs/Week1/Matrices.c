#include <stdio.h>
#include "addmatrices.h"
int main()
{ int a[10][10],b[10][10],c[10][10],i,j,m,n;

  printf("Enter dimensions of matrix ");
  scanf("%d%d",&m,&n);

  printf("Enter elements in first matrix ");
  for(i=0;i<m;i++)
  	for(j=0;j<n;j++)
  		scanf("%d",&a[i][j]);

 printf("Enter elements in second matrix ");
  for(i=0;i<m;i++)
  	for(j=0;j<n;j++)
  		scanf("%d",&b[i][j]);

  	addmatrices(a,b,m,n,c);
  
  return 0;

}