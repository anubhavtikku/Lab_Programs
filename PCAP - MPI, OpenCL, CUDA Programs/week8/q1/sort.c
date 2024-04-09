#include <stdio.h>
#include <CL/cl.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SOURCE_SIZE 0x100000

int main(int argc, char* argv[]) {
	int n;
	char a[100],b[100];
	printf("Enter string ");
	fgets(a,100,stdin);
	a[strlen(a)-1]='\0';

	n=strlen(a);

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

	cl_mem a_mem_obj = clCreateBuffer(context,CL_MEM_READ_ONLY,n*sizeof(char),NULL,&ret);
	cl_mem b_mem_obj = clCreateBuffer(context,CL_MEM_WRITE_ONLY,n*sizeof(char),NULL,&ret);

	ret = clEnqueueWriteBuffer(command_queue,a_mem_obj,CL_TRUE,0,n*sizeof(char),a,0,NULL,NULL);

	cl_program program = clCreateProgramWithSource(context,1,(const char**)&source_str,(const size_t*)&source_size,&ret);

	ret = clBuildProgram(program,1,&device_id,NULL,NULL,NULL);

	cl_kernel kernel = clCreateKernel(program,"octal",&ret);
	ret = clSetKernelArg(kernel,0,sizeof(cl_mem),(void*)&a_mem_obj);
	ret = clSetKernelArg(kernel,1,sizeof(cl_mem),(void*)&b_mem_obj);

	size_t global_item_size=n;
	size_t local_item_size =1;
	ret = clEnqueueNDRangeKernel(command_queue,kernel,1,NULL,&global_item_size,&local_item_size,0,NULL,NULL);
	ret = clEnqueueReadBuffer(command_queue,b_mem_obj,CL_TRUE,0,n*sizeof(char),b,0,NULL,NULL);
	ret = clFinish(command_queue);

	printf("Sorted string is %s",b);

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


