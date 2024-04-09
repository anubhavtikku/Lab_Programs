#include <stdio.h>
struct stack
{char a[10];
 int top;
};

void push(char ch,struct stack *s)
{ if(s->top==9)
	{ printf("Stack is full");
	  return ;}
  else
  	{  s->top=s->top +1;
  	   s->a[s->top]=ch;
  	}

}

void pop(struct stack *s)
{ if(s->top==-1)
	{ printf("Stack is empty ");
     }
  else
  	s->top=s->top-1;
}

void display(struct stack *s)
{  int i;
	for(i=0;i<=s->top;i++)
		printf("%c",s->a[i]);
    }

 int main()
 { struct stack s;
   char a[100],b;
   int i,x=0;
   s.top=-1;
   printf("Enter string ");
   gets(a);
   for(i=0;a[i]!='\0';i++)
   	push(a[i],&s);

   for(i=0;a[i]!='\0';i++)
   	{  b=s.a[s.top];
   	   pop(&s);
       if(b!=a[i])
       {x=1;
        break;}
          }

    

 if(x==0)
 printf("Palindrome ");
 else
 printf("Not palindrome ");
 }

