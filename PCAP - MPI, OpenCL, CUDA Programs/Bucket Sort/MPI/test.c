#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<mpi.h>

int comparator(const void *p, const void *q) 
{ 
    // Get the values at given addresses 
  //   int l = *(const int *)p; 
    //  int r = *(const int *)q; 
    float a = *(const float *)p;
    float b = *(const float *)q;
  return ((int) ((a-b)*1000));
} 

char name[7000][100];
float score[7000];
int id[7000];
int k1=0;

void getData(char *buff);

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

int main(int argc,char *argv[])
{
    FILE *fp = fopen("edit.csv","r");
    int count=0;
    char buff[1024];
    char *res;
    res = fgets(buff, 1024, (FILE*)fp);

int rank,size;
float a[10][10000];
float d[10][10000];
int im[10][10000];
int im2[10][10000];
int k[10]={0};
int i,j,temp;
float x;
float b[10000];
int imp[10000];
float t;
int c;

memset(k,0,10);

MPI_Init(&argc,&argv);
MPI_Comm_rank(MPI_COMM_WORLD,&rank);
MPI_Comm_size(MPI_COMM_WORLD,&size);

if(rank==0)
{
    do
  {
   res = fgets(buff, 1024, (FILE*)fp);
   if(res==NULL)
    break; 
   //printf("%s",buff);
    getData(buff);
  }while(1);

/*
for(int i=0;i<k1;i++)
{
  printf("\n!!%d\t\t%s\t\t%f!!",id[i],name[i],score[i]);
}*/

  //printf("Enter values ");
  //fflush(stdout);
  for(i=0;i<k1;i++)
  //{scanf("%f",&x);
    {
      temp=(int)score[i];
      im[temp][k[temp]]=id[i];
      a[temp][k[temp]++]=score[i];    
    }
}

MPI_Scatter(im,10000,MPI_INT,imp,10000,MPI_INT,0,MPI_COMM_WORLD);
MPI_Scatter(a,10000,MPI_FLOAT,b,10000,MPI_FLOAT,0,MPI_COMM_WORLD);
MPI_Scatter(k,1,MPI_INT,&c,1,MPI_INT,0,MPI_COMM_WORLD);
//qsort(b,c,sizeof(b[0]),comparator);
for(i=0;i<c;i++)
  for(j=0;j<c-i-1;j++)
    if(b[j]>b[j+1])
      {
        t=b[j];
        b[j]=b[j+1];
        b[j+1]=t;
        temp=imp[j];
        imp[j]=imp[j+1];
        imp[j+1]=temp;
      }

MPI_Gather(b,10000,MPI_FLOAT,d,10000,MPI_FLOAT,0,MPI_COMM_WORLD);
MPI_Gather(imp,10000,MPI_INT,im2,10000,MPI_INT,0,MPI_COMM_WORLD);
if(rank==0)
{
   // printf("hello world\n");
    //for(i=0;i<10;i++)
    //printf("%d\n",k[i]);
    int z=0;
    for(i=0;i<10;i++)
    for(j=0;j<k[i];j++)
      printf("%d\t%s\t%.1f\n",z++,name[im2[i][j]],d[i][j]);
}
MPI_Finalize();
fclose(fp);
}
