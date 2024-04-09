#include<stdio.h>
#include<stdlib.h>

struct process
{ int processid;
  int arrtime;
  int bursttime;
  int priority;
  int rt;
  int f;
};

struct grantchart
{int processid;
 int starttime;
 int endtime;
 int tat;
 int wt;
};

void fcfs(struct process p[],int n,struct grantchart g[],int gg[])
{
 int i,j;
 struct process temp;
 for(i=0;i<n;i++)
 for(j=0;j<n-1-i;j++)
 { if(p[j].arrtime>p[j+1].arrtime)
   {temp=p[j];
    p[j]=p[j+1];
    p[j+1]=temp;
   }
 }

 int k=0;
 for(i=0;i<n;i++)
 {  g[i].processid=p[i].processid;
    g[i].starttime=p[i].arrtime;
    g[i].endtime=k+p[i].bursttime;
    g[i].tat=g[i].endtime-g[i].starttime;
    g[i].wt=g[i].tat-p[i].bursttime;
    k+=p[i].bursttime;
 }

 printf("FCFS\n");
 printf("Process\tArrivial time\tBurst time\tPriority\tTAT\tWT\n");
 for(i=0;i<n;i++)
 {
  printf("%d\t%d\t\t%d\t\t%d\t\t%d\t%d\n",p[i].processid,p[i].arrtime,p[i].bursttime,p[i].priority,g[i].tat,g[i].wt);
 }
 
}

void rb(struct process p[],int n,struct grantchart g[],int gg[])
{ int q=10;
  int i,k=0;
  for(i=0;i<n;i++)
  {p[i].f=0;p[i].rt=p[i].bursttime;}
  
  while(1)
  { for(i=0;i<n;i++)
     { if(p[i].f==0 && p[i].arrtime<k)
       {             
           if(p[i].rt>q)
           {p[i].rt=p[i].rt-q;
            k=k+q;
           }
           else
          {k=k+p[i].rt;
           p[i].rt=0;
           p[i].f=1;
           g[i].processid=p[i].processid;
           g[i].starttime=p[i].arrtime;
           g[i].endtime=k;
           g[i].tat=g[i].endtime-g[i].starttime;
           g[i].wt=g[i].tat-p[i].bursttime;
          }   
                
       } 
     }
     int t=1;
     for(i=0;i<n;i++)
     if(p[i].f==0)
     t=0;

     if(t==1)
     break;
  }

 printf("Round Robin\n");
 printf("Process\tArrivial time\tBurst time\tPriority\tTAT\tWT\n");
 for(i=0;i<n;i++)
 {
  printf("%d\t%d\t\t%d\t\t%d\t\t%d\t%d\n",p[i].processid,p[i].arrtime,p[i].bursttime,p[i].priority,g[i].tat,g[i].wt);
 }
 
}

void srtf(struct process p[],int n,struct grantchart g[],int gg[])
{int i,j;
 struct process temp;
 for(i=0;i<n;i++)
 for(j=0;j<n-1-i;j++)
 { if(p[j].arrtime>p[j+1].arrtime)
   {temp=p[j];
    p[j]=p[j+1];
    p[j+1]=temp;
   }
 }

 for(i=0;i<n;i++)
 for(j=0;j<n-1-i;j++)
 { if(p[j].bursttime>p[j+1].bursttime && p[j].arrtime==p[j+1].arrtime)
   {temp=p[j];
    p[j]=p[j+1];
    p[j+1]=temp;
   }
 }

 for(i=0;i<n;i++)
  {p[i].rt=p[i].bursttime;p[i].f=0;}
 
 struct process pf[5];
 int k=0,s=0;
 i=0; 
 while(n!=0)
{ 

 if(p[i].arrtime<=k)
 {
    p[i].rt-=1;
    k+=1;
 }
 else
 {  int y=0;
    while(p[i].arrtime>k && y!=n)
      {i=(i+1)%n;y++;}
    if(y!=n)
    p[i].rt-=1;
    k=k+1;
 }
  

 if(p[i].rt==0)
 { pf[s]=p[i];
   g[s].processid=p[i].processid;
   g[s].starttime=p[i].arrtime;
   g[s].endtime=k;
   g[s].tat=g[s].endtime-g[s].starttime;
   g[s].wt=g[s].tat-p[i].bursttime;

   for(int z=i;z<n-1;z++)
   p[z]=p[z+1];
   n=n-1;
   s=s+1;
 }

 for(i=0;i<n;i++)
 for(j=0;j<n-1-i;j++)
 { if(p[j].rt>p[j+1].rt)
   {temp=p[j];
    p[j]=p[j+1];
    p[j+1]=temp;
   }
 }
 i=0;
}

 printf("SRTF\n");
 printf("Process\tArrivial time\tBurst time\tPriority\tTAT\tWT\n");
 for(i=0;i<s;i++)
 {
  printf("%d\t%d\t\t%d\t\t%d\t\t%d\t%d\n",pf[i].processid,pf[i].arrtime,pf[i].bursttime,pf[i].priority,g[i].tat,g[i].wt);
 } 
  
}

int main()
{

 struct process p[]={{1,0,60,3},{2,3,30,2},{3,4,40,1},{4,9,10,4}};
 struct grantchart g[4];
 int gg[1000];
 int i,j,n=4;

 fcfs(p,4,g,gg);
 //rb(p,4,g,gg);
  // srtf(p,4,g,gg);
}

