#include <stdio.h>
#include "add.h"
int main()
{ int x,y,z;
  int *a=&x ,*b=&y, *c=&z;

	printf("Enter two numbers ");
	scanf("%d %d",a,b);
	c = add(a,b);
	printf("Sum is %d \t",*c) ;
    return 0;
}