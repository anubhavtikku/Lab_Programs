__kernel void octal(__global char *a,__global char *b,__global int *n)
{
int i = get_global_id(0);
int m=*n;
int j;

for(j=0;j<m;j++)
b[i*m+j]=a[j];

}

