#include <stdio.h>
#include <stdlib.h>
#include <CL/cl.h>
#define MAX_SOURCE_SIZE (0x100000)

int main(void){
	int i,j;
	cl_int m,n;
	printf("Enter m,n\n");
	scanf("%d %d", &m,&n);
	int* A = (int*) malloc(m*n*sizeof(int));
	int* B = (int*) malloc(m*n*sizeof(int));
	//int A[10][10],B[10][10];
	printf("Enter A\n");
	//for(i=0; i<m; i++){
		for(j=0;j<m*n;j++){
			scanf("%d", &A[j]);
		}
	//}
	FILE* fp;
	char* source_str;
	size_t source_size;
	fp = fopen("main.cl", "r");
	if(!fp)
		printf("HI\n");
	source_str = (char*) malloc(MAX_SOURCE_SIZE);
	source_size = fread(source_str, 1, MAX_SOURCE_SIZE, fp);
	fclose(fp);
	cl_platform_id platform_id = NULL;
	cl_device_id device_id = NULL;
	cl_uint ret_num_devices, ret_num_platforms;
	cl_int ret = clGetPlatformIDs(1, &platform_id, &ret_num_platforms);
	ret = clGetDeviceIDs(platform_id, CL_DEVICE_TYPE_GPU, 1, &device_id, &ret_num_devices);
	cl_context context = clCreateContext(NULL, 1, &device_id, NULL, NULL, &ret);

	cl_command_queue command_queue = clCreateCommandQueue(context, device_id, NULL, &ret);

	cl_mem a_mem_obj = clCreateBuffer(context, CL_MEM_READ_WRITE, m*n*sizeof(int), NULL, &ret);

	cl_mem b_mem_obj = clCreateBuffer(context, CL_MEM_READ_WRITE, m*n*sizeof(int), NULL, &ret);

	ret = clEnqueueWriteBuffer(command_queue, a_mem_obj, CL_TRUE, 0, m*n*sizeof(int), A, 0, NULL, NULL);
	cl_program program = clCreateProgramWithSource(context, 1, (const char**)&source_str, (const size_t*)&source_size, &ret);

	ret = clBuildProgram(program, 1, &device_id, NULL, NULL, NULL);
	cl_kernel kernel = clCreateKernel(program,"swap", &ret);

	ret = clSetKernelArg(kernel, 0, sizeof(cl_mem), (void*)&a_mem_obj);
	ret = clSetKernelArg(kernel, 1, sizeof(cl_mem), (void*)&b_mem_obj);
	ret = clSetKernelArg(kernel, 2, sizeof(cl_int), (void*)&m);
	ret = clSetKernelArg(kernel, 3, sizeof(cl_int), (void*)&n);
	size_t global_item_size[2] = {m,n};
	size_t local_item_size[2] = {1,1};
	cl_event event;
	ret = clEnqueueNDRangeKernel(command_queue, kernel, 2, NULL, global_item_size, local_item_size, 0, NULL, NULL);
	ret = clFinish(command_queue);
	ret = clEnqueueReadBuffer(command_queue, b_mem_obj, CL_TRUE, 0, m*n*sizeof(int), B, 0, NULL, NULL);
	printf("B\n");
		//for(i=0; i<m; i++){
			for(j=0;j<m*n;j++){
				printf("%d ", B[j]);
				//if(j%n==0 && j!=0)
					//printf("\n");
			}
		//}
	ret = clFlush(command_queue);
	ret = clReleaseKernel(kernel);
	ret = clReleaseProgram(program);
	ret = clReleaseMemObject(a_mem_obj);
	ret = clReleaseMemObject(b_mem_obj);
	ret = clReleaseCommandQueue(command_queue);
	ret = clReleaseContext(context);
	free(A);
	free(B);
	getchar();
	return 0;
}

