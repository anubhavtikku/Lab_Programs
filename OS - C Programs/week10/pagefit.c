#include<stdio.h>
#include<stdlib.h>

int firstfit(int a[],int *n1,int a1[],int p[],int *nw)
{ int i,j,k,z=1,l=0,i1;
  for(i=0;i<*nw;i++)
  {  k=p[i];

     for(j=0;j<*n1;j++)
     {   l=0;
         if(a[j]>=k && a1[j]!=1)
         {
           for(i1=*n1;i1>j;i1--)
           {a[i1]=a[i1-1];
            a1[i1]=a1[i1-1];
           }
           *n1=*n1 +1;
           a[j]=k;
           a[j+1]-=k;
           a1[j]=1;
           l=1;
         }
         if(l==1)
         break;
        
     }
     if(l==0)
        return 1;
     
  }
 return 0;
}

int bestfit(int b[],int *n2,int b1[],int p[],int *nw)
{ int i,k,i1;
  int d,nd,j7;
  for(i=0;i<*nw;i++)
  {  k=p[i];
     d=30000,nd=-1;
     for(j7=0;j7<*n2;j7++)
        { if(b[j7]>=k && b1[j7]!=1 && b[j7]-k<d)
           { d=b[j7]-k;
             nd=j7;
           }
         }
    
    if(nd==-1)
    return 1;
    
    for(i1=*n2;i1>nd;i1--)
    {b[i1]=b[i1-1];
     b1[i1]=b1[i1-1];
    }
    *n2=*n2 +1;
     b[nd]=k;
     b[nd+1]-=k;
     b1[nd]=1;
    }   
  
}

int worstfit(int c[],int *n3,int c1[],int p[],int *nw)
{ int i,k,i1;
  int d,nd,j7;
  for(i=0;i<*nw;i++)
  {  k=p[i];
     d=-1,nd=-1;
     for(j7=0;j7<*n3;j7++)
        { if(c[j7]>=k && c1[j7]!=1 && c[j7]-k>d)
           { d=c[j7]-k;
             nd=j7;
           }
         }
    
    if(nd==-1)
    return 1;
    
    for(i1=*n3;i1>nd;i1--)
    {c[i1]=c[i1-1];
     c1[i1]=c1[i1-1];
    }
    *n3=*n3 +1;
     c[nd]=k;
     c[nd+1]-=k;
     c1[nd]=1;
  }

}

int main()
{int a[100],b[100],c[100],d[100],a1[100]={0},b1[100]={0},c1[100]={0};
 int p[100];
 int i,k;
 int *n=(int *)malloc(sizeof(int *));
 int *nw=(int *)malloc(sizeof(int *));
 printf("Enter no. of memory partitions ");
 scanf("%d",n);
 printf("Enter the size of memory partitions ");
 for(i=0;i<*n;i++)
 scanf("%d",&a[i]);
 int *n1=(int *)malloc(sizeof(int *));
 int *n2=(int *)malloc(sizeof(int *));
 int *n3=(int *)malloc(sizeof(int *));
 *n1=*n2=*n3=*n;
 for(i=0;i<*n;i++)
 {b[i]=a[i];
  c[i]=a[i];
  d[i]=a[i];}
 printf("Enter the no. of processes ");
 scanf("%d",nw);
 printf("Enter the size of processes ");
 for(i=0;i<*nw;i++)
 scanf("%d",&p[i]);
 
 int r1,r2,r3;
 r1=firstfit(a,n1,a1,p,nw);
 if(r1==1)
 {printf("\nFirst fit is not possible\n");}
 else
 {printf("\nFirst fit\n");
  printf("Memory\tUsed/Free\n");
  for(i=0;i<*n1;i++)
  printf("\n%d\t\t%d",a[i],a1[i]);
 }
 r2=bestfit(b,n2,b1,p,nw);
 if(r2==1)
 {printf("\nBest fit is not possible\n");}
 else
 {printf("\n\nBest fit\n");
  printf("Memory\tUsed/Free\n");
  for(i=0;i<*n2;i++)
  printf("\n%d\t\t%d",b[i],b1[i]);
 }
 r3=worstfit(c,n3,c1,p,nw);
 if(r3==1)
 {printf("\n\nWorst fit is not possible");}
 else
 {printf("\n\nWorst fit\n");
  printf("Memory\tUsed/Free\n");
  for(i=0;i<*n3;i++)
  printf("\n%d\t\t%d",c[i],c1[i]);
 }

}

