#include<stdio.h>
#include<stdlib.h>

int comp(const void * l, const void * r)
{ int a=*(int *)l;
  int b=*(int *)r;
  
  return a-b;
}

void subset(int s[],int n,int inc[],int total,int k,int sum)
{
    
    if(total==sum)
      { int i;
        printf("\nSubset is \t");
        for(i=0;i<n;i++)
        if(inc[i]==1)
        printf("%d\t",s[i]);
        printf("\n");
      }

   if(total<=sum && k<n)
   { 
  
        inc[k]=1;
        subset(s,n,inc,total+s[k],k+1,sum);
        if(total<sum)
        {inc[k]=0;
         subset(s,n,inc,total,k+1,sum);
        }
   }

}

int main()
{int s[50];
int inc[50];
int n,i;
int sum;

printf("Enter no. of elements in set ");
scanf("%d",&n);

printf("Enter elements ");
for(i=0;i<n;i++)
scanf("%d",&s[i]);

qsort(s,n-1,sizeof(int),comp);


printf("Enter subset sum ");
scanf("%d",&sum);

for(i=0;i<50;i++)
inc[i]=0;

subset(s,n,inc,0,0,sum);
}
