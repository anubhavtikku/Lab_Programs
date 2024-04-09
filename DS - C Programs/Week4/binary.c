# include <stdio.h>
struct stack
{ int a[10];
  int top;
  };

 void push(int item,struct stack *s)
 { if(s->top==9)
   {printf("Stack is full");
   return;
   }
   else
   	{ printf("Push %d\n",item);
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
    printf("Pop %d \n",s->a[s->top]);
     s->top=s->top-1; 
  }

  void display(struct stack *s)
  {int i=0;
  	printf("Stack is ");
   for(i=0;i<=s->top;i++)
   printf("%d \t",s->a[i]);
    }

  int main()
  {  int n,x,i,k=0,t,b[10];
     struct stack s;
     s.top=-1;
     printf("Enter number ");
     scanf("%d",&n);
     x=n;
     while(x>0)
      { t=x%2;
        x=x/2;
        ++k;
        push(t,&s);    
        }

    for(i=0;s.top!=-1;i++)
      { b[i]=s.a[s.top];
        pop(&s);
     }

    printf("Binary number is ");

     for(i=0;i<k;i++)
      printf("%d",b[i]);
    return 0;
}