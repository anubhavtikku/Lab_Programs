#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <CL/cl.h>
#define MAX_SOURCE_SIZE (0x100000)

int main(){
	int i,j,m,n;
	printf("Enter m,n:");
	scanf("%i %i",&m,&n);
	int A[m*n],B[m*n];
	for(i=0;i<m*n;i++)
			scanf("%i",&A[i]);
	FILE* fp;
	char* source_str;
	size_t source_size;
	fp = fopen("lab72.cl", "r");
	source_str=(char*)malloc(MAX_SOURCE_SIZE);
	source_size=fread(source_str, 1, MAX_SOURCE_SIZE, fp);
	fclose(fp);
	cl_platform_id platform_id = NULL;
	cl_device_id device_id = NULL;
	cl_uint ret_num_devices, ret_num_platforms;
	cl_int ret = clGetPlatformIDs(1, &platform_id, &ret_num_platforms);
	ret = clGetDeviceIDs(platform_id, CL_DEVICE_TYPE_CPU, 1, &device_id, &ret_num_devices);
	cl_context context = clCreateContext(NULL, 1, &device_id, NULL, NULL, &ret);
	cl_command_queue command_queue = clCreateCommandQueue(context, device_id, NULL, &ret);
	cl_mem a_mem_obj = clCreateBuffer(context, CL_MEM_READ_ONLY,m*n*sizeof(int), NULL, &ret);
	cl_mem c_mem_obj = clCreateBuffer(context, CL_MEM_WRITE_ONLY, m*n*sizeof(int), NULL, &ret);
	ret = clEnqueueWriteBuffer(command_queue, a_mem_obj, CL_TRUE, 0,m*n*sizeof(int), A, 0, NULL, NULL);
	cl_program program = clCreateProgramWithSource(context, 1, (const char**)&source_str, (const size_t*)&source_size, &ret);
	ret = clBuildProgram(program, 1, &device_id, NULL, NULL, NULL);
	//printf("%i",ret);
	cl_kernel kernel = clCreateKernel(program, "mat_change", &ret);
	//printf("%i",ret);
	ret = clSetKernelArg(kernel, 0, sizeof(cl_mem), (void*)&a_mem_obj);
	ret = clSetKernelArg(kernel, 1, sizeof(cl_mem), (void*)&c_mem_obj);
	ret = clSetKernelArg(kernel, 2, sizeof(cl_int), (void*)&m);
	ret = clSetKernelArg(kernel, 3, sizeof(cl_int), (void*)&n);

	size_t global_item_size[2]={m,n};
	size_t local_item_size[2]= {1,1};
	ret = clEnqueueNDRangeKernel(command_queue, kernel, 2, NULL, global_item_size, local_item_size, 0, NULL, NULL);
	ret = clFinish(command_queue);
	ret = clEnqueueReadBuffer(command_queue, c_mem_obj, CL_TRUE, 0,m*n*sizeof(int), B, 0, NULL, NULL);
	for(i=0;i<m*n;i++)
	{
			printf("%i\t",B[i]);
			if((i+1)%m==0)
				printf("\n");
	}
	ret = clFlush(command_queue);
	ret = clReleaseKernel(kernel);
	ret = clReleaseProgram(program);
	ret = clReleaseMemObject(a_mem_obj);
	ret = clReleaseMemObject(c_mem_obj);
	ret = clReleaseCommandQueue(command_queue);
	ret = clReleaseContext(context);
	return 0;
}


