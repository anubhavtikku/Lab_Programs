# include <stdio.h>
struct stack
{ char a[10];
  int top;
  };

 void push(char item,struct stack *s)
 { if(s->top==9)
   {printf("Stack is full");
   return;
   }
   else
   	{ printf("Push %c\n",item);
   	  s->top=s->top+1;
   	  s->a[s->top]=item; 
  }
}

  void pop(struct stack *s)
  { if(s->top==-1)
  	{printf("Stack is empty ");
    return;
    }
    else
    printf("Pop %c \n",s->a[s->top]);
     s->top=s->top-1; 
  }

  void display(struct stack *s)
  {int i=0;
  	printf("Stack is ");
   for(i=0;i<=s->top;i++)
   printf("%c \t",s->a[i]);
    }

 int main()
 { struct stack s;
 	char a;
   s.top=-1;
   int x=1;
   do
   { printf("\nEnter number 1-Push  2-Pop  3-Display 4-Exit ");
     scanf("%d",&x);
      if(x==1)
      	{ printf("Enter element ");
          scanf(" %c",&a);
           push(a,&s);
         }
      if(x==2)
         pop(&s);

      if(x==3)
      display(&s);

    }
   while(x==1 | x==2 | x==3);
   

   return 0;
}