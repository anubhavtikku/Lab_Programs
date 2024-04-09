#include <stdio.h>

int l(char a[10]);

int main()
{ char a[10];
  int i;
  printf("Enter string ");
  gets(a);
  i=l(a);
  printf("The length is %d",i);
  return 0;
  }

 int l(char a[10])
 { static int i=0;
    if(a[i]=='\0')
    return i;

   i++;
   l(a);
 }