#include  <stdio.h>
#include <stdlib.h>

int fib(int n)
{
	if(n==0)
		return 0;

	if(n==1)
		return 1;

	return (fib(n-1) + fib(n-2) );
}

int main()
{	int n,r;
	printf("Enter number ");
	scanf("%d",&n);
    r=fib(n);
    printf("The no. is %d",r);
    return 0;
}