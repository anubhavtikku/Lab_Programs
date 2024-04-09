#include <stdio.h>
#include <stdlib.h>

struct edge
{int a,b,w;
};

int find(int a[],int i)
{ return a[i];
}

void unio(int a[],int f1,int f2,int e)
{int i;
 for(i=0;i<e;i++)
 if(a[i]==f2)
 a[i]=f1;

}

int main()
{int a[100];
 int v,e,i,j,n=0;
 int w=0;

 struct edge p[10];
 struct edge temp; 

 int u[10]={0};

 printf("Enter no. of vertices ");
 scanf("%d",&v);
 
 printf("Enter no. of edges ");
 scanf("%d",&e);
 
 printf("\nEnter edges with their weights \n");
 for(i=0;i<e;i++)
 scanf("%d %d %d",&p[i].a,&p[i].b,&p[i].w);

 for(i=0;i<e;i++)
 a[i]=i;

 for(i=0;i<e;i++)
 for(j=0;j<e-i-1;j++)
 if(p[j].w>p[j+1].w)
 {temp=p[j];
  p[j]=p[j+1];
  p[j+1]=temp;
 }
 
 for(i=0;i<e;i++)
 { int f1=find(a,p[i].a);
   int f2=find(a,p[i].b);
   
   if(f1!=f2)
   {
    u[i]=1;
    unio(a,f1,f2,e);
    w+=p[i].w;
   }
  
 }

 printf("\nKrushkal's algo\n");
 printf("\nEdges used with their weights in min spanning tree \n");
 for(i=0;i<e;i++)
  if(u[i]==1)
  printf("\nVertex %d , Vertex %d , Edge Weight %d\n",p[i].a,p[i].b,p[i].w);
  
 printf("\nMax weight of tree is %d",w);
}
