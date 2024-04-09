#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

typedef struct 
{ int a,b,c;
  int ma,mb,mc;
  int na,nb,nc;
} process;

int s(int avail[],process p)
{ if(avail[0]>=p.na && avail[1]>=p.nb && avail[2]>=p.nc)
  return 1;

  return 0;
}

int safe(int finish[],process p[],int avail[])
{  int i,j;
   for(j=0;j<5;j++)
   for(i=0;i<5;i++)
   if(finish[i]==0 && s(avail,p[i]))
   { finish[i]=1;
     avail[0]+=p[i].a;
     avail[1]+=p[i].b;
     avail[2]+=p[i].c;
  
   }

  int k=0;
  for(i=0;i<5;i++)
  { if(finish[i]==0)
    k=1;
  }

 if(k==0)
 {printf("\nSystem is in Safe State ");
  return 1;}
 else
 printf("\nSystem is Deadlocked ");
 return 0;
}

int main()
{ process p[5];
  int avail[3];
  int a,b,c,i,j;
  
  printf("Enter available instances of resources A,B and C ");
  scanf("%d %d %d",&a,&b,&c);

  for(i=0;i<5;i++)
  {printf("Enter the allocated resources of A,B,C for process %d  ",i+1);
   scanf("%d %d %d",&p[i].a,&p[i].b,&p[i].c);
   }

  for(i=0;i<5;i++)
  {printf("Enter the requested resources of A,B,C for process %d  ",i+1);
   scanf("%d %d %d",&p[i].na,&p[i].nb,&p[i].nc);
   }

  avail[0]=a;
  avail[1]=b;
  avail[2]=c; 
   
  int finish[5]={0};
  safe(finish,p,avail);

  avail[0]=a;
  avail[1]=b;
  avail[2]=c;
  for(int k=0;k<5;k++)
  finish[k]=0;
  int t,ta,tb,tc;
  printf("\n\nEnter process no. which wants additiional resources ");
  scanf("%d",&t);
  printf("Enter no. of resourses of A,B,C wanted ");
  scanf("%d %d %d",&ta,&tb,&tc);
  p[t].na+=ta;
  p[t].nb+=tb;
  p[t].nc+=tc;
  safe(finish,p,avail);
  
}
