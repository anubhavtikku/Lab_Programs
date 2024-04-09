#include<stdio.h>
#include<stdlib.h>

void fcfs(int a[],int n,int length,int point)
{ int i,sum=0,dif;
  int seek=point;
  for(i=0;i<n;i++)
  {dif=seek-a[i];
   if(dif<0)
   dif=dif*(-1);
   sum+=dif;
   seek=a[i];
  }

  printf("\nTotal movement for FCFS is %d\n",sum);
}

void sort(int a[],int n)
{int i,j,temp;
 for(i=0;i<n;i++)
 for(j=0;j<n-1-i;j++)
 if(a[j]>a[j+1])
 {temp=a[j];
  a[j]=a[j+1];
  a[j+1]=temp;
 }

}


void sstf(int a[],int n,int length,int point)
{ int i,sum=0,dif,k=-1;
  sort(a,n);
  int seek=point;
  while(n>0)
{ k=-1;
  for(i=0;i<n;i++)
  if(a[i]>seek)
  {k=i;break;}

  if(k==-1)
  {sum+=seek-a[0];seek=a[0];n=0;}

  else if(k==0)
  { 
    sum+=a[n-1]-seek;seek=a[n-1];n=0;
  }

  else
  {
     int d1=a[k]-seek;
     int d2=seek-a[k-1];
   
     if(d1<d2)
     {sum+=d1;
      seek=a[k];
      a[k]=-1;
     }
     else
     {sum+=d2;
      seek=a[k-1];
      a[k-1]=-1;
     }

     sort(a,n);
     for(i=1;i<n;i++)
     a[i-1]=a[i];
     n=n-1;
  }
  
}
  printf("\nTotal movement for SSTF is %d\n",sum);
}

void scan(int a[],int n,int length,int point)
{ int i,sum=0,dif,k=-1;
  sort(a,n);
  int seek=point;

  for(i=0;i<n;i++)
  if(a[i] > seek)
  {k=i;break;}

   if(k==-1)
  {
   sum+=seek-a[0]+(length-seek)*2;
   seek=a[0];
   }

  else if(k==0)
  { 
    sum+=a[n-1]-seek;seek=a[n-1];
  }
 
  else
  {
    sum+=a[n-1]-seek;
    sum+=(length-a[n-1])*2+a[n-1]-a[0];
    seek=a[0];
    
  }
 
  printf("\nTotal movement for SCAN is %d\n",sum);
}

void cscan(int a[],int n,int length,int point)
{ int i,sum=0,dif,k=-1;
  sort(a,n);
  int seek=point;
  

  for(i=0;i<n;i++)
  if(a[i] > seek)
  {k=i;break;}

   if(k==-1)
  {sum+=length-seek;
   sum+=a[n-1];
   seek=a[n-1];
   }

  else if(k==0)
  { 
    sum+=a[n-1]-seek;seek=a[n-1];
  }
 
  else
  {
    sum+=length-seek;
    sum+=a[k-1];
    seek=a[k-1];
  }
 
  printf("\nTotal movement for CSCAN is %d\n",sum);
}


int main()
{int n,i,length,point;
 int a[100];
 int b[100],c[100],d[100],e[100];

 printf("Enter total cylinder length ");
 scanf("%d",&length);

 printf("Enter the read/write head ");
 scanf("%d",&point);

 printf("Enter the no. of tracks to enter ");
 scanf("%d",&n);

 printf("Enter the track numbers ");
 for(i=0;i<n;i++)
 {scanf("%d",&a[i]);
  b[i]=c[i]=d[i]=e[i]=a[i];
  }


 fcfs(a,n,length-1,point);
 sstf(b,n,length-1,point);
 scan(c,n,length-1,point);
 cscan(d,n,length-1,point);

}
