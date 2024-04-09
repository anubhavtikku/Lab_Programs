#include <stdio.h>

int main()
{ int x,y,z;
  int *a=&x ,*b=&y, *c=&z;
  printf("Enter two numbers ");
  scanf("%d %d",a,b);
  *c = *a + *b;
  printf("Sum is %d \t",*c);
  return 0;
}