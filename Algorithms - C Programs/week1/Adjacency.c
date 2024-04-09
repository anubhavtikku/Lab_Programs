#include <stdio.h>
#include <stdlib.h>

int main()
{   int a[100][100];
	int n,i,j;
	printf("Enter no. of vertices ");
	scanf("%d",&n);
	
	for(i=0;i<n;i++)
	for(j=0;j<n;j++)
	{	printf("Enter 1 if %d is connected to %d - 0 otherwise ",i+1,j+1);
        scanf("%d",&a[i][j]);                 
    }

    printf("\nAdjacency Matrix\n");

    for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
	 	printf("%d\t",a[i][j]);
        
    printf("\n");
    }

    printf("\nAdjacency List\n");

    for(i=0;i<n;i++)
	{    printf("%d",i+1);
	    for(j=0;j<n;j++)
	 	{ 	if(a[i][j]==1 && i!=j)
	 		printf("->%d",j+1);
          }

    printf("\n");
    }


}