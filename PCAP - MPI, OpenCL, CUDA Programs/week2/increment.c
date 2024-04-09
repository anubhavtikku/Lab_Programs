#include<stdio.h>
#include<mpi.h>

int main(int argc,char *argv[])
{int rank,size;
 int x,i;
 MPI_Status status;

 MPI_Init(&argc,&argv);
 MPI_Comm_rank(MPI_COMM_WORLD,&rank);
 MPI_Comm_size(MPI_COMM_WORLD,&size);

 if(rank==0)
 {printf("Enter number ");
  scanf("%d",&x);

  MPI_Send(&x,1,MPI_INT,rank+1,1,MPI_COMM_WORLD);
  MPI_Recv(&x,1,MPI_INT,size-1,1,MPI_COMM_WORLD,&status);
  printf("Output is %d",x);
}
 else
 {   MPI_Recv(&x,1,MPI_INT,rank-1,1,MPI_COMM_WORLD,&status);
     printf("Received number %d by process %d\n",x,rank);
     x=x+1;
     MPI_Send(&x,1,MPI_INT,(rank+1)%size,1,MPI_COMM_WORLD);
 }

 MPI_Finalize();
 return 0;
}
