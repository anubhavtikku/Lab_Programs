#include<stdio.h>
#include<mpi.h>

int main(int argc,char *argv[])
{int rank,size;
int a[10];
int b[10];
int i,count;
int k;

MPI_Init(&argc,&argv);
MPI_Comm_rank(MPI_COMM_WORLD,&rank);
MPI_Comm_size(MPI_COMM_WORLD,&size);
if(rank==0)
{printf("Enter values for matrix ");
for(i=0;i<9;i++)
    scanf("%d",&a[i]);

printf("Enter values to be searched ");
scanf("%d",&k);
}

MPI_Bcast(&k,1,MPI_INT,0,MPI_COMM_WORLD);
MPI_Scatter(a,3,MPI_INT,b,3,MPI_INT,0,MPI_COMM_WORLD);

int c=0;

for(i=0;i<3;i++)
{ if(b[i]==k)
    c++;
}

MPI_Reduce(&c,&count,1,MPI_INT,MPI_SUM,0,MPI_COMM_WORLD);

if(rank==0)
    printf("The no. of occurences are %d\n",count);

MPI_Finalize();
return 0;
}
