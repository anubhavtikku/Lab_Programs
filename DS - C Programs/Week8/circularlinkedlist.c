#include <stdio.h>
#include <stdlib.h>

typedef struct node
{ 
  int data;
  struct node* next;

}Node;

Node* insert(Node *head,char ele)
{ 
  Node *newnode=(Node *)malloc(sizeof(Node)),*temp=head;

  newnode->data=ele;
  newnode->next=head;
  while(temp->next!=head)
  {
  	temp=temp->next;
  }
  temp->next=newnode;
  return head;
}

Node *merge(Node *h1,Node *h2)
{ Node *temp=h1,*prev=h2;

	char k;

	while(temp->next!=h1)
	{
		temp=temp->next;
		++k;
	}

	temp->next=h2->next;
 
    while(prev->next!=h2)
	{
		prev=prev->next;
	}
       prev->next=h1;
       
  temp=h1;
  temp=temp->next;
  prev=temp;
  
  for(temp=h1->next;temp!=h1;temp=temp->next)
  	for(prev=h1->next;prev->next!=h1;prev=prev->next)
  		if(prev->data > (prev->next)->data)
  		{ k=prev->data;
          prev->data=(prev->next)->data;
          (prev->next)->data=k;
  		}

  return h1;
}

void  display(Node *head)
{ Node *temp=head;
    if(head->next==NULL)
	{   printf("Empty List ");
		return ;
	}
	
	while(temp->next!=head)
	{
		temp=temp->next;
		if(temp)
		printf("%c \t",temp->data);
		
	}
 
}


int main()
{ char t[20];
  int i;
   Node *h1=(Node *)malloc(sizeof(Node));
   h1->next=h1;
   h1->data=0;

   Node *h2=(Node *)malloc(sizeof(Node));
   h2->next=h2;
   h2->data=0;

  printf("Enter string of characters for first list ");
  scanf("%s",t);
  for(i=0;t[i]!='\0';i++)
  	h1=insert(h1,t[i]);
  
  printf("Enter string of characters for second list ");
  scanf("%s",t);
  for(i=0;t[i]!='\0';i++)
  	h2=insert(h2,t[i]);

 h1=merge(h1,h2);
 display(h1);
 return 0;
}