#include<stdio.h>
#include<mpi.h>

int fact(int x)
{int i,sum=1;
 
 for(i=2;i<=x;i++)
 sum=sum*i;
 
 return sum;
}

int sum(int x)
{int s=0;

 s=(x*(x+1))/2;
 return s;
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
 {int s=fact(rank+1); 
  
  for(i=1;i<size;i++)
  {MPI_Recv(&x,1,MPI_INT,i,1,MPI_COMM_WORLD,&status);
   s+=x;
  }

  printf("Sum is %d",s);
 }

 else if(rank%2==0)
 {
     int z=fact(rank+1);
     MPI_Send(&z,1,MPI_INT,0,1,MPI_COMM_WORLD);  
 }
 
 else
 {   int z=sum(rank+1);
     MPI_Send(&z,1,MPI_INT,0,1,MPI_COMM_WORLD); 
 }

 MPI_Finalize();
 return 0;
}
