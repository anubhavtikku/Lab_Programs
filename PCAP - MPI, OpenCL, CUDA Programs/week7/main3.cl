__kernel void octal(__global int *A,__global int *B) 
{
	int row=get_global_id(0);
	int col=get_global_id(1);

	int m=get_global_size(0);
	int n=get_global_size(1);
	
	int k=A[col*n+row];
        printf("A %d\t",k);
        printf("Row%d Col%d A%d B%d\n",row,col,row*n+col,col*n+row);       

        B[row*n+col]=k;

	
}
