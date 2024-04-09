__kernel void octal(__global char *a, __global char *b,__global int *cnt,__global int *n) 
{
	int id = get_global_id(0);
	int no=get_global_size(0);
	
	int li=n[id]+1;
	int ri=n[id+1];
	
	int flag=0;
	int i,j=0;
	
	for(i=li;i<ri;i++)
	if(a[i]==b[j])
	j++;
	else
	{flag=1;break;}
	
	if(flag==0)
	{*cnt=*cnt + 1;}//printf("hello world");}
	
}
