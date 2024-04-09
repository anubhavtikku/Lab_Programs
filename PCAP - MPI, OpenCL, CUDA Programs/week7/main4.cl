__kernel void octal(__global int *A,__global int *B) 
{
	int row=get_global_id(0);
	int col=get_global_id(1);

	int m=get_global_size(0);
	int n=get_global_size(1);
	
	int k=A[row*n+col];

	
	B[row*n+col]=k;
	
	int i;
	
	for(i=0;i<row;i++)
	B[row*n+col]*=k;

       printf("\n%d %d Row%d Column%d  :%d    %d",m,n,row,col,A[row*n+col],B[row*n+col]);
}
