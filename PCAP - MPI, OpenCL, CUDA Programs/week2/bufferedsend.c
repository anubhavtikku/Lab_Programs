#include<stdio.h>
#include<mpi.h>

int main(int argc,char *argv[])
{int rank,size;
 int i;
 int x;
 int a[100];
 MPI_Status status;


 MPI_Init(&argc,&argv);
 MPI_Comm_rank(MPI_COMM_WORLD,&rank);
 MPI_Comm_size(MPI_COMM_WORLD,&size);

 if(rank==0)
 { int s;
   MPI_Pack_size(size,MPI_INT,MPI_COMM_WORLD,&s);
   /*int *d=malloc(size*sizeof(int));
   int bsize=s+size*MPI_BSEND_OVERHEAD;
   int *c=malloc(bsize);*/
   int c[1000];
   printf("Enter numbers ");
   for(i=0;i<size;i++)
       scanf("%d",&a[i]);
   MPI_Buffer_attach(c,1000);
   for(i=1;i<size;i++)
     MPI_Bsend(&a[i],1,MPI_INT,i,1,MPI_COMM_WORLD);

   printf("Process %d prints %d\n",rank,a[0]*a[0]);
 }

 else
 {MPI_Recv(&x,1,MPI_INT,0,1,MPI_COMM_WORLD,&status);
  if(rank%2==0)
  printf("Process %d prints %d\n",rank,x*x);
  else
  printf("Process %d prints %d\n",rank,x*x*x);
 }

MPI_Finalize();
return 0;
}

