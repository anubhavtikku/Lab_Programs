#include <stdio.h>
#include <CL/cl.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SOURCE_SIZE 0x100000

int main(int argc, char* argv[]) {
	int i,n=0;
	char a[100],b[100];

	int cnt=0;

	int c[100];
    memset(c,0,100);

	printf("Enter string ");
    fgets(a,100,stdin);

    a[strlen(a)-1]='\0';

    for(i=0;i<strlen(a);i++)
    if(a[i]==' ')
    	n++;

    n=n+2;

    c[0]=-1;
    int k=1;
    c[n-1]=strlen(a);

    for(i=0;i<strlen(a);i++)
    	if(a[i]==' ')
    	c[k++]=i;

    printf("Enter word ");
    fgets(b,100,stdin);

    b[strlen(b)-1]='\0';

	FILE *fp = fopen("main.cl","r");
	if(!fp) {
		fprintf(stderr,"Failed to load kernel");
		exit(1);
	}
	char *source_str = malloc(sizeof(char)*MAX_SOURCE_SIZE);
	size_t source_size = fread(source_str,1,MAX_SOURCE_SIZE,fp);
	fclose(fp);

	cl_platform_id platform_id = NULL;
	cl_device_id device_id = NULL;
	cl_uint ret_num_devices,ret_num_platforms;

	cl_int ret = clGetPlatformIDs(1,&platform_id,&ret_num_platforms);
	ret = clGetDeviceIDs(platform_id,CL_DEVICE_TYPE_GPU,1,&device_id,&ret_num_devices);

	cl_context context = clCreateContext(NULL,1,&device_id,NULL,NULL,&ret);
	cl_command_queue command_queue = clCreateCommandQueue(context,device_id,NULL,&ret);

	cl_mem a_mem_obj = clCreateBuffer(context,CL_MEM_READ_ONLY,strlen(a)+1,NULL,&ret);
	cl_mem b_mem_obj = clCreateBuffer(context,CL_MEM_WRITE_ONLY,strlen(b)+1,NULL,&ret);
	cl_mem c_mem_obj = clCreateBuffer(context,CL_MEM_WRITE_ONLY,sizeof(int),NULL,&ret);
	cl_mem d_mem_obj = clCreateBuffer(context,CL_MEM_WRITE_ONLY,n*sizeof(int),NULL,&ret);

	ret = clEnqueueWriteBuffer(command_queue,a_mem_obj,CL_TRUE,0,strlen(a)+1,a,0,NULL,NULL);
	ret = clEnqueueWriteBuffer(command_queue,b_mem_obj,CL_TRUE,0,strlen(b)+1,b,0,NULL,NULL);
	ret = clEnqueueWriteBuffer(command_queue,c_mem_obj,CL_TRUE,0,sizeof(int),&cnt,0,NULL,NULL);
	ret = clEnqueueWriteBuffer(command_queue,d_mem_obj,CL_TRUE,0,n*sizeof(int),c,0,NULL,NULL);

	cl_program program = clCreateProgramWithSource(context,1,(const char**)&source_str,(const size_t*)&source_size,&ret);

	ret = clBuildProgram(program,1,&device_id,NULL,NULL,NULL);

	cl_kernel kernel = clCreateKernel(program,"octal",&ret);
	ret = clSetKernelArg(kernel,0,sizeof(cl_mem),(void*)&a_mem_obj);
	ret = clSetKernelArg(kernel,1,sizeof(cl_mem),(void*)&b_mem_obj);
	ret = clSetKernelArg(kernel,2,sizeof(cl_mem),(void*)&c_mem_obj);
	ret = clSetKernelArg(kernel,3,sizeof(cl_mem),(void*)&d_mem_obj);

	size_t global_item_size=n;
	size_t local_item_size =1;
	ret = clEnqueueNDRangeKernel(command_queue,kernel,1,NULL,&global_item_size,&local_item_size,0,NULL,NULL);
	ret = clEnqueueReadBuffer(command_queue,b_mem_obj,CL_TRUE,0,n*sizeof(char),b,0,NULL,NULL);
	ret = clEnqueueReadBuffer(command_queue,c_mem_obj,CL_TRUE,0,sizeof(int),&cnt,0,NULL,NULL);
	ret = clFinish(command_queue);

	printf("Occurences %d ",cnt-1);

	ret = clFlush(command_queue);
	ret = clReleaseKernel(kernel);
	ret = clReleaseProgram(program);
	ret = clReleaseMemObject(a_mem_obj);
	ret = clReleaseMemObject(b_mem_obj);
	ret = clReleaseCommandQueue(command_queue);
	ret = clReleaseContext(context);

//	free(a);
	return 0;
}

