#include<stdio.h>
#include<mpi.h>

int main(int argc,char *argv[])
{int rank,size;
float x,y,area,pi;

MPI_Init(&argc,&argv);
MPI_Comm_rank(MPI_COMM_WORLD,&rank);
MPI_Comm_size(MPI_COMM_WORLD,&size);
x=(float)(rank+1)/size;
y=4.0/(1.0+x*x);
area=(1.0/(float)size)*y;

MPI_Reduce(&area,&pi,1,MPI_FLOAT,MPI_SUM,0,MPI_COMM_WORLD);

if(rank==0)
    printf("The value of pi is %f\n",pi);

MPI_Finalize();
return 0;
}
