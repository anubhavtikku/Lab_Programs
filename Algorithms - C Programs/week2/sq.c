#include  <stdio.h>
#include <stdlib.h>

int main()
{	int n,m,l;
	printf("Enter number ");
	scanf("%d",&n);
    l=n;
    int f=1;
    while(f<=l)
    { m=f+(l-f)/2;
    	if(m*m==n)
    		break;

    	else if(m*m>n)		
    		l=m-1;

    	else
    		f=m+1;

    }
    printf("Square root is %d",m);

return 0;	
}
	