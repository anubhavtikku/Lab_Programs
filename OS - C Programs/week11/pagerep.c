#include<stdio.h>
#include<stdlib.h>

int search(int b[],int m,int x)
{int i;

for(i=0;i<m;i++)
if(b[i]==x)
return i;

return -1;
}

void fifo(int a[],int n,int b[],int m)
{ int pagehits=0;
 int pagemiss=0;
 int i,k,z,i2;
 
 printf("FIFO ");
 for(i=0;i<n;i++)
 { z=0;
   k=search(b,m,a[i]);
   if(k==-1)
   pagemiss+=1;
   else
   pagehits+=1;
   if(k==-1){ 
   for(i2=0;i2<m;i2++)
   if(b[i2]==-1)
   {b[i2]=a[i];
    z=1;
    break;
   }

   if(z==1)
   { int temp=b[0];
     for(i2=1;i2<m;i2++)
     b[i2-1]=b[i2];
     b[i2-1]=temp;
   }
   
   if(z==0)
   {int temp=a[i];
    for(i2=1;i2<m;i2++)
     b[i2-1]=b[i2];
     b[i2-1]=temp;
    }

   }
 }

printf("\nPage hits %d\n",pagehits);
printf("Page faults %d\n",pagemiss);
printf("Page cache consists of ");
for(i=0;i<m;i++)
printf("%d \t",b[i]);
}

void lru(int a[],int n,int b[],int m)
{int pagehits=0;
 int pagemiss=0;
 int i,k,z,i2;
 printf("LRU");

 for(i=0;i<n;i++)
 { z=0;
   k=search(b,m,a[i]);
   if(k==-1)
   pagemiss+=1;
   else
   pagehits+=1;
   if(k==-1){ 
   for(i2=0;i2<m;i2++)
   if(b[i2]==-1)
   {b[i2]=a[i];
    z=1;
    break;
   }

   if(z==1)
   { int temp=b[0];
     for(i2=1;i2<m;i2++)
     b[i2-1]=b[i2];
     b[i2-1]=temp;
   }
   
   if(z==0)
   {int temp=a[i];
    for(i2=1;i2<m;i2++)
     b[i2-1]=b[i2];
     b[i2-1]=temp;
    }
  }
 else
   {int temp=b[k];
    for(i2=k;i2<m-1;i2++)
     b[i2]=b[i2+1];
     b[m-1]=temp;  
   }

 }

printf("\nPage hits %d\n",pagehits);
printf("Page faults %d\n",pagemiss);
printf("Page cache consists of ");
for(i=0;i<m;i++)
printf("%d \t",b[i]);

}

int opt(int a[],int n,int b[],int m,int i)
{ int j1,j2;
  int count,min=0,pos;
  for(j1=0;j1<m;j1++)
  { count=0;
    for(j2=i+1;j2<n;j2++)
    {count++;
     if(a[j2]==b[j1])
     break;
    if(j2==n-1)
     count++;
    }
    
    if(count>min)
    {min=count;
     pos=j1;
    }
  }

return pos;
}

void optimal(int a[],int n,int b[],int m)
{int pagehits=0;
 int pagemiss=0;
 int i,k,z,i2,j;

 printf("Optimal");

for(i=0;i<n;i++)
{z=0;
 k=search(b,m,a[i]);
 if(k==-1)
 pagemiss+=1;
 else
 pagehits+=1;
 if(k==-1){
 for(i2=0;i2<m;i2++)
  if(b[i2]==-1)
  {b[i2]=a[i];
   z=1;
   break;
  }
 
 if(z==0)
 {
  b[j]=a[i];
 }

}

 j=opt(a,n,b,m,i);
}

printf("\nPage hits %d\n",pagehits);
printf("Page faults %d\n",pagemiss);
printf("Page cache consists of ");
for(i=0;i<m;i++)
printf("%d \t",b[i]);
 
}

int main()
{int a[100];
 int b[100];
 int n,i,m,x=0;
 
 for(i=0;i<100;i++)
 b[i]=-1;
 
 printf("Enter no. of page accesses ");
 scanf("%d",&n);
 
 printf("Enter the page accesses ");
 for(i=0;i<n;i++)
 scanf("%d",&a[i]);
   
 printf("Enter length of page cache ");
 scanf("%d",&m);

 printf("\nEnter 1.FIFO 2.LRU 3.OPTIMAL ");
 scanf("%d",&x);
 if(x==1)
 fifo(a,n,b,m);
 else if(x==2)
 lru(a,n,b,m);
 else
 optimal(a,n,b,m);
}
