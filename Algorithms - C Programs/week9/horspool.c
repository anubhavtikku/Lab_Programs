#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void shifttable(char p[],int a[])
{ int i,j;
  int size=strlen(p);
  
  for(i=0;i<255;i++)
  a[i]=size;
  
  for(i=0;i<size;i++)
  a[p[i]]=size-i-1;
}


int main()
{ int i,j,k;
  int z=0,op=0;
  char p[80],t[80];
  int a[255];
  printf("Enter text ");
  gets(t);
  printf("Enter pattern to be searched in text ");
  gets(p);
  shifttable(p,a);
  int m=strlen(p);
  int n=strlen(t);
  
  i=m-1;
  while(i<=n-1)
  {k=0;op++;
   while(k<=m-1 && p[m-1-k]==t[i-k])
   {k++;op++;}
   if(k==m)
    {z=i-m+1;
     break;
    }
   else
   i+=a[t[i]];
   op++; 
  }

 if(z==0)
  printf("\nPattern not found ");
 else
  printf("\nPattern found at index %d",z);
  printf("\nOpcode is %d",op); 
}
