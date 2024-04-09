#include <stdio.h>
#include "selection_sort_fun.h"
void main()
{ int array[10];
  int i,n;
  printf("Enter the value of n \n");
  scanf("%d",&n);
  printf("Enter the elements \n");
  for(i=0;i<n;i++)
  	scanf("%d",&array[i]);
  // Selection Sort begins
  exchange(array,n);
  printf("The sorted list is(used selection sort): \n");
  for(i=0;i<n;i++)
  	printf("%d\t",array[i]);
}