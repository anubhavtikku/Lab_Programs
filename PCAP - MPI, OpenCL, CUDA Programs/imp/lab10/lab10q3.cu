#include "cuda_runtime.h"
#include "device_launch_parameters.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N  9

__device__ int getGlobalIdx_1D_1D(){
	return blockIdx.x *blockDim.x + threadIdx.x;
}

__global__ void find( char* A,  int* B){
	int id=getGlobalIdx_1D_1D();
	int n = A[id];
	int i = 1;
	int bin = 0;
	while(n>0){
		int rem = n%2;
		bin = bin + rem*i;
		i=i*10;
		n=n/2;
	}
	B[id] = bin;
}


int main(){
	char A[1000]={'\0'};
	int B[1000]={0};
	char ca;
	gets(A);
	scanf("%c",&ca);
	int len1 = strlen(A);

	char (*pA);
	int (*pB);

	cudaMalloc((void**)&pA, (len1)*sizeof(char));
	cudaMalloc((void**)&pB, (len1)*sizeof(int));

	cudaMemcpy(pA, A, (len1)*sizeof(char), cudaMemcpyHostToDevice);
	//cudaMemcpy(pC, C, (len1-len2+1)*sizeof(int), cudaMemcpyHostToDevice);

	int numBlocks = 1;
	int threadsPerBlock = len1;
	find<<<numBlocks,threadsPerBlock>>>(pA,pB);

	cudaMemcpy(B, pB, (len1)*sizeof(int), cudaMemcpyDeviceToHost);

	int i; printf("C = \n");
	for(i=0;i<len1;i++){
	    printf("%d ", B[i]);
	}
	printf("\n");


	cudaFree(pA);
	cudaFree(pB);

	printf("\n");

	return 0;

}
