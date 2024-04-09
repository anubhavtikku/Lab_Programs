#include<stdio.h>
#include<mpi.h>
#include<stdlib.h>

int main(int argc,char *argv[])
{int rank,size;
 int i;
 MPI_Status status;

 MPI_Init(&argc,&argv);
 MPI_Comm_rank(MPI_COMM_WORLD,&rank);
 MPI_Comm_size(MPI_COMM_WORLD,&size);

 if(rank==0)
 { double t1,t2;
 t1=MPI_Wtime();
  int sum=0,x;
  for(i=0;i<=argc/2;i++)
        sum+=atoi(argv[i]);
  MPI_Recv(&x,1,MPI_INT,1,1,MPI_COMM_WORLD,&status);
  printf("Sum is %d\n",sum+x);
  t2=MPI_Wtime();
       printf("Time taken by process %d is %lf\n",rank,t2-t1);
 }

 else
 {   double t1,t2;
     t1=MPI_Wtime();
     int temp=0;
     for(i=argc/2+1;i<argc;i++)
     temp+=atoi(argv[i]);
     MPI_Send(&temp,1,MPI_INT,0,1,MPI_COMM_WORLD);
     t2=MPI_Wtime();
     printf("Time taken by process %d is %lf\n",rank,t2-t1);
 }
 MPI_Finalize();
 return 0;
 }
