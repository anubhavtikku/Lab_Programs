#include<stdio.h>
#include<mpi.h>

int fact(int x)
{int i,prod=1;

 for(i=2;i<=x;i++)
 prod=prod*i;

 return prod;
}

int main(int argc,char *argv[])
{int rank,size;
 int a[80];
 int i,z;
 MPI_Init(&argc,&argv);
 MPI_Comm_rank(MPI_COMM_WORLD,&rank);
 MPI_Comm_size(MPI_COMM_WORLD,&size);

 if(rank==0)
 {printf("Enter values ");
  fflush(stdout);
  for(i=0;i<size;i++)
  scanf("%d",&a[i]);
 }

 MPI_Scatter(a,1,MPI_INT,&z,1,MPI_INT,0,MPI_COMM_WORLD);

 printf("Rank%d prints factorial of %d which is %d\n",rank,z,fact(z));

 MPI_Finalize();
 return 0;
}

