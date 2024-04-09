#include <stdio.h>
#include "listbig.h"
int main()
{ int a[10],n,i,big;
     printf("Enter no. of elements in array ");
     scanf("%d",&n);
     printf("Enter elements ");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);

     big = listbig(a,n);
      printf("Largest element is %d \t",big);

     return 0;
 }