#include <stdio.h>
#include <stdlib.h>

typedef struct node 
{int data;
  struct node *next;
 } Node;

Node* insert(Node *head,int ele)
{ 
  Node *newnode=(Node *)malloc(sizeof(Node)),*temp=head;

  newnode->data=ele;
  newnode->next=NULL;
  while(temp->next!=NULL)
  {
  	temp=temp->next;
  }
  temp->next=newnode;
  return head;
}

Node* delete(Node *head)
{ if(head->next==NULL)
	{   printf("Empty List ");
		return head;
	}
  Node *temp=head;
  temp=temp->next;
  temp=temp->next;
  head->next=temp;
  return head;
}

void  display(Node *head)
{ Node *temp=head;
    if(head->next==NULL)
	{   printf("Empty List ");
		return ;
	}
	
	while(temp!=NULL)
	{
		temp=temp->next;
		if(temp)
		printf("%d \t",temp->data);
		
	}
 
}

 int main()
 { Node *head=(Node *)malloc(sizeof(Node));
   head->next=NULL;
   head->data=0;
   
   int x,y;

   do
   { printf("\nEnter 1.To insert element 2.To delete element 3.To display queue 4.Exit ");
     scanf("%d",&x);

     if(x==1)
     {  printf("Enter element ");
        scanf("%d",&y);
     	head=insert(head,y);
     }

     if(x==2)
     {
     	head=delete(head);
     }

     if(x==3)
       {
       	display(head);
       }

   }while(x==1 ||x==2 || x==3);

   return 0;
 }