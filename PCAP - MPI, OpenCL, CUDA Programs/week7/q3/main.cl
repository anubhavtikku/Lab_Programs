__kernel void swap(__global int* A,__global int* B, int m, int n){
	int i = get_global_id(1);
	int j = get_global_id(0);
        int x=get_global_size(0);
	int y=get_global_size(1);
        printf("\nCoord%d %d %d %d",i,j,x,y);
	B[j*n+i]=A[i*n+j];
}
