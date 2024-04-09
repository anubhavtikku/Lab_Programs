#include "cuda_runtime.h"
#include "device_launch_parameters.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>



__device__ int getGlobalIdx_1D_1D(){
	return blockIdx.x *blockDim.x + threadIdx.x;
}

__global__ void find(char* A, char* B, int* N, int* C, int len){
	int id=getGlobalIdx_1D_1D();
	int j;
	int li = N[id]+1;
	int ri = N[id+1];
	int flag=1;
	if(ri-li!=len){
		C[id]=0;
	}else{
	for(int j=li;j<ri;j++){
		if(B[j-li]!=A[j]){
			flag=1;
		}
	}
	C[id] = flag;
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
	int count=0;
	for(int i=0; i<strlen(A); i++){
		if(A[i]==' '){
			count = count+1;
		}
	}
	count = count+2;
	int N[count];
	int same[count-1];
	N[0] = -1;
	N[count-1] = strlen(A);
	int j=1;
	for(int i=0; i<strlen(A); i++)
		if(A[i]==' ')
			N[j++] = i;
	char (*pA), (*pB);
	int (*pC),(*pN);

	cudaMalloc((void**)&pA, (len1+1)*sizeof(char));
	cudaMalloc((void**)&pB, (len2+1)*sizeof(char));
	cudaMalloc((void**)&pN, (count)*sizeof(int));
	cudaMalloc((void**)&pC, (count-1)*sizeof(int));

	cudaMemcpy(pA, A, (len1+1)*sizeof(char), cudaMemcpyHostToDevice);
	cudaMemcpy(pB, B, (len2+1)*sizeof(char), cudaMemcpyHostToDevice);
	cudaMemcpy(pN, N, (count)*sizeof(int), cudaMemcpyHostToDevice);
	//cudaMemcpy(pC, C, (len1-len2+1)*sizeof(int), cudaMemcpyHostToDevice);

	int numBlocks = 1;
	int threadsPerBlock = count-1;
	find<<<numBlocks,threadsPerBlock>>>(pA,pB,pN,pC,len2);

	cudaMemcpy(C, pC, (count-1)*sizeof(int), cudaMemcpyDeviceToHost);

	int i; printf("C = \n");
	for(i=0;i<count-1;i++){
	    printf("%d ", C[i]);
	}
	printf("\n%d\n",len2);


	cudaFree(pA);
	cudaFree(pB);
	cudaFree(pC);

	printf("\n");

	return 0;

}
