#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node 
{ char data[20];
  struct node *next;
  struct node *prev;
 } Node;

Node* insert(Node *head,char ele[])
{ 
  Node *newnode=(Node *)malloc(sizeof(Node)),*temp=head;

  strcpy(newnode->data,ele);
  newnode->next=NULL;
  if(head==NULL)
    return newnode;

  while(temp->next!=NULL)
  {
  	temp=temp->next;
  }
  temp->next=newnode;
  newnode->prev=temp;

  return head;
}

void display(Node *h)
{ Node *temp=h;
  while(temp!=NULL)
  { printf("%s\t",temp->data);
    temp=temp->next;
  }

}

Node *rev(Node *h)
{ Node *t=h;
  Node *temp=(Node *)malloc(sizeof(Node));
  temp=NULL;

    if(h=NULL)
      return NULL;
    
    while(t->next)
    { temp=t->next; 
      t->next=t->prev;
      t->prev=temp;
      t=t->prev;
    }
  
    t->next=t->prev;
    t->prev=NULL;

  return t;
}

int main()
{ Node *head=(Node *)malloc(sizeof(Node));
  head=NULL;
  char a[100],b[100];
  int i,j,k,l=0;
  printf("Enter string ");
  gets(a);
  for(i=0;a[i]!='\0';i++)
  { for(k=0;k<100;k++)
     {b[k]=' ';
      l=0;
      }

    if(a[i]!=' ')
    { for(j=i;(a[j]!=' ' )&& (a[j]!='\0');j++)
         {b[l]=a[j];
           l++;  }
       b[l]='\0';
       head=insert(head,b);
       i=j-1;
    }
   }
 

  head=rev(head);
   printf("Reversed String: ");
   display(head);
  return 0;
}