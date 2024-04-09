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
 {printf("\nSafe state ");
  return 1;}
 else
 printf("\nNot in a safe state ");
 return 0;
}

int main()
{ process p[5];
  int a,b,c,i,j;
  printf("Enter no. of instances of resources A,B and C ");
  scanf("%d %d %d",&a,&b,&c);
  int avail[3];
  for(i=0;i<5;i++)
  {printf("Enter the allocated resources of A,B,C for process %d  ",i+1);
   scanf("%d %d %d",&p[i].a,&p[i].b,&p[i].c);
   }

  for(i=0;i<5;i++)
  {printf("Enter the max resources of A,B,C for process %d  ",i+1);
   scanf("%d %d %d",&p[i].ma,&p[i].mb,&p[i].mc);
   }

  int t1=0,t2=0,t3=0;
  for(i=0;i<5;i++)
  { t1+=p[i].a;
    t2+=p[i].b;
    t3+=p[i].c;
  }

  if(t1>a || t2>b || t3>c)
  {printf("Not enough resources available to be allocated ");
   exit(EXIT_SUCCESS);
  }
  else
  {avail[0]=a-t1;
   avail[1]=b-t2;
   avail[2]=c-t3;
  }

  printf("\nNeed matrix\n");
  for(i=0;i<5;i++)
  {p[i].na=p[i].ma-p[i].a;
   p[i].nb=p[i].mb-p[i].b;
   p[i].nc=p[i].mc-p[i].c;
   printf("%d\t%d\t%d\n",p[i].na,p[i].nb,p[i].nc);
  }
  
  int finish[5]={0};
  safe(finish,p,avail);

  
  avail[0]=a-t1;
  avail[1]=b-t2;
  avail[2]=c-t3; 
  
  for(int k=0;k<5;k++)
  finish[k]=0;
  
  int t,ta,tb,tc;
  printf("\n\nEnter process no. which requests more resources ");
  scanf("%d",&t);

  printf("\nEnter requested resources of A,B,C ");
  scanf("%d %d %d",&ta,&tb,&tc);
  
  if(avail[0]<ta || avail[1]<tb || avail[2]<tc || p[1].na<ta  || p[1].nb<tb || p[1].nc<tc )
  { printf("Allocation not possible ");
   }

 else
 { avail[0]-=ta;
   avail[1]-=tb;
   avail[2]-=tc;
   p[t].na-=ta;
   p[t].nb-=tb;
   p[t].nc-=tc;
   p[t].a+=ta;
   p[t].b+=tb;
   p[t].c+=tc;
   int s=safe(finish,p,avail);
   if(s==0)
   printf("Allocation not possible ");
   else
   printf("Allocation possible ");
   p[t].na+=ta;
   p[t].nb+=tb;
   p[t].nc+=tc;
   p[t].a-=ta;
   p[t].b-=tb;
   p[t].c-=tc;
 } 
 
}

