#include "cuda_runtime.h"
#include "device_launch_parameters.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define WA  2
#define HA  9
#define WB  2
#define HB  9
#define WC  2
#define HC  9


__device__ int getGlobalIdx_2D_2D(){
	int blockId = blockIdx.x + blockIdx.y * gridDim.x;
	int threadId = blockId * (blockDim.x * blockDim.y) + (threadIdx.y * blockDim.x) + threadIdx.x;
	return threadId;
}

__global__ void addMat( int* A,  int* B, int* C){
	int id = getGlobalIdx_2D_2D();
	if(id<gridDim.x*gridDim.y*blockDim.x*blockDim.y){
		C[id] = A[id]+B[id];
	}
}

int main(){

int A[WA*HA];
int B[WB*HB];
int C[WC*HC]={0};
for(int i=0;i<WA*HA;i++)
		A[i]=1;
for(int i=0;i<WB*HB;i++)
		B[i]=1;
int (*pA), (*pB), (*pC);

cudaMalloc((void**)&pA, (WA*HA)*sizeof(int));
cudaMalloc((void**)&pB, (WB*HB)*sizeof(int));
cudaMalloc((void**)&pC, (WC*HC)*sizeof(int));

cudaMemcpy(pA, A, (WA*HA)*sizeof(int), cudaMemcpyHostToDevice);
cudaMemcpy(pB, B, (WB*HB)*sizeof(int), cudaMemcpyHostToDevice);
cudaMemcpy(pC, C, (WC*HC)*sizeof(int), cudaMemcpyHostToDevice);

dim3 numBlocks(HC%2==0?(HC/2):(HC/2+1),WC%2==0?(WC/2):(WC/2+1));
dim3 threadsPerBlock(2,2);
addMat<<<numBlocks,threadsPerBlock>>>(pA,pB,pC);

cudaMemcpy(C, pC, (WC*HC)*sizeof(int), cudaMemcpyDeviceToHost);

int i, j=0;; printf("C = \n");
for(i=0;i<WC*HC;i++){
	if(j%WC==0) printf(" \n");
    printf("%d ", C[i]);
	j++;
    }
    printf("\n");


cudaFree(pA);
cudaFree(pB);
cudaFree(pC);

printf("\n");

return 0;
}
