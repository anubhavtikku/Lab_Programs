#include<stdio.h>
#include<mpi.h>
#include<string.h>

int main(int argc,char *argv[])
{int rank,size;

char s[80];
char a[80];
char b[80];
int i;
memset(b,'/',80);
MPI_Init(&argc,&argv);
MPI_Comm_rank(MPI_COMM_WORLD,&rank);
MPI_Comm_size(MPI_COMM_WORLD,&size);
if(rank==0)
{printf("Enter string ");
 fflush(stdout);
 scanf("%s",s);
}

memset(a,'/',80);
MPI_Scatter(s,1,MPI_CHAR,a,1,MPI_CHAR,0,MPI_COMM_WORLD);
for(i=1;i<rank+1;i++)
a[i]=a[0];


MPI_Gather(a,size,MPI_CHAR,b,size,MPI_CHAR,0,MPI_COMM_WORLD);

if(rank==0)
{
  for(i=0;i<80;i++)
  if(b[i]!='/')
  printf("%c",b[i]);
}
MPI_Finalize();
return 0;
}

