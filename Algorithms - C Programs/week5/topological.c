#include<stdio.h>
#include<stdlib.h>

int a[10][10];
int v[10];
int k1=0,k2=0;
int pu[10];
int po[10];
int n;
void dfs(int );


int main()
{ printf("Enter no. of vertices ");
  scanf("%d",&n);

  int i,j;
  printf("Enter Adjacency Matrix\n");
  for(i=0;i<n;i++)
  for(j=0;j<n;j++)
  scanf("%d",&a[i][j]);
  
  for(i=0;i<n;i++)
  v[i]=0;

  dfs(0);
  
  printf("\n\nPush order ");
  for(i=0;i<n;i++)
  printf("%d\t",pu[i]+1);
  
  printf("\nPop order ");
  for(i=0;i<n;i++)
  printf("%d\t",po[i]+1);
  
  printf("\nTopological sorting order ");
  for(i=n-1;i>=0;i--)
  printf("%d\t",po[i]+1);

}

void dfs(int i)
{ int j;
  
  printf("\n%d",i+1);
  pu[k1++]=i;
  v[i]=1;
  
  for(j=0;j<n;j++)
  if(v[j]==0 && a[i][j]==1)
  dfs(j);
  po[k2++]=i;
}


