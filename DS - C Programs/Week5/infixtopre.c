#define Max 100
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
typedef struct 
{
	char item[Max];
	int top;
}stack;

void init(stack *);
int  empty(stack *);
int full(stack *);
char pop(stack *);
void push(stack *s,char);
char top1(stack *s);
int priority(char x);

void init(stack *s)
{
	s->top=-1;
}
char top1(stack *s)
{
	return(s->item[s->top]);
}
int  empty(stack *s)
{
	if(s->top==-1)
	  return 1;
	 return 0;
}
int full(stack *s)
{
  if(s->top==Max-1)
	return 1;
  return 0;
}
char pop(stack *s)
{
	char v;
	v=s->item[s->top];
	s->top=s->top-1;
	return(v);
}
void push(stack *s,char c)
{
	s->top=s->top+1;
	s->item[s->top]=c;
}
int priority(char x)
{
  if(x==')')
  	 return 0;
  if(x=='+'||x=='-')
  	 return 1;
  if(x=='*'||x=='/'||x=='%')
  	return 2;
  if(x=='^')
  return 3;
return 4;
}
void main()
{
	stack s;
	char x[100],y[100];
	int k=0;
	char token,t;
	int i;
	init(&s);
	printf("enter infix expression");
	scanf("%s",x);
	int c=strlen(x);
	for(i=c;i>=0;i--)
	{   
		if(isalnum(x[i]))
			y[k++]=x[i];
	    else 
	    	if(x[i]==')')
				push(&s,')');
			else
			{
				if(x[i]=='(')
					while((t=pop(&s))!=')')
						y[k++]=t;
		        else
		        {
		    	      while(!empty(&s) && priority(x[i])<priority(top1(&s)))
		    	       {
		    		        t=pop(&s);
		    	 	        y[k++]=t;
		    	       }
		    	       push(&s,x[i]);
		        }
			}
	}
	while(!empty(&s))
	{
		t=pop(&s);
		y[k++]=t;
	}
	int p=strlen(y);
	for(i=p-1;i>=0;i--)
	    printf("%c",y[i]);
	printf("\n");
}