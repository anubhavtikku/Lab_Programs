#include<stdio.h>
#include<stdlib.h>

__global__ void add(int *a,int *b,int *c){
	//int idx=blockIdx.x;
	int idx=threadIdx.x;
	c[idx]=a[idx]+b[idx];
}

int main()
{
int a[30],b[30],c[30];
int *d_a,*d_b,*d_c;
int i,n;
printf("Enter n ");
scanf("%d",&n);
printf("Enter values of A ");
for(i=0;i<n;i++)
	scanf("%d",&a[i]);
printf("Enter values of B");
for(i=0;i<n;i++)
	scanf("%d",&b[i]);
int size=n*sizeof(int);
cudaMalloc((void **)&d_a,size);
cudaMalloc((void **)&d_b,size);
cudaMalloc((void **)&d_c,size);

cudaMemcpy(d_a,&a,size,cudaMemcpyHostToDevice);
cudaMemcpy(d_b,&b,size,cudaMemcpyHostToDevice);
//For blocks
//add<<<n,1>>>(d_a,d_b,d_c);
//For threads
add<<<1,n>>>(d_a,d_b,d_c);
cudaMemcpy(&c,d_c,size,cudaMemcpyDeviceToHost);
for(i=0;i<n;i++)
	printf("%d\t",c[i]);
cudaFree(d_a);
cudaFree(d_b);
cudaFree(d_c);
return 0;
}

