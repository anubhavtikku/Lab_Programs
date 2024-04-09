#include<stdio.h>
#include<string.h>
#include<mpi.h>
#include<ctype.h>

int main(int argc,char *argv[])
{int rank,size,i;
 char s[80],a[80],d[80];
 int b[80];
 int c[80];
 int n;

 MPI_Init(&argc,&argv);
 MPI_Comm_rank(MPI_COMM_WORLD,&rank);
 MPI_Comm_size(MPI_COMM_WORLD,&size);

 if(rank==0)
 {
    printf("Enter string ");
    scanf("%s",s);
    n=strlen(s)/size;
 }
 MPI_Bcast(&n,1,MPI_INT,0,MPI_COMM_WORLD);
 MPI_Scatter(s,n,MPI_CHAR,a,n,MPI_CHAR,0,MPI_COMM_WORLD);

 for(i=0;i<n;i++)
 {if(isupper(a[i]))
	 a[i]=tolower(a[i]);
  else
	 a[i]=toupper(a[i]);
 b[i]=(int)a[i];
 }

 MPI_Gather(a,n,MPI_CHAR,d,n,MPI_CHAR,0,MPI_COMM_WORLD);
 MPI_Gather(b,n,MPI_INT,c,n,MPI_INT,0,MPI_COMM_WORLD);

 if(rank==0)
 {
	 printf("\nModified string is %s\n",d);
	 printf("ASCII value\n");
	 for(i=0;i<strlen(s);i++)
		 printf("%d\t",c[i]);
 }

 MPI_Finalize();
 return 0;
}

