#include <stdio.h>

int facts;
int factorial(int n)
{
	int val;
	if ( n > 1)
	{
		val = n* factorial(n-1);
		return val;
	}
	else
	{
		return 1;
	}
}
int main()
{
	printf("factorial program\n");
	facts = factorial(5);
	printf("fact 5 = %d \n", facts );
}