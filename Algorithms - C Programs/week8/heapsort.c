#include<stdio.h>
#include<stdlib.h>

void heapify(int a[],int n)
{
	int k,i,j,v;
	int fl;

	for(i=n/2;i>=1;i--)
	{ v=a[i];
	  k=i;
	  fl=0;
	  while(!fl && 2*k<=n)
	  {
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
}

void swap(int a[],int i,int j)
{
	int temp=a[i];
	a[i]=a[j];
	a[j]=temp;
}

int main()
{
	int a[100];
	int n,i,size;
	printf("Enter no. of elements ");
	scanf("%d",&n);
    size=n;
    printf("Enter elements ");
	for(i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}

	heapify(a,n);

     while(n>1)
	{
		swap(a,1,n);
		n=n-1;
		heapify(a,n);
	}
    
	printf("The array after heapsort is ");
	for(i=1;i<=size;i++)
	{
		printf("%d\t",a[i]);
	}

}