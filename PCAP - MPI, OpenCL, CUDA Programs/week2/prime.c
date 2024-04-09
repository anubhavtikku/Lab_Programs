#include<stdio.h>
#include<mpi.h>

int isprime(int x)
{int i;
 
 for(i=2;i<x;i++)
 if(x%i==0)
 return 0;
 
 return 1;
}

int main(int argc,char *argv[])
{int rank,size;
 int a[80];
 int x,i;
 MPI_Status status;
 MPI_Init(&argc,&argv);
 MPI_Comm_rank(MPI_COMM_WORLD,&rank);
 MPI_Comm_size(MPI_COMM_WORLD,&size);

 if(rank==0)
 {   printf("Enter array ");
     fflush(stdout);
     for(i=0;i<size;i++)     
     scanf("%d",&a[i]);
     
     for(i=1;i<size;i++)
     MPI_Send(&a[i],1,MPI_INT,i,1,MPI_COMM_WORLD);
    
     if(isprime(a[0]))
     printf("Prime:%d\n",a[0]); 
 }

 else
 {int z;
  MPI_Recv(&z,1,MPI_INT,0,1,MPI_COMM_WORLD,&status); 
  if(isprime(z))
  printf("Prime:%d\n",z); 
 }

 MPI_Finalize();
 return 0;
}
