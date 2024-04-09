__kernel void octal(__global char *A, __global char *B) 
{
	int id = get_global_id(0);
	int n=get_global_size(0);
	
	int data=A[id];
	
	int pos=0;
	int i;
	
	for(i=0;i<n;i++)
	if ((A[i]<data)||(A[i]==data && i<id))
	pos++;
	
	B[pos]=data;
	
}
