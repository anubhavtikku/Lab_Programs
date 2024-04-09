#include <stdio.h>
#include <stdlib.h>

 struct node 
{ 
  int data;
  struct node* next;

};

typedef struct node Node;

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

void  display(Node *head)
{ Node *temp=head;
    if(head->next==head)
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

Node* unio(Node *h1,Node *h2)
{ Node *temp=h1,*prev=h2;
	Node *h3=(Node *)malloc(sizeof(Node));
    h3->data=0;
    h3->next=h3;
    
    temp=temp->next;
	while(temp!=h1)
	{ 
	  h3=insert(h3,temp->data);
      temp=temp->next;
      }

    Node *x=h3->next;
    prev=prev->next;

    while(prev!=h2)
    {   int k=0;
    	x=h3->next;
    	while(x!=h3)
       { if(x->data==prev->data)
           {
           	k=1;
           	break;
           }
           x=x->next;
       }

       if(k==0)
       	insert(h3,prev->data);
      prev=prev->next;
    }

  for(prev=h3->next;prev->next!=h3;prev=prev->next)
  for(temp=prev;temp->next!=h3 && temp!=h3;temp=temp->next)        
        if((temp->next)->data==prev->data)
        	while((temp->next)->data==prev->data)
	         temp->next=(temp->next)->next;
return h3;

}

Node* inters(Node *h1,Node *h2)
{ Node *temp=h1->next,*prev=h2;
	Node *h3=(Node *)malloc(sizeof(Node));
    h3->data=0;
    h3->next=h3;

    
	while(temp!=h1)
	{ prev=h2->next;
		while(prev!=h2)	
        {  if(temp->data==prev->data)
            {   h3=insert(h3,temp->data);
            	break;
            }
        	prev=prev->next;
        }

			temp=temp->next;
	}

for(prev=h3->next;prev->next!=h3;prev=prev->next)
  for(temp=prev;temp->next!=h3 && temp!=h3;temp=temp->next)        
        if((temp->next)->data==prev->data)
        	while((temp->next)->data==prev->data)
	         temp->next=(temp->next)->next;

return h3;

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

   Node *h3=(Node *)malloc(sizeof(Node));
   Node *h4=(Node *)malloc(sizeof(Node));

  printf("Enter string of characters for first list ");
  scanf("%s",t);
  for(i=0;t[i]!='\0';i++)
  	h1=insert(h1,t[i]);
  
  printf("Enter string of characters for second list ");
  scanf("%s",t);
  for(i=0;t[i]!='\0';i++)
  	h2=insert(h2,t[i]);

printf("Union is \n");
 h3=unio(h1,h2);
 display(h3);
 printf("\nIntersection is \n");
 h4=inters(h1,h2);
 display(h4);
 return 0;
}