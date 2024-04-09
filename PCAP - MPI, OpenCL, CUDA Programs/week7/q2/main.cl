__kernel void mat_change(global int* A,global int* C, int m,int n)
{
	int i=get_global_id(0);
	int j=get_global_id(1);
	int k;
	int rem=0;
	if(i==m-1 ||j==n-1 ||i==0||j==0)
	{
		C[i*m+j]=A[i*m+j];
	}
	else
	{

		k=A[i*m+j];
		int pow=1;
		while(k>0)
		{
			if(k%2==0)
			{
				rem=rem+(1)*pow;
			}
			else
				rem=rem+(0)*pow;
				
			pow=pow*10;
			k=k/2;
		}
		C[i*m+j]=rem;
	}
}
