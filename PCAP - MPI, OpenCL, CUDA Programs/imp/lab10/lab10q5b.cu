#include "cuda_runtime.h"
#include "device_launch_parameters.h"
#include<stdio.h>

__device__ int getGlobalIdx_2D_2D(){
	int blockId = blockIdx.x + blockIdx.y * gridDim.x;
	int threadId = blockId * (blockDim.x * blockDim.y) + (threadIdx.y * blockDim.x) + threadIdx.x;
	return threadId;
}
__global__ void add_matrix(int* a, int* b, int* c,int colsize1,int colsize2)
{
	int id = getGlobalIdx_2D_2D();
	c[id] = 0;
	for(int i=0;i<colsize1;i++)
	{
	c[id] = c[id]+a[((blockIdx.y*blockDim.y)+threadIdx.y)* (colsize1) + i]*b[i*(colsize2) + ((blockIdx.x*blockDim.x)+threadIdx.x)];
	}
}


int main()
{
	int row1, col1, row2, col2;
	printf("enter row1 & col1\n");
	scanf("%d",&row1);
	scanf("%d",&col1);
	printf("enter row2 & col2\n");

	scanf("%d",&row2);
	scanf("%d",&col2);

	int a[1000]={0}, b[1000]={0}, c[1000]={0};

	if(col1!=row2)
		exit(0);

	int *d_a, *d_b, *d_c, *col_size1;

	int size1 = sizeof(int)*row1*col1;
	int size2 = sizeof(int)*row2*col2;
	int size3 = sizeof(int)*1000;
	int size_int = sizeof(int);

	cudaMalloc((void**)&d_a,size1);
	cudaMalloc((void**)&d_b,size2);
	cudaMalloc((void**)&d_c,size3);
	cudaMalloc((void**)&col_size1, size_int);


	for(int i = 0;i<row1*col1;i++)
	{
		a[i] = 1;

	}
	for(int j=0;j<row2*col2;j++)
	{
		b[j] = 1;
	}

	if(col2%2==0){
		col2 = col2+1;
		for(int j=row2*(col2-1);j<row2*col2;j++){
			b[j]=0;
		}
	}
	if(row1%2==0){
		row1 = row1+1;
		for(int j=(row1-1)*(col1);j<row1*col1;j++){
			a[j]=0;
		}
	}
	if(col1%2==0){
			col1 = col1+1;
			for(int j=row1*(col1-1);j<row1*col1;j++){
				a[j]=0;
			}
		}
		if(row2%2==0){
			row2 = row2+1;
			for(int j=(row2-1)*(col2);j<row2*col2;j++){
				b[j]=0;
			}
		}
	cudaMemcpy(d_a, &a, size1, cudaMemcpyHostToDevice);
	cudaMemcpy(d_b, &b, size2, cudaMemcpyHostToDevice);
	cudaMemcpy(col_size1, &col1, size_int, cudaMemcpyHostToDevice);
	int WC = col2;
	int HC = row1;
	dim3 numBlocks(WC%2==0?(WC/2):((WC/2)+1),HC%2==0?(HC/2):((HC/2)+1));
	dim3 threadsPerBlock(2,2);
	add_matrix<<<threadsPerBlock,numBlocks>>>(d_a, d_b, d_c, col1,col2);

	cudaMemcpy(&c, d_c, size3, cudaMemcpyDeviceToHost);
	for(int i=0;i<row1*col2;i++)
	{
		if(i%col2 == 0 && i!=0)
			printf("\n");
		printf("%d ", c[i]);

	}
	printf("\n");
	cudaFree(d_a);
	cudaFree(d_b);
	cudaFree(d_c);
}
