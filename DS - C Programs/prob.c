#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct node
{ 
  int data;
  struct node* next;

}Node;

Node* insert(Node *head,int ele)
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
    if(head->next==NULL)
  {   printf("Empty List ");
    return ;
  }
  
  while(temp->next!=head)
  {
    temp=temp->next;
    if(temp)
    printf("%d \t",temp->data);
    
  }
}

Node* sort(Node *h1)
{ Node *h2=(Node *)malloc(sizeof(Node));
  h2->data=32145;
  h2->next=h2;
  int i=32145;
  Node *t=h1->next;
  Node *j=h1->next;
  Node *prev;
  
  while(j!=h1)
  {	i=32145;
  for(t=h1->next;t!=h1;t=t->next)
  {    
  	   if(t->data<i)
  	   	i=t->data; 	   

  }   
  
 for(t=h1;t->next!=h1;t=t->next)
  {
  	  if((t->next)->data==i)
       {
       	 prev=t->next;
       	 t->next=prev->next;
         prev->next=NULL;
         if(j==prev)
         	{j=t->next;            
         	}
         
       	 free(prev);
       	 h2=insert(h2,i);
       	 break;
       }
  }

}

return h2;
}

 int main()
 { Node *h1=(Node *)malloc(sizeof(Node));
   h1->next=h1;
   h1->data=32145;
   
   int n,x,i;
   int a[10];

   printf("Enter n for number \n");
   scanf("%d",&n);

  for(i=0;i<n;i++)
  { printf("Enter number ");
    scanf("%d",&x);	
  	h1=insert(h1,x);
  }
printf("List is ");
  display(h1);
 printf("\nSorted List is ");
 Node *h2=(Node *)malloc(sizeof(Node));
  h2=NULL;
  h2=sort(h1);
  display(h2);
}