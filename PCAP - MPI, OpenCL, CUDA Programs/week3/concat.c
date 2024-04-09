#include<stdio.h>
#include<string.h>
#include<mpi.h>

int main(int argc,char *argv[])
{
 int rank,size;
 int n,i;
 char a[80],b[80],c[80],d[80],e[80],f[80];
 MPI_Init(&argc,&argv);
 MPI_Comm_rank(MPI_COMM_WORLD,&rank);
 MPI_Comm_size(MPI_COMM_WORLD,&size);
 if(rank==0)
 {
	 printf("Enter first string ");
	 scanf("%s",a);
	 printf("Enter second string ");
	 scanf("%s",b);
	 n=strlen(a)/size;
 }
 MPI_Bcast(&n,1,MPI_INT,0,MPI_COMM_WORLD);
 MPI_Scatter(a,n,MPI_CHAR,c,n,MPI_CHAR,0,MPI_COMM_WORLD);
 MPI_Scatter(b,n,MPI_CHAR,d,n,MPI_CHAR,0,MPI_COMM_WORLD);
 int k=0;
 for(i=0;i<n;i++)
 {e[k++]=c[i];e[k++]=d[i];}

 MPI_Gather(e,2*n,MPI_CHAR,f,2*n,MPI_CHAR,0,MPI_COMM_WORLD);

 if(rank==0)
 {   f[2*strlen(a)]='\0';
	 printf("\nThe modified string is %s\n",f);
 }

 MPI_Finalize();
 return 0;
}

