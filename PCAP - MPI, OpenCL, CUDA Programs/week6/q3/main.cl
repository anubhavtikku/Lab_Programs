__kernel void octal(__global char *a,__global char *b,__global int *n)
{
int i = get_global_id(0);
int m=*n;

b[m-i-1]=a[i];
}
