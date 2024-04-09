#include<stdio.h>
#include<mpi.h>

int main(int argc,char *argv[])
{int rank,size;
int a[20];
int b[20],c[20],d[20];
int i,count;

MPI_Init(&argc,&argv);
MPI_Comm_rank(MPI_COMM_WORLD,&rank);
MPI_Comm_size(MPI_COMM_WORLD,&size);
if(rank==0)
{printf("Enter values for matrix 1\n");
for(i=0;i<9;i++)
    scanf("%d",&a[i]);
printf("Enter values for matrix 2\n");
for(i=0;i<9;i++)
    scanf("%d",&b[i]);

}

MPI_Scatter(a,3,MPI_INT,c,3,MPI_INT,0,MPI_COMM_WORLD);
MPI_Scatter(b,3,MPI_INT,d,3,MPI_INT,0,MPI_COMM_WORLD);


for(i=0;i<3;i++)
{ printf("%d\t",c[i]+d[i]);
}printf("\n");

MPI_Reduce(&c,&count,1,MPI_INT,MPI_SUM,0,MPI_COMM_WORLD);

MPI_Finalize();
return 0;
}
