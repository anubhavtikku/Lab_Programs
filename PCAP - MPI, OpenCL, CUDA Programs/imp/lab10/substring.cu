#include<stdio.h>
#include<string.h>
__global__ void substring(char *a,char *b,int *m,int *n,int *match){
	int idx = threadIdx.x+blockDim.x*blockIdx.x;
	
	if(idx<=((*m)-(*n)))
	{
		int flag = 1;
		for(int i = 0;i<(*n);i++){
			if(a[idx+i]!=b[i]){
				flag=0;
				break;
			}
		}
	match[idx]=flag;		
	
	}
	


}
int main(){
	int m,n,pos=-1;
	char s[100],p[100];
	printf("Enter string \n");
	scanf("%s",s);
	m=strlen(s);
	printf("Enter pattern \n");
	scanf("%s",p);
	n=strlen(p);
	int match[m-n+1];
	for(int i =0;i<m-n;i++)
		match[i]=2;
	char *d_s,*d_p;
	int *d_m,*d_n,*d_match;
	cudaMalloc((void**)&d_s,m*sizeof(char));
	cudaMalloc((void**)&d_p,n*sizeof(char));
	cudaMalloc((void**)&d_m,sizeof(int));
	cudaMalloc((void**)&d_n,sizeof(int));
	cudaMalloc((void**)&d_match,(m-n+1)*sizeof(int));
	cudaMemcpy(d_s,s,m*sizeof(char),cudaMemcpyHostToDevice);
	cudaMemcpy(d_p,p,n*sizeof(char),cudaMemcpyHostToDevice);
	cudaMemcpy(d_m,&m,sizeof(int),cudaMemcpyHostToDevice);
	cudaMemcpy(d_n,&n,sizeof(int),cudaMemcpyHostToDevice);
	dim3 griddim(1,1,1);
	dim3 blockdim(m-n+1,1,1);
	substring<<<griddim,blockdim>>>(d_s,d_p,d_m,d_n,d_match);
	cudaMemcpy(match,d_match,(m-n+1)*sizeof(int),cudaMemcpyDeviceToHost);
	for(int i =0;i<=(m-n);i++){
		if(match[i]==1){
			pos=i;
		}
	}
	printf("Substring found at position %d",pos);

	cudaFree(d_s);
	cudaFree(d_p);
	cudaFree(d_m);
	cudaFree(d_n);
	cudaFree(d_match);
	return 0;
}
