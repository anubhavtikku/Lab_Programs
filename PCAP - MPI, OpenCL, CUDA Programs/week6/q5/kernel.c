#include <stdio.h>
#include <CL/cl.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SOURCE_SIZE 0x100000

int main(int argc, char* argv[]) {
    int i,LIST_SIZE,N;
    char A[20486];
    printf("Enter String: ");
    scanf("%s",A);
    printf("Enter Number of times: ");
    scanf("%d",&N);
    LIST_SIZE = strlen(A);
    char *B = malloc(sizeof(char)*(LIST_SIZE*N+1));
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
    ret = clGetDeviceIDs(platform_id,CL_DEVICE_TYPE_CPU,1,&device_id,&ret_num_devices);

    cl_context context = clCreateContext(NULL,1,&device_id,NULL,NULL,&ret);
    cl_command_queue command_queue = clCreateCommandQueue(context,device_id,NULL,&ret);

    cl_mem a_mem_obj = clCreateBuffer(context,CL_MEM_READ_ONLY,LIST_SIZE*sizeof(char),NULL,&ret);
    cl_mem b_mem_obj = clCreateBuffer(context,CL_MEM_WRITE_ONLY,LIST_SIZE*N*sizeof(char),NULL,&ret);
    cl_mem n_mem_obj = clCreateBuffer(context,CL_MEM_READ_ONLY,sizeof(int),NULL,&ret);

    ret = clEnqueueWriteBuffer(command_queue,a_mem_obj,CL_TRUE,0,LIST_SIZE*sizeof(char),A,0,NULL,NULL);
    ret = clEnqueueWriteBuffer(command_queue,n_mem_obj,CL_TRUE,0,sizeof(int),&N,0,NULL,NULL);

    cl_program program = clCreateProgramWithSource(context,1,(const char**)&source_str,(const size_t*)&source_size,&ret);

    ret = clBuildProgram(program,1,&device_id,NULL,NULL,NULL);
    cl_kernel kernel = clCreateKernel(program,"ntimes",&ret);
    ret = clSetKernelArg(kernel,0,sizeof(cl_mem),(void*)&a_mem_obj);
    ret = clSetKernelArg(kernel,1,sizeof(cl_mem),(void*)&b_mem_obj);
    ret = clSetKernelArg(kernel,2,sizeof(cl_mem),(void*)&n_mem_obj);

    size_t global_item_size = LIST_SIZE;
    size_t local_item_size = 1;

    cl_event event;
    ret = clEnqueueNDRangeKernel(command_queue,kernel,1,NULL,&global_item_size,&local_item_size,0,NULL,NULL);

    ret = clFinish(command_queue);

    ret = clEnqueueReadBuffer(command_queue,b_mem_obj,CL_TRUE,0,LIST_SIZE*N*sizeof(char),B,0,NULL,NULL);

    printf("%s\n",B);

    ret = clFlush(command_queue);
    ret = clReleaseKernel(kernel);
    ret = clReleaseProgram(program);
    ret = clReleaseMemObject(a_mem_obj);
    ret = clReleaseMemObject(b_mem_obj);
    ret = clReleaseMemObject(n_mem_obj);
    ret = clReleaseCommandQueue(command_queue);
    ret = clReleaseContext(context);

    free(B);
    return 0;
}
