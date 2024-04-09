#include<stdio.h>
#include<stdlib.h>

int main()
{int p,ps,pn,o,la,i;
 printf("Enter total no. of pages ");
 scanf("%d",&p);
 printf("Enter page size of each page ");
 scanf("%d",&ps);
 printf("Enter logical address ");
 scanf("%d",&la);
 pn=la/ps;
 o=la%ps;
 if(pn>p)
 printf("Page fault ");
 else
 printf("\nPage no. %d and Offset %d ",pn,o);
}
