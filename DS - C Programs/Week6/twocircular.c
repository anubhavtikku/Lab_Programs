#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 10

struct queue
{ int a[50];
  int front1;
  int rear1;
  int front2;
  int rear2;
  };


 void insertcq(int item,struct queue *s,int x)
 {  if(x==1)
  {
 	if((s->rear1+1)%MAX==s->front2)
   {printf("Circular Queue is full");
   return;
   }
   else
   	{ printf("Insert %d\n",item);  	  
   	  s->a[s->rear1]=item; 
   	  s->rear1=(s->rear1+1)%MAX;
  }	
  }

   if(x==2)
  {
 	if((s->rear2+1)%MAX==s->front1)
   {printf("Circular Queue is full");
   return;
   }
   else
   	{ printf("Insert %d\n",item);
   	  s->a[s->rear2]=item;
   	  s->rear2=(s->rear2+1)%MAX;
 
  }
  }
}

void delete(struct queue *s,int x)
  { 
      if(x==1)
  	{if(s->front1==s->rear1)
  	{printf("Circular Queue is empty ");
    return;
    }
    else
    printf("Delete %d \n",s->a[s->front1]);
     s->front1=(s->front1+1)%MAX; 
    }

    if(x==2)
  	{if(s->front2==s->rear2)
  	{printf("Circular queue is empty ");
    return;
    }
    else
    printf("Delete %d \n",s->a[s->front2]);
     s->front2=(s->front2+1)%MAX; 
    }
  }

  void display(struct queue *s,int x)
  { int i;

  	if(x==1)
  	{ 	i=s->front1;
  	printf("Circular queue%d is ",x);
    do
    { printf("%d\t",s->a[i]);
      i=(i+1)%MAX;
     }  while(i!=s->rear1);

    }

    if(x==2)
   { i=s->front2;
  	 printf("Circular queue%d is ",x);
     do
     { printf("%d\t",s->a[i]);
       i=(i+1)%MAX;
      }  while(i!=s->rear2);
   }
 }

 int main()
  {struct queue s;
   int x,y,s1;
   s.front1=0;
   s.rear1=0;
   s.front2=5;
   s.rear2=5;

   do
    {printf("\nEnter 1.To perform operation on queue1 and 2.To perform operation on queue2 "); 
     scanf("%d",&y);
     printf("\nEnter 1.To insert element 2.To delete element 3.To display queue 4.Exit ");
     scanf("%d",&x);
     if(x==1)
     { printf("Enter element ");
       scanf("%d",&s1);
       insertcq(s1,&s,y);
     }             

     if(x==2)
     { 
       delete(&s,y);
     } 

     if(x==3)
     { 
       display(&s,y);
     } 


     }while(x==1 || x==2 || x==3);

     return 0;
     }

  