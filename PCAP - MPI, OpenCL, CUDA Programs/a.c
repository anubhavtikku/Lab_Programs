#include<stdio.h>
#include<string.h>
#include<mpi.h>

int main(int argc,char *argv[])
{  int rank,size;
   int l1,i,j,sum=0;
   int k,x;
 int a[4][4];
 int b[4],c[4];
 int d[4];
 
MPI_Init(&argc,&argv);
MPI_Comm_rank(MPI_COMM_WORLD,&rank);
MPI_Comm_size(MPI_COMM_WORLD,&size);
if(rank==0)
{
  for(i=0;i<size;i++)
  for(j=0;j<size;j++)
  scanf("%d",&a[i][j]);

}

MPI_Scatter(a,4,MPI_INT,b,4,MPI_INT,0,MPI_COMM_WORLD);
MPI_Allgather(b,1,MPI_INT,c,1,MPI_INT,MPI_COMM_WORLD);

MPI_Reduce(c,d,4,MPI_INT,MPI_PROD,0,MPI_COMM_WORLD);

if(rank==0)
printf("%d %d %d %d",d[0],d[1],d[2],d[3]);


MPI_Finalize();

}
