#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

  char a[10][10];
  int k=-1;

 
 
 int isnoop(char x)
 {
    if(x=='+'||x=='-'||x=='*'||x=='/')
      return 1;
    return 0;
 }

 void opf(char b)
{ char t1[100],t2[100],t3[10],t4[10],t5[10];
  t3[0]='(';
  t3[1]='\0';
  t4[0]=b;
  t4[1]='\0';
  t5[0]=')';
  t5[1]='\0';

  strcpy(t1,a[k--]);
  strcpy(t2,a[k--]);
  strcat(t3,t2);
  strcat(t3,t4);
  strcat(t3,t1);
  strcat(t3,t5);
  strcpy(a[++k],t3);
}
 
 void main()
 { 
 	
    char b[20],c[20];
    int i,x;
    printf("Enter postfix expression ");
    scanf("%s",b);
     x=strlen(b);
     for(i=0;i<x;i++)
     {  if(isnoop(b[i]))
         opf(b[i]);
        else
          {c[0]=b[i];
          c[1]='\0';
          strcpy(a[++k],c);
        }
       }
   for(i=0;i<=k;i++)
   printf("%s",a[i]);
 }