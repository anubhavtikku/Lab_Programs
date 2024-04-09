#include<stdio.h>
#include<mpi.h>
#include<string.h>

int main(int argc,char *argv[])
{char s[80];
 char a[80];
 int b[80];
 int rank,size;
 int i;
 int n;
 MPI_Init(&argc,&argv);
 MPI_Comm_rank(MPI_COMM_WORLD,&rank);
 MPI_Comm_size(MPI_COMM_WORLD,&size);

if(rank==0)
{printf("Enter string ");
 scanf("%s",s);
 n=strlen(s)/size;
}
 MPI_Bcast(&n,1,MPI_INT,0,MPI_COMM_WORLD);
 MPI_Scatter(s,n,MPI_CHAR,a,n,MPI_CHAR,0,MPI_COMM_WORLD);
 int v=0,nv=0;
 for(i=0;i<n;i++)
 if(a[i]=='a'||a[i]=='e'||a[i]=='i'||a[i]=='o'||a[i]=='u')
	 v+=1;
 nv=n-v;
 MPI_Gather(&nv,1,MPI_INT,b,1,MPI_INT,0,MPI_COMM_WORLD);

 if(rank==0)
 {int sum=0;
  printf("\nDifferent processes have different non vowels\n");
  for(i=0;i<size;i++)
	  {printf("%d\n",b[i]);sum+=b[i];}

  printf("\nTotal no. of non vowels is %d \n",sum);
 }

MPI_Finalize();
return 0;
}

