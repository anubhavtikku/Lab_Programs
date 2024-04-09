#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct node
{ char data;
  struct node *lc;
  struct node *rc;
 }Node;

Node *a[10];
int top=-1;

Node* createexptree(char postfix[])
{   int i=0;
	Node *newnode;
    while(postfix[i]!='\0')
    {       newnode=(Node *)malloc(sizeof(Node));
         	newnode->lc= newnode->rc=NULL;
         	newnode->data=postfix[i];

    	if(isalpha(postfix[i])||isdigit(postfix[i]))
         {  
         	a[++top]=newnode;
         	}
       else
       { 
         newnode->rc=a[top--];
         newnode->lc=a[top--];   	
         a[++top]=newnode;
       }
       i++;
    }
    return newnode;
}

float perform(char op,int op1,int op2)
{ 
   switch(op)
   { case '+':return op1 + op2;
     break;

     case '-':return op1 - op2;
     break;
     
     case '*':return op1*op2;
     break;

     case '/':return op1/op2;
     break;
   }

   return 0;
} 

float evaluate(Node *rt)
{  float a,b,c;
   if(rt==NULL)
	return 0;

  if(isdigit(rt->data))
  	return((float)rt->data-'0');

  if(isalpha(rt->data))
  { 
  	printf("Enter a value for %c",rt->data);
    scanf("%f",&c);
    return c;
  }

  a=evaluate(rt->lc);
  b=evaluate(rt->rc);
  return perform(rt->data,a,b); 

}

int main()
{ 
  char p[20];
  printf("Enter postfix expression ");
  scanf("%s",p);
  Node *rt=createexptree(p);
  float f;
  f=evaluate(rt);
  printf("%f",f);
}