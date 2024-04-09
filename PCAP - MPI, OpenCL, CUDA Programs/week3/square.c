#include<stdio.h>
#include<mpi.h>
#include<math.h>

int power(int x,int m)
{int i,prod=1;
for(i=0;i<m;i++)
	prod=prod*x;

return prod;
}

int main(int argc,char *argv[])
{int a[100],b[100],c[100],d[100];
 int m,i;
 int rank,size;
 MPI_Init(&argc,&argv);
 MPI_Comm_rank(MPI_COMM_WORLD,&rank);
 MPI_Comm_size(MPI_COMM_WORLD,&size);

 if(rank==0)
 {printf("Enter m ");
 fflush(stdout);
 scanf("%d",&m);
 printf("Enter values \n");
 for(i=0;i<size*m;i++)
 scanf("%d",&a[i]);
 }

 MPI_Bcast(&m,1,MPI_INT,0,MPI_COMM_WORLD);
 MPI_Scatter(a,m,MPI_INT,b,m,MPI_INT,0,MPI_COMM_WORLD);

 for(i=0;i<m;i++)
	 c[i]=power(b[i],rank+2);

MPI_Gather(c,m,MPI_INT,d,m,MPI_INT,0,MPI_COMM_WORLD);

if(rank==0)
{printf("\n");
for(i=0;i<size*m;i++)
printf("%d\t",a[i]);

printf("\n");
for(i=0;i<size*m;i++)
printf("%d\t",d[i]);
}
MPI_Finalize();
return 0;
}

