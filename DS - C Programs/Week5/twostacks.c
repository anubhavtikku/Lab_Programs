#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct stack
{ char a[10];
  int top1;
  int top2;
  };

 void push(char item,struct stack *s,int x)
 {  if(x==0)
  {
 	if(s->top1+1==s->top2)
   {printf("Stack is full");
   return;
   }
   else
   	{ printf("Push %c\n",item);
   	  s->top1=s->top1+1;
   	  s->a[s->top1]=item; 
  }
  }

   if(x==1)
  {
 	if(s->top2==s->top1+1)
   {printf("Stack is full");
   return;
   }
   else
   	{ printf("Push %c\n",item);
   	  s->top2=s->top2-1;
   	  s->a[s->top2]=item; 
  }
  }

}

  void pop(struct stack *s,int x)
  { 
      if(x==0)
  	{if(s->top1==-1)
  	{printf("Stack is empty ");
    return;
    }
    else
    printf("Pop %c \n",s->a[s->top1]);
     s->top1=s->top1-1; 
    }

    if(x==1)
  	{if(s->top2==10)
  	{printf("Stack is empty ");
    return;
    }
    else
    printf("Pop %c \n",s->a[s->top2]);
     s->top2=s->top2+1; 
    }
  }

  void display(struct stack *s,int x)
  { int i;
  	if(x==0)
  	{ 	i=0;
  	printf("Stack%d is ",x+1);
    for(i=0;i<=s->top1;i++)
    printf("%c \t",s->a[i]);
    }
    if(x==1)
    	{ 	i=0;
  	printf("Stack%d is ",x+1);
    for(i=9;i>=s->top2;i--)
    printf("%c \t",s->a[i]);
    }
 }

  void main()
  {struct stack s;
   int i,x;
   s.top1=-1;
   s.top2=10;
   push('A',&s,0);
   push('B',&s,0);
   push('C',&s,1);
   display(&s,0);
   display(&s,1);
  }