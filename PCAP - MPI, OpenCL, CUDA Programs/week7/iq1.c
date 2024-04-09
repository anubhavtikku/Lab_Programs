#include <CL/cl.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_SOURCE_SIZE 0x100000

int main()
{
	int i;
	int a[100];
	int m,n;

	printf("Enter dimensions of matrix ");
	scanf("%d %d",&m,&n);

	printf("Enter values of matrix\n");
	for(i=0;i<m*n;i++)
		scanf("%d",&a[i]);


	FILE *fp;
	char *source_str;
	size_t source_size;

	fp = fopen("main.cl","r");

	if(!fp)
	{
		fprintf(stderr,"Failed to load kernel\n");
		exit(1);
	}

	source_str = (char *)malloc(MAX_SOURCE_SIZE);
	source_size = fread(source_str,1,MAX_SOURCE_SIZE,fp);

	fclose(fp);

	cl_platform_id pid = NULL;
	cl_device_id did = NULL;
	cl_uint dno;
	cl_uint pno;

	cl_int ret = clGetPlatformIDs(1,&pid,&pno);

	ret = clGetDeviceIDs(pid,CL_DEVICE_TYPE_GPU,1,&did,&dno);

	cl_context context = clCreateContext(NULL,1,&did,NULL,NULL,&ret);

	cl_command_queue queue = clCreateCommandQueue(context,did,NULL,&ret);

	cl_mem a_mem_obj = clCreateBuffer(context,CL_MEM_READ_ONLY,m*n*sizeof(int),NULL,&ret);
	cl_mem b_mem_obj = clCreateBuffer(context,CL_MEM_WRITE_ONLY,m*n*sizeof(int),NULL,&ret);

	ret = clEnqueueWriteBuffer(queue,a_mem_obj,CL_TRUE,0,m*n*sizeof(int),a,0,NULL,NULL);
	cl_program program = clCreateProgramWithSource(context,1,(const char**)&source_str,(const size_t *)&source_size,&ret);

	ret = clBuildProgram(program,1,&did,NULL,NULL,NULL);



	cl_kernel kernel = clCreateKernel(program,"octal",&ret);

	ret = clSetKernelArg(kernel,0,sizeof(cl_mem),(void *)&a_mem_obj);
	ret = clSetKernelArg(kernel,1,sizeof(cl_mem),(void *)&b_mem_obj);

	size_t global_item_size[2]={m,n};
 	size_t local_item_size[2]= {1,1};

	cl_event event;
	ret = clEnqueueNDRangeKernel(queue,kernel,2,NULL,global_item_size,local_item_size,0,NULL,NULL);
	ret = clFinish(queue);

	int b[100];
	ret = clEnqueueReadBuffer(queue,b_mem_obj,CL_TRUE,0,m*n*sizeof(int),b,0,NULL,NULL);


printf("\nArray returning \n");

	for(i=0;i<m*n;i++)
			{printf("%d\t",b[i]);
			if(i%n==n-1)
				printf("\n");
			}

	clFlush(queue);
	clReleaseKernel(kernel);
	clReleaseProgram(program);
	clReleaseMemObject(a_mem_obj);
	clReleaseMemObject(b_mem_obj);
	clReleaseCommandQueue(queue);
	clReleaseContext(context);

	//free(a);
	//free(b);
	return 0;
}
