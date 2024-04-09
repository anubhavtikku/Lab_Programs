#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 3

struct queue
{ char a[10][10];
  int front;
  int rear;
  };


 void insertcq(char t[50],struct queue *s)
 { if((s->rear+1)%MAX==s->front)
   {printf("Circular queue is full ");
   return;
   }
   

   else
   	{ printf("Insert %s\n",t);   	  
   	  strcpy(s->a[s->rear],t);
   	  s->rear=(s->rear+1)%MAX; 
    }
 }

   void deletecq(struct queue *s)
    {if (s->rear==s->front)
    {printf("Circular Queue is empty ");
    return;
    }
    else
    {  
      printf("Deleted %s\n",s->a[s->front]); 
      s->front=(s->front+1)%MAX;    
    }
    }

    

   void displayc(struct queue *s)
 {  int i=s->front;
 	if (s->rear==s->front)
 		{printf("\nEmpty Queue");
 	     return;}
    do
    { printf("%s\t",s->a[i]);
      i=(i+1)%MAX;
     }  while(i!=s->rear);
  }

  int main()
  { struct queue s;
    int x=1;
    char s1[20];
    s.rear=0;
    s.front=0;
    do
    {printf("\nEnter 1.To insert element 2.To delete element 3.To display queue 4.Exit ");
     scanf("%d",&x);
     if(x==1)
     { printf("Enter string ");
       scanf("%s",s1);
       insertcq(s1,&s);
     }             

     if(x==2)
     { 
       deletecq(&s);
     } 

     if(x==3)
     { 
       displayc(&s);
     } 


     }while(x==1 || x==2 || x==3);

     return 0;
     }

