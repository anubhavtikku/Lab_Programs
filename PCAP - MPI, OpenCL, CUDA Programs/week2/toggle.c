#include<stdio.h>
#include<mpi.h>
#include<ctype.h>
int main(int argc,char *argv[])
{int rank,size;
 char s[80];
 int x,i;
 MPI_Status status;
 MPI_Init(&argc,&argv);
 MPI_Comm_rank(MPI_COMM_WORLD,&rank);
 MPI_Comm_size(MPI_COMM_WORLD,&size);

 if(rank==0)
 {   printf("Enter string ");
     fflush(stdout);
     scanf("%s",s);
     MPI_Ssend(s,sizeof(s),MPI_CHAR,1,1,MPI_COMM_WORLD);
     fflush(stdout);
     MPI_Recv(s,sizeof(s),MPI_CHAR,1,1,MPI_COMM_WORLD,&status);
     printf("Message Received by rank%d:%s\n",rank,s);
 }
 else
 {
  MPI_Recv(s,sizeof(s),MPI_CHAR,0,1,MPI_COMM_WORLD,&status);
  printf("Message Received by rank%d:%s\n",rank,s);
  for(i=0;s[i]!='\0';i++)
      if(islower(s[i]))
      s[i]=toupper(s[i]);
      else
      s[i]=tolower(s[i]);
  MPI_Ssend(s,sizeof(s),MPI_CHAR,0,1,MPI_COMM_WORLD);
 }
 MPI_Finalize();
 return 0;
}
