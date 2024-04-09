#include <stdio.h>
#include <stdlib.h>

void insertSort(int arr[],int n){
	int i,j,k,temp;
	for(i=1;i<n;i++){
		temp=arr[i];
	for(j=0;j<i;j++){
	 if(arr[j]>arr[i]){
		for(k=i;k>j;k--)
			arr[k]=arr[k-1];
		break;
			}
		}
		arr[j]=temp;
	}
}

int main()
{
	int n,a[10];
	printf("Enter number of elements in the list ");
	scanf("%d",&n);
	printf("Enter the unsorted list of integers-\n");
	int i;
	for(i=0;i<n;i++)
	 scanf("%d",&a[i]);

	insertSort(a,n);
	for(i=0;i<n;i++)
		printf("%d ",a[i]);
	return 0;
}