#include<stdio.h>
#include<mpi.h>

int main(int argc,char *argv[])
{int rank,size;
 int a[200];
 int b[100];
 int c[100];
 int m,z;
 int i,j;
 MPI_Status status;
 MPI_Init(&argc,&argv);
 MPI_Comm_rank(MPI_COMM_WORLD,&rank);
 MPI_Comm_size(MPI_COMM_WORLD,&size);

 if(rank==0)
 {printf("Enter value of m ");
  fflush(stdout);
  scanf("%d",&m);

  printf("Enter values ");
  fflush(stdout);
  for(i=0;i<size*m;i++)
  scanf("%d",&a[i]);
 }
  MPI_Bcast(&m,1,MPI_INT,0,MPI_COMM_WORLD);
  MPI_Scatter(a,m,MPI_INT,b,m,MPI_INT,0,MPI_COMM_WORLD);
  int avg=0;
  for(i=0;i<m;i++)
  avg+=b[i];

  avg=avg/m;
  MPI_Gather(&avg,1,MPI_INT,c,1,MPI_INT,0,MPI_COMM_WORLD);

 if(rank==0)
 { int s=0;
   for(i=0;i<size;i++)
   s+=c[i];
   s=s/size;
   printf("\nTotal average is %d\n",s);
 }

 MPI_Finalize();
 return 0;
}

