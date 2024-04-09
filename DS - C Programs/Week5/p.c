#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

  int a[10];
  int top;

 void push(int item)
 { if(top==9)
    { printf("Stack is full ");
      return;
     }
    top=top+1;
    a[top]=item;
   }

 void pop()
 { if(top==-1)
    { printf("Stack is empty ");
      return;
     }
 
    top=top-1;
 }

 void oper(char i)
 { int x,y;
   x=a[top];
   
   top--;
   y=a[top];
   top--;
  
   if(i=='+')
   	x=x+y;
   if(i=='-')
   	x=y-x;
   if(i=='*')
   	x=x*y;
   if(i=='/')
   	x=y/x;
   
   push(x);
   
 }
 
 void main()
 { 
 	  top=-1;
    char b[20];
    int i;
    printf("Enter prefix expression ");
    scanf("%s",b);
    for(i=strlen(b)-1;i>=0;i--)
    { if(isdigit(b[i]))
        {int z;
         z=(int )b[i];   
         push(z-48);
         }
       else
         oper(b[i]);
      }

   for(i=0;i<=top;i++)
   printf("Expression is %d",a[i]);
  }
