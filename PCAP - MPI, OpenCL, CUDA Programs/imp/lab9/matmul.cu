#include <stdio.h>

__global__ void mul1 (int *A, int *B, int *C, int height, int width) {
    int idx = blockIdx.x;
    int sum=0;
    for(int i=0; i<width; i++){
        sum=0;
        for(int j=0; j<width; j++)
            sum+=A[idx*width+j]*B[j*width+i];
        C[idx*width+i]=sum;
    }
}

__global__ void mul2 (int *A, int *B, int *C, int height, int width) {
    int idx = blockIdx.x;
    int sum=0;
    for(int i=0; i<height; i++){
        sum=0;
        for(int j=0; j<width; j++)
            sum+=A[idx*width+j]*B[j*width+i];
        C[idx*width+i]=sum;
    }
}

__global__ void mul3 (int *A, int *B, int *C, int height, int width) {
    int rid = blockIdx.y;
    int cid = threadIdx.x;
    int sum=0;
    for(int i=0; i<width; i++){
            sum+=A[rid*width+i]*B[i*width+cid];
    }
        C[rid*width+cid]=sum;
}


int main() {

    int N, M;
    printf("\nEnter The Value Of N and M: ");
    scanf("%d %d",&N,&M); //row

    int row=N, col=M;

    int sizeMatrix=N*M;
    // Host copies of the variables
    int A[sizeMatrix], B[sizeMatrix], C[sizeMatrix];

    int i, j;
    for(i=0; i<sizeMatrix; i++)
        scanf("%d",&A[i]);
    for(j=0; j<sizeMatrix; j++)
        scanf("%d",&B[j]);

    // Device copies of the variables
    int *d_a, *d_b, *d_c;

    int size = sizeof(int) * sizeMatrix;

    // Allocate Memories to device copies of the objects
    cudaMalloc((void**)&d_a, size);
    cudaMalloc((void**)&d_b, size);
    cudaMalloc((void**)&d_c, size);

    // Copy inputs to device
    cudaMemcpy(d_a, &A, size, cudaMemcpyHostToDevice);
    cudaMemcpy(d_b, &B, size, cudaMemcpyHostToDevice);

    // Launch kernel onto the device
    mul1<<<row, 1>>>(d_a, d_b, d_c,row,col);

    //mul2<<<row, 1>>>(d_a, d_b, d_c,row,col);

    //dim3 dimBlock = (row,col);
    //mul3<<<1, dimBlock>>>(d_a, d_b, d_c,row,col);

    // Copy the result back to the host
    cudaMemcpy(&C, d_c, size, cudaMemcpyDeviceToHost);

    printf("A:\n");
    for (j = 0; j < sizeMatrix; ++j) {
        printf("%d\t", A[j]);
    }
    printf("\n");

    printf("B:\n");
    for (j = 0; j < sizeMatrix; ++j) {
        printf("%d\t", B[j]);
    }
    printf("\n");

    printf("A * B:\n");
    for (j = 0; j < sizeMatrix; ++j) {
        printf("%d\t", C[j]);
    }
    printf("\n");

    cudaFree(d_a);
    cudaFree(d_b);
    cudaFree(d_c);

    getchar();

    return 0;
}