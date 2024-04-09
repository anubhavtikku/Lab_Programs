__kernel void octal(__global char *a,__global char *b,__global int *n)
{
int i = get_global_id(0);
int m,j;
char c[100];

int k=-1;
int last=0,cur=0;

for(j=0;j<*n;j++)
if(a[j]==' ')
{k++;
b[j]=' ';
cur=j;
if(k==i)
break;
else
last=j;
}
last+1
cur-1

for(j=0;j<cur-last-2;j++)
c[j]=a[last+j+1];

for(j=last+1;j<=cur-1;j++)
b[j]=c[fl++]


}
