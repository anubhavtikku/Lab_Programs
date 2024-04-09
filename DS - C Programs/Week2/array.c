#include <stdio.h>

int main()
{ int a[10],n,i;
	int *x=&a[0];
  printf("Enter size of array "); 
  scanf("%d",&n);
  printf("Enter elements of array ");
  
  for(i=0;i<n;i++)
  scanf("%d",&a[i]);
  
  printf("\nForward \t");
   fr(x,n);
   printf("\nBackward \t");
   br(x,n);
  return 0;
  }

  int fr(int *x,int n)
  { int i;
    for(i=0;i<n;i++)
    	printf("%d\t",*(x+i));

  }

 int br(int *x,int n)
  { int i;
    for(i=n-1;i>=0;i--)
    	printf("%d\t",*(x+i));

  }

