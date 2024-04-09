#include<stdio.h>
#include<mpi.h>

int fact(int x)
{   int i,p=1;
    for(i=2;i<=x;i++)
        p=p*i;
    return p;
}

int main(int argc,char *argv[])
{int rank,size;

MPI_Init(&argc,&argv);
MPI_Comm_rank(MPI_COMM_WORLD,&rank);
MPI_Comm_size(MPI_COMM_WORLD,&size);

int sum,s;
s=fact(rank+1);
MPI_Scan(&s,&sum,1,MPI_INT,MPI_SUM,MPI_COMM_WORLD);
//MPI_Barrier(MPI_COMM_WORLD);
if(rank==size-1)
printf("The sum of factorials is %d\n",sum);

MPI_Finalize();
return 0;
}
