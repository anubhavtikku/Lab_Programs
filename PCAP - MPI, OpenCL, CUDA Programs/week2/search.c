#include<stdio.h>
#include<mpi.h>

int main(int argc,char *argv[])
{int rank,size;
 int i;
 int x,n;
 int a[100];
 MPI_Status status;


 MPI_Init(&argc,&argv);
 MPI_Comm_rank(MPI_COMM_WORLD,&rank);
 MPI_Comm_size(MPI_COMM_WORLD,&size);

 if(rank==0)
 { printf("Enter size ");
   scanf("%d",&n);
   printf("Enter numbers ");
   for(i=0;i<n;i++)
       scanf("%d",&a[i]);
   int k=0;
   int s=0;
   printf("Enter search no.");
   scanf("%d",&x);

   MPI_Send(&n,1,MPI_INT,1,1,MPI_COMM_WORLD);
   MPI_Send(&x,1,MPI_INT,1,1,MPI_COMM_WORLD);
   MPI_Send(a,n,MPI_INT,1,1,MPI_COMM_WORLD);

   for(i=0;i<n/2;i++)
       if(a[i]==x)
       k=1;

   MPI_Recv(&s,1,MPI_INT,1,1,MPI_COMM_WORLD,&status);
   if(s==1 || k==1)
       printf("Element found");
   else
       printf("Element not found");
 }

 else
 {int temp=0;
  MPI_Recv(&n,1,MPI_INT,0,1,MPI_COMM_WORLD,&status);
  MPI_Recv(&x,1,MPI_INT,0,1,MPI_COMM_WORLD,&status);
  MPI_Recv(a,n,MPI_INT,0,1,MPI_COMM_WORLD,&status);
  for(i=n/2;i<n;i++)
         if(a[i]==x)
         temp=1;
  MPI_Send(&temp,1,MPI_INT,0,1,MPI_COMM_WORLD);
 }

MPI_Finalize();
return 0;
}
