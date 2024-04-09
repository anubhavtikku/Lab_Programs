#include <stdio.h>
#include "search.h"
int main()
{ int a[10],n,i,j=0;
     printf("Enter no. of elements ");
     scanf("%d",&n);
     printf("Enter elements ");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);
	printf("Enter element to be found ");
	scanf("%d",&i);
    j= search(a,n,i);
    if(j==1)
    	printf("Element found");
    else
    printf("Element not found");
 return 0;}
	