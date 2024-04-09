#include <stdio.h>

int st(char a[10],char b[10]);

int main()
{ char a[10],b[10];
  printf("Enter string ");
  gets(a);
  st(a,b);
  printf("Copied String is %s",b);
  return 0;
  }

int st(char a[10],char b[10])
{ static int i=0;
  if(a[i]=='\0')
  	return 0;
  b[i]=a[i];
  i++;
  st(a,b);
   }  