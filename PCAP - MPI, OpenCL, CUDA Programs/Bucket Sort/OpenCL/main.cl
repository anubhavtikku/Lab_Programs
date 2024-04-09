__kernel void octal(__global float *a, __global int *b,__global int *k) 
{
      int id = get_global_id(0);
      int i,j,temp,cf=0;
      float t;
      
      for(i=0;i<id;i++)
      cf+=k[i];
     
      for(i=cf;i<cf+k[id];i++)
      for(j=cf;j<cf+k[id]-1;j++)
      if(a[j]>a[j+1])
      {
        t=a[j];
        a[j]=a[j+1];
        a[j+1]=t;
        temp=b[j];
        b[j]=b[j+1];
        b[j+1]=temp;
      }
	
}
