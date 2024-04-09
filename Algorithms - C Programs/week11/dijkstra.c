#include <stdio.h>
#include <stdlib.h>

# define MAX 1<<15

int mindist(int s[],int d[],int v)
{ int min=MAX,pos=0,i;
  
  for(i=0;i<v;i++)
  { if(d[i]<=min && s[i]==0)
      {min=d[i];pos=i;
      }
  }

 return pos;
}



void dijkstra(int a[100][100],int v,int s[],int d[])
{ int i,j,k;

  for(i=0;i<v;i++)
  { 
      j=mindist(s,d,v);
      s[j]=1;
    
      for(k=0;k<v;k++)
      if(a[j][k]&&(d[k]>d[j]+a[j][k])&&s[k]==0&&d[j]!=MAX)  
      d[k]=d[j]+a[j][k]; 
  }


}

int main()
{int s[100];
 int d[100];
 int v,e,i,j,n=0;
 int b,c,f,x;
 int w=0;
 
 for(i=0;i<100;i++)
 {s[i]=0;d[i]=MAX;}

 int a[100][100]={0}; 

 
 printf("Enter no. of vertices ");
 scanf("%d",&v);
 
 printf("Enter no. of edges ");
 scanf("%d",&e);
 
 printf("\nEnter edges with their weights \n");
 for(i=0;i<e;i++)
 {scanf("%d %d %d",&b,&c,&f);a[b-1][c-1]=a[c-1][b-1]=f;}

 printf("\nEnter source\n");
 scanf("%d",&x);
 
 d[x-1]=0; 
 
 dijkstra(a,v,s,d);

 for(i=0;i<v;i++)
 printf("\nVertex %d  Distance %d\n",i,d[i]);
}
