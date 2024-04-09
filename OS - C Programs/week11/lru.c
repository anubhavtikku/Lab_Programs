#include<stdio.h>
#include<stdlib.h>

int search(int b[],int m,int x,int r[])
{int i,j;

for(i=0;i<m;i++)
if(b[i]==x)
{r[i]=1;return i;}

return -1;
}

void fifo(int a[],int n,int b[],int m,int r[])
{ int pagehits=0;
 int pagemiss=0;
 int i,k,z,i2,j=0;
 
 printf("LRU SECOND CHANCE ");
 for(i=0;i<n;i++)
 { z=0;
   
   k=search(b,m,a[i],r);
   if(k==-1)
   pagemiss+=1;
   else
   pagehits+=1;
 
   if(k==-1)
   {for(i2=0;i2<m;i2++)
   if(b[i2]==-1)
   {b[i2]=a[i];r[i2]=1;z=1;break;}
   
   if(z==0)
  {
   for(i2=0;i2<m;i2++)
   {if(r[i2]==1)
    r[i2]=0;
    else 
    {b[i2]=a[i];r[i2]=1;z=1;}
      
    if(z==1)
    break;
    }

    if(i2==m)
    {b[0]=a[i];r[0]=1;}

  }

  } 

 }

printf("\nPage hits %d\n",pagehits);
printf("Page faults %d\n",pagemiss);
printf("Page cache consists of ");
for(i=0;i<m;i++)
printf("%d \t",b[i]);
}


int main()
{int a[100];
 int b[100],r[100];
 int n,i,m;
 
 for(i=0;i<100;i++)
 {b[i]=-1;r[i]=0;}
 
 printf("Enter no. of page accesses ");
 scanf("%d",&n);
 
 printf("Enter the page accesses ");
 for(i=0;i<n;i++)
 scanf("%d",&a[i]);
   
 printf("Enter length of page cache ");
 scanf("%d",&m);

 fifo(a,n,b,m,r);
 
}
