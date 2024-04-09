#include <stdio.h>

int count=0;

int toh(int n,char s,char d,char t);

int main()
{int n;
 char s='A',t='B',d='C';
 printf("Enter no. of disks ");
 scanf("%d",&n);
 toh(n,s,d,t);
 printf("No. of Moves are %d",count);
 return 0;
  }

int toh(int n,char s,char d,char t)
{ if(n>0)
    { toh(n-1,s,t,d);
      printf("Moving disk %d from %c to %c",n,s,d);
      count++;
      printf("\n");
      toh(n-1,t,d,s);
       }  
   return 0;
  } 