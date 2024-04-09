#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

int m1,n1,m2,n2,k=0;
int a[100][100],b[100][100],c[100][100];

void *mul(void *param)
{  if(n1!=m2)
   { k=1;
     printf("Dimensions not right ");
     return 0;
    }
  
  int i,j,l;
  
  for(i=0;i<m1;i++)
  for(j=0;j<n2;j++)
  c[i][j]=0;

  for(i=0;i<m1;i++)
  for(j=0;j<n2;j++)
  for(l=0;l<n1;l++)
  c[i][j]+=a[i][l]*b[l][j];
  printf("\n");

}

int main()
{ int i,j;
 
 printf("Enter dimensions of first matrix ");
 scanf("%d",&m1);
 scanf("%d",&n1);
 printf("\nEnter elements ");

 for(i=0;i<m1;i++)
 for(j=0;j<n1;j++)
 scanf("%d",&a[i][j]);
 
 printf("\nEnter dimensions of second matrix ");
 scanf("%d",&m2);
 scanf("%d",&n2);
 printf("\nEnter elements ");

 for(i=0;i<m2;i++)
 for(j=0;j<n2;j++)
 scanf("%d",&b[i][j]);

 pthread_t thread;
 pthread_create(&thread,0,&mul,0);
 pthread_join(thread,0);
 
 if(k==0)
 { for(i=0;i<m1;i++)
   {for(j=0;j<n2;j++)
   printf("%d \t",c[i][j]);
   printf("\n");
   } 
 }

 return 0;
}
