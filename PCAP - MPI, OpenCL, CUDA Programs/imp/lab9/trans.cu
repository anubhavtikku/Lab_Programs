#include<stdio.h>
__global__ void transpose(int *a,int *b,int m){
	int rows = threadIdx.y; 
	int cols = threadIdx.x;

	//b[cols*(*m)+rows]=a[cols*(*m)+rows];
	b[cols*(m)+rows]=a[rows*(m)+cols];
}
int main(){
	int m;
	printf("Enter m");
	scanf("%d",&m);
	int a[m*m],b[m*m];
	printf("Enter elements \n");
	for(int i = 0;i<m*m;i++)
		scanf("%d",&a[i]);
	int *d_a,*d_b;
	int d_m;
	cudaMalloc((void**)&d_a,m*m*sizeof(int));
	cudaMalloc((void**)&d_b,m*m*sizeof(int));
	cudaMalloc((void**)&d_m,sizeof(int));
	cudaMemcpy(d_a,&a,m*m*sizeof(int),cudaMemcpyHostToDevice);
	dim3 griddim(1,1,1);
	dim3 blockdim(m,m,1);
	transpose<<<griddim,blockdim>>>(d_a,d_b,m);
	cudaMemcpy(&b,d_b,m*m*sizeof(int),cudaMemcpyDeviceToHost);
	printf("Transpose of the matrix is \n");
	for(int i = 0;i<m*m;i++)
		printf("%d ",b[i]);

	cudaFree(d_a);
	cudaFree(d_b);
	//cudaFree(d_m);
	return 0;
}
