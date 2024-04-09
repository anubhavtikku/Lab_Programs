#include<stdio.h>
#include<mpi.h>

int main(int argc,char *argv[])
{int rank,size;
int a[20];
int b[20],c[20];
int i,count;

MPI_Init(&argc,&argv);
MPI_Comm_rank(MPI_COMM_WORLD,&rank);
MPI_Comm_size(MPI_COMM_WORLD,&size);
if(rank==0)
{printf("Enter values for matrix ");
for(i=0;i<16;i++)
    scanf("%d",&a[i]);

}

MPI_Scatter(a,4,MPI_INT,b,4,MPI_INT,0,MPI_COMM_WORLD);
MPI_Scan(b,c,4,MPI_INT,MPI_SUM,MPI_COMM_WORLD);


printf("\n");
for(i=0;i<4;i++)
{ printf("%d\t",c[i]);
}

MPI_Reduce(&c,&count,1,MPI_INT,MPI_SUM,0,MPI_COMM_WORLD);

MPI_Finalize();
return 0;
}
