#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 10

struct queue 
{  int a[MAX];
   int front;
   int rear;
};

void delete(struct queue *s)
{ if(s->front==s->rear)
	{printf("Queue is empty ");
      return;
    }

  	s->front=s->front+1;

}

void insert(struct queue *s,int ele)
{ int i,j,temp,k;
  if(s->rear==MAX-1)
	{ printf("Queue is full ");
      return; 
      }
    s->a[s->rear]=ele;
    s->rear=s->rear+1;
    
    for(i=s->front,k=0;i<s->rear;i++,k++)
    for(j=s->front;j<s->rear-k-1;j++)
    	if(s->a[j] > s->a[j+1])
    		{ temp=s->a[j];
              s->a[j]=s->a[j+1];
              s->a[j+1]=temp; 
              }
}

void display(struct queue *s)
{   if(s->front==s->rear)
	{printf("Queue is empty ");
      return;
    }
  int i;
   printf("Queue is ");
	for(i=s->front;i<s->rear;i++)
	{
        printf("%d\t",s->a[i]);
	}

}

int main()
{ struct queue s;
  s.front=0;
  s.rear=0;
  int x=1,s1;

   do
    {printf("\nEnter 1.To insert element 2.To delete element 3.To display queue 4.Exit ");
     scanf("%d",&x);
     if(x==1)
     { printf("Enter element ");
       scanf("%d",&s1);
       insert(&s,s1);
     }             

     if(x==2)
     { 
    
       delete(&s);
     } 

     if(x==3)
     { 
       display(&s);
     } 


     }while(x==1 || x==2 || x==3);

     return 0;
}


