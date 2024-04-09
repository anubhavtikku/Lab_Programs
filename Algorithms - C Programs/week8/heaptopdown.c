#include<stdio.h>
#include<stdlib.h>

int op=0;

void heapify(int a[],int n)
{
	int k,i,j,v;
	int fl;

	for(i=n/2;i>=1;i--)
	{ v=a[i];
	  k=i;
	  op++;
	  fl=0;
	  while(!fl && 2*k<=n)
	  { op++;
	  	j=2*k;
	  	if(j<n && a[j]<a[j+1])
	  		j=j+1;
	  	if(v>=a[j])
	  		fl=1;
	  	else
	  	{
	  		a[k]=a[j];
	  		k=j;
	  	}
	  }
      a[k]=v;
	}
	op++;
}

int main()
{
	int a[100];
	int n,i;
	printf("Enter no. of elements ");
	scanf("%d",&n);
	printf("Enter elements ");
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		heapify(a,i);
	}

	printf("The heap constructed through top down approach is ");
	for(i=1;i<=n;i++)
	{
		printf("%d\t",a[i]);
	}
	printf("\nOpcode is %d",op);

}