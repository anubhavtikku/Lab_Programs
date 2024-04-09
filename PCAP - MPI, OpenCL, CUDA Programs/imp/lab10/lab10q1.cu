#include "cuda_runtime.h"
#include "device_launch_parameters.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define N  9

__device__ int getGlobalIdx_1D_1D(){
	return blockIdx.x *blockDim.x + threadIdx.x;
}

__global__ void find( char* A,  char* B, int* C, int len){
	int id=getGlobalIdx_1D_1D();
	int flag=0;
	for(int i=0;i<len;i++){
		if(A[id+i]!=B[i]){
			flag=1;
		}
	}
	if(flag==0){
		C[id]=1;
	}else{
		C[id]=0;
	}
}


int main(){
	char A[1000];
	char B[1000];
	int C[1000]={0};
	char ca;
	gets(A);
	scanf("%c",&ca);
	gets(B);
	int len1 = strlen(A);
	int len2 = strlen(B);

	char (*pA), (*pB);
	int (*pC);

	cudaMalloc((void**)&pA, (len1)*sizeof(char));
	cudaMalloc((void**)&pB, (len2)*sizeof(char));
	cudaMalloc((void**)&pC, (len1-len2+1)*sizeof(int));

	cudaMemcpy(pA, A, (len1)*sizeof(char), cudaMemcpyHostToDevice);
	cudaMemcpy(pB, B, (len2)*sizeof(char), cudaMemcpyHostToDevice);
	//cudaMemcpy(pC, C, (len1-len2+1)*sizeof(int), cudaMemcpyHostToDevice);

	int numBlocks = 1;
	int threadsPerBlock = len1-len2+1;
	find<<<numBlocks,threadsPerBlock>>>(pA,pB,pC,len2);

	cudaMemcpy(C, pC, (len1-len2+1)*sizeof(int), cudaMemcpyDeviceToHost);

	int i; printf("C = \n");
	for(i=0;i<len1-len2+1;i++){
	    printf("%d ", C[i]);
	}
	printf("\n%d\n",len2);


	cudaFree(pA);
	cudaFree(pB);
	cudaFree(pC);

	printf("\n");

	return 0;

}
