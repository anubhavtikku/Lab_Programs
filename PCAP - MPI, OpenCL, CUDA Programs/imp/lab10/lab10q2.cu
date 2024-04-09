#include "cuda_runtime.h"
#include "device_launch_parameters.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N  9

__device__ int getGlobalIdx_1D_1D(){
	return blockIdx.x *blockDim.x + threadIdx.x;
}

__global__ void find( char* A,  char* B,int len){
	int id=getGlobalIdx_1D_1D();
	B[id] = A[len-id-1];
}


int main(){
	char A[1000]={'\0'};
	char B[1000]={'\0'};
	char ca;
	gets(A);
	scanf("%c",&ca);
	int len1 = strlen(A);

	char (*pA), (*pB);

	cudaMalloc((void**)&pA, (len1)*sizeof(char));
	cudaMalloc((void**)&pB, (len1)*sizeof(char));

	cudaMemcpy(pA, A, (len1)*sizeof(char), cudaMemcpyHostToDevice);
	//cudaMemcpy(pC, C, (len1-len2+1)*sizeof(int), cudaMemcpyHostToDevice);

	int numBlocks = 1;
	int threadsPerBlock = len1;
	find<<<numBlocks,threadsPerBlock>>>(pA,pB,len1);

	cudaMemcpy(B, pB, (len1)*sizeof(char), cudaMemcpyDeviceToHost);

	printf("%s\n",B);


	cudaFree(pA);
	cudaFree(pB);

	printf("\n");

	return 0;

}
