#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct node 
{ int data;
  struct node *next;
 } Node;

Node* insert(Node *head,int ele)
{ 
  Node *newnode=(Node *)malloc(sizeof(Node)),*temp=head;

  newnode->data=ele;
  newnode->next=NULL;
  if(head==NULL)
    return newnode;

  while(temp->next!=NULL)
  {
  	temp=temp->next;
  }
  temp->next=newnode;

  return head;
}


void  display(Node *head)
{ Node *temp=head;
    if(head==NULL)
	{   printf("Empty List ");
		return ;
	}
	
	while(temp!=NULL)
	{
	
		printf("%d \t",temp->data);
	  temp=temp->next;	
	}
 
}

Node* add(Node *h1,Node *h2)
{ 
  Node *h3=(Node *)malloc(sizeof(Node));
  h3=NULL;
  int rem=0;
  int x;
  Node *t=h1,*prev=h2;
  
  while(t!=NULL && prev!=NULL)
    { 

      x=t->data+prev->data+rem;
      if(x>9)
        x=x-10;
     
      h3=insert(h3,x);
  
      if(t->data+prev->data+rem>9)
        rem=1;
      else
        rem=0;
      
      t=t->next;
      prev=prev->next;
 
      }
  
   while(t!=NULL)
 { 
    x=t->data+rem;
      if(x>9)
        x=x-10;


  h3=insert(h3,x);
   
   if(t->data+rem>9)
        rem=1;
      else
        rem=0;

     t=t->next;
 }

 while(prev!=NULL)
 { x=prev->data+rem;
      if(x>9)
        x=x-10;

   h3=insert(h3,x);
   
   if(prev->data+rem>9)
        rem=1;
      else
        rem=0;

     prev=prev->next;
 }

 if(rem==1)
 h3=insert(h3,rem);

return h3;
}

Node *rev(Node *cur,Node **h)
{ Node *t;

  if(cur==NULL)
    return NULL;

  if(cur->next==NULL)
    {  *h=cur;
      return cur;
      }
  t=rev(cur->next,h);
  t->next=cur;

  return cur;
}

int main()
{ long int x,y,w;
  int rem;
  printf("Enter first number ");
  scanf("%d",&x);
  Node *h1=(Node *)malloc(sizeof(Node));
  h1=NULL;
  w=x;
  while(w>0)
  { rem=w%10;
    h1=insert(h1,rem);
    w=w/10;
  }
   
  printf("Enter second number ");
  scanf("%d",&y);
  Node *h2=(Node *)malloc(sizeof(Node));
  h2=NULL;
  w=y;
  while(w>0)
  { rem=w%10;
    h2=insert(h2,rem);
    w=w/10;
  }
 

  Node *h3=(Node *)malloc(sizeof(Node));
  h3=add(h1,h2);

  Node *t=(Node *)malloc(sizeof(Node));
  t=rev(h3,&h3);
  t->next=NULL;

  printf("Sum is ");
  display(h3);
  
} 