#include <stdio.h>
#include "add.h"
void main()
{ int a[10],n,i,sum=0;
	printf("Enter the no. of elements to sum ");
	scanf("%d",&n);
	printf("Enter the elements ");
	for(i=0;i<n;i++)
	 scanf("%d",&a[i]);
	sum=add(a,n); 

	printf("The sum is %d\t",sum);
	
	}