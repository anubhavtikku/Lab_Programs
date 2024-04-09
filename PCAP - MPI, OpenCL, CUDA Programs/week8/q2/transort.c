#include <stdio.h>
#include <CL/cl.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SOURCE_SIZE 0x100000

int main(int argc, char* argv[]) {
	int i,n;
	int a[100];
	printf("Enter no of numbers ");
	scanf("%d",&n);

	printf("Enter numbers ");
	for(i=0;i<n;i++)
		scanf("%d",&a[i]);

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

	cl_mem a_mem_obj = clCreateBuffer(context,CL_MEM_READ_WRITE,n*sizeof(int),NULL,&ret);

	ret = clEnqueueWriteBuffer(command_queue,a_mem_obj,CL_TRUE,0,n*sizeof(int),a,0,NULL,NULL);

	cl_program program = clCreateProgramWithSource(context,1,(const char**)&source_str,(const size_t*)&source_size,&ret);

	ret = clBuildProgram(program,1,&device_id,NULL,NULL,NULL);

	cl_kernel kernel = clCreateKernel(program,"odd1",&ret);
	cl_kernel kernel2 = clCreateKernel(program,"odd2",&ret);
	ret = clSetKernelArg(kernel,0,sizeof(cl_mem),(void*)&a_mem_obj);

	ret = clSetKernelArg(kernel2,0,sizeof(cl_mem),(void*)&a_mem_obj);

	size_t global_item_size=n;
	size_t local_item_size =1;
	for(i=0;i<=n/2;i++)
	{ret = clEnqueueNDRangeKernel(command_queue,kernel,1,NULL,&global_item_size,&local_item_size,0,NULL,NULL);
	// ret = clEnqueueReadBuffer(command_queue,a_mem_obj,CL_TRUE,0,n*sizeof(int),a,0,NULL,NULL);
 	 ret = clEnqueueNDRangeKernel(command_queue,kernel2,1,NULL,&global_item_size,&local_item_size,0,NULL,NULL);
 	// ret = clEnqueueReadBuffer(command_queue,a_mem_obj,CL_TRUE,0,n*sizeof(int),a,0,NULL,NULL);
	}

    ret = clEnqueueReadBuffer(command_queue,a_mem_obj,CL_TRUE,0,n*sizeof(int),a,0,NULL,NULL);
	ret=clFinish(command_queue);

	printf("\nThe sorted array is \n");
	for(i=0;i<n;i++)
			printf("%d\t",a[i]);

	ret = clFlush(command_queue);
	ret = clReleaseKernel(kernel);
	ret = clReleaseProgram(program);
	ret = clReleaseMemObject(a_mem_obj);
	ret = clReleaseCommandQueue(command_queue);
	ret = clReleaseContext(context);

	return 0;
}

