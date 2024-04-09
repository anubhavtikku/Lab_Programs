#include<stdio.h>
#include<mpi.h>

int main(int argc,char *argv[])
{int rank,size;

int p;
int error;

MPI_Init(&argc,&argv);
MPI_Comm_rank(MPI_COMM_WORLD,&rank);
MPI_Comm_size(MPI_COMM_WORLD,&size);

if(rank==0)
{
    p=2;
}
MPI_Errhandler_set(MPI_COMM_WORLD,MPI_ERRORS_RETURN);
error=MPI_Bcast(&p,1,MPI_INT,10,MPI_COMM_WORLD);


if(error!=0)
{ char s[800];
  int len,class;
  MPI_Error_string(error,s,&len);
  MPI_Error_class(error,&class);
  printf("Error string:%s\n",s);
  printf("Error class:%d",class);
}

MPI_Finalize();
return 0;
}
