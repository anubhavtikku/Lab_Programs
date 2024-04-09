#include <stdio.h>
#include <stdlib.h>

int main()
{	int m,n,g=1,i=2,t,op=0;
	printf("Enter two numbers ");
	scanf("%d",&m);
	scanf("%d",&n);
	t=m;
	if(t>n)
		t=n;
	
	while(m!=1 && n!=1 && i<=t)
	{   
		while(m%i==0 && n%i==0)
		{
              g=g*i;
              m=m/i;
              n=n/i;
		}

		i=i+1;
		op+=1;
	}


	printf("GCD is %d op %d",g,op);

	return 0;
}