#include <stdio.h>


__global__ void add (int *A, int *B, int *C,int M,int N) {
    
    //Row Wise
    int idx = threadIdx.x;
    for (int i = 0; i < M; ++i) 
        C[i + M * idx] = A[i + M * idx] + B[i + M * idx];
    
    //Column Wise
    //int idx = threadIdx.x;
    //for (int i = 0; i < N; ++i, idx += M) 
        //C[idx] = A[idx] + B[idx];

    //Element Wise
    //int idx = blockDim.x * blockIdx.x + threadIdx.x;
    //C[idx] = A[idx] + B[idx];


}

int main () {
    int M,N;
    printf("N rows and M columns \n");
    scanf("%d%d",&N,&M);
    int A[M * N], B[M * N], C[M * N];
    int i, j;
    printf("A ELEMENTS \n");
    for (i = 0; i < M * N; ++i) {
        scanf("%d",&A[i]);
    }
    printf("B ELEMENTS \n");
    for (i = 0; i < M * N; ++i) {
        scanf("%d",&B[i]);
    }

    int *d_a, *d_b, *d_c;

    int size = sizeof(int) * M * N;

    cudaMalloc((void**)&d_a, size);
    cudaMalloc((void**)&d_b, size);
    cudaMalloc((void**)&d_c, size);


    cudaMemcpy(d_a, &A, size, cudaMemcpyHostToDevice);
    cudaMemcpy(d_b, &B, size, cudaMemcpyHostToDevice);
    //Row and Column both
    add<<<1, N>>>(d_a, d_b, d_c,M,N);
    //Element Wise
    //add<<<M, N>>>(d_a, d_b, d_c,M,N);
    cudaMemcpy(&C, d_c, size, cudaMemcpyDeviceToHost);

    printf("A:\n");
    for (i = 0; i < N; ++i) {
        for (j = 0; j < M; ++j) {
            printf("%d\t", A[i * M + j]);
        }
        printf("\n");
    }
    printf("\n");

    printf("B:\n");
    for (i = 0; i < N; ++i) {
        for (j = 0; j < M; ++j) {
            printf("%d\t", B[i * M + j]);
        }
        printf("\n");
    }
    printf("\n");

    printf("A + B:\n");
    for (i = 0; i < N; ++i) {
        for (j = 0; j < M; ++j) {
            printf("%d\t", C[i * M + j]);
        }
        printf("\n");
    }
    printf("\n");

    cudaFree(d_a);
    cudaFree(d_b);
    cudaFree(d_c);

    getchar();

    return 0;
}