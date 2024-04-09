#include <stdio.h>
#include <stdlib.h>

int gcd(int x,int y)
{  int g=x,op=0;
	if(x>y)
		g=y;

	while(g>0)
	{
		if(x%g==0 && y%g==0)
			{   printf(" Opcode %d",op);
				return g;}

        g=g-1;
        op+=1;

	}

  return 1;

}

int main()
{   
	int m,n,g;
	printf("Enter two numbers ");
	scanf("%d",&m);
	scanf("%d",&n);
	g=gcd(m,n);
	printf("GCD is %d",g);
	return 0;
}