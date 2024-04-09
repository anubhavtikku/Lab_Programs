__kernel void octal(__global char *a,__global char *b,__global int *n)
{
int i = get_global_id(0);
int k=a[i];

int x=k,y=0,rem;

while(x>0)
{rem=x%10;
 x=x/10;
 y=y*10+rem;
}

b[i]=(char)y;

}
