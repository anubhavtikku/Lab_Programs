#include <stdio.h>
#include <CL/cl.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SOURCE_SIZE 0x1000000

char name[7000][100];
float score[7000];
float a[10][10000];
int id[7000];
int k1=0;
int temp;

void getData(char buff[])
{
   int x,y,c=0;
   float z;
   char str1[100],str2[100];
   char *token = strtok(buff,"\t");
  // printf("**%s**\n",token);
   //printf("%s\n",token);
   //strcpy(name[k1],token);
   //int counter=0;
   //token = strtok(NULL,"\t");
   //score[k1]=atof(token);
   //id[k1]=k1;
   //k1++;
   while(token!=NULL) 
   {  
      if(c%2==0)
          strcpy(name[k1],token);//  m.name=token;
      else{
          score[k1]=atof(token);
      //    printf("%f",score[k1]);
      }
      id[k1]=k1;
     // rank[k]=k;
    //printf("%s\n",token);
      token = strtok(NULL,"\t");
    //  k++;
      c++;
   } 
   k1++;
   //printf("%d %s %.1f\n",id[k1-1],name[k1-1],score[k1-1]);
}

int im[10][10000];
int k[10]={0};

float a1[10000];
int im1[10000];

int main(int argc, char* argv[]) {
	int i,n=0;
	int j;

    FILE *fp1 = fopen("edit.csv","r");
    int count=0;
    char buff[1024];
    char *res;
    res = fgets(buff, 1024, (FILE*)fp1);

   do
   {
    res = fgets(buff, 1024, (FILE*)fp1);
    if(res==NULL)
    break; 
 //   printf("%s",buff);
    getData(buff);
    }while(1);

    fclose(fp1);

    for(i=0;i<k1;i++)
    //{scanf("%f",&x);
    {
      temp=(int)score[i];
      im[temp][k[temp]]=id[i];
      a[temp][k[temp]++]=score[i];    
    }
    
    int z=0;
    for(i=0;i<10;i++)
    {for(j=0;j<k[i];j++) 	
     {
     im1[z]=im[i][j];
     a1[z++]=a[i][j];
     }
    }

//for(i=0;i<z;i++)
//printf("%.1f\t",a1[i]);

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

	cl_mem a_mem_obj = clCreateBuffer(context,CL_MEM_READ_WRITE,10000*sizeof(float),NULL,&ret);
	cl_mem b_mem_obj = clCreateBuffer(context,CL_MEM_READ_WRITE,10000*sizeof(int),NULL,&ret);
        cl_mem c_mem_obj = clCreateBuffer(context,CL_MEM_READ_ONLY,10*sizeof(int),NULL,&ret);
	
	ret = clEnqueueWriteBuffer(command_queue,a_mem_obj,CL_TRUE,0,10000*sizeof(float),a1,0,NULL,NULL);
	ret = clEnqueueWriteBuffer(command_queue,b_mem_obj,CL_TRUE,0,10000*sizeof(int),im1,0,NULL,NULL);
        ret = clEnqueueWriteBuffer(command_queue,c_mem_obj,CL_TRUE,0,10*sizeof(int),k,0,NULL,NULL);
	
	cl_program program = clCreateProgramWithSource(context,1,(const char**)&source_str,(const size_t*)&source_size,&ret);
        
	ret = clBuildProgram(program,1,&device_id,NULL,NULL,NULL);

	cl_kernel kernel = clCreateKernel(program,"octal",&ret);
	ret = clSetKernelArg(kernel,0,sizeof(cl_mem),(void*)&a_mem_obj);
	ret = clSetKernelArg(kernel,1,sizeof(cl_mem),(void*)&b_mem_obj);
	ret = clSetKernelArg(kernel,2,sizeof(cl_mem),(void*)&c_mem_obj);

	size_t global_item_size=10;
	size_t local_item_size =1;
	ret = clEnqueueNDRangeKernel(command_queue,kernel,1,NULL,&global_item_size,&local_item_size,0,NULL,NULL);
	//printf("%d",ret);
        ret = clEnqueueReadBuffer(command_queue,a_mem_obj,CL_TRUE,0,10000*sizeof(float),a1,0,NULL,NULL);
	ret = clEnqueueReadBuffer(command_queue,b_mem_obj,CL_TRUE,0,10000*sizeof(int),im1,0,NULL,NULL);
	ret = clFinish(command_queue);

	for(i=0;i<z;i++)
        printf("%d %s %.2f \n",i+1,name[im1[i]],a1[i]);


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

