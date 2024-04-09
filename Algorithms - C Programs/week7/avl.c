#include<stdio.h>
#include<stdlib.h>

struct node
{int data,b;
 struct node *lt;
 struct node *rt;
};

typedef struct node Node;

Node *Insert(Node *h,int k){

Node *newnode=(Node *)malloc(sizeof(Node *));
newnode->data=k; 

if(h==NULL)
return newnode;   

else 
{ Node *prev = NULL;
  Node *curr = h;
  while(curr != NULL)
{ prev = curr;
  if(curr->data < k) 
  curr=curr->rt;
  else 
  curr=curr->lt;
}
  
   if (prev->data < k)
    prev->rt=newnode;

    else 
    prev->lt = newnode;
return h;
}

void bf(Node *h)
{
 bf(h->lt);
 bf(h->rt);
}

Node* avl(Node *h,int k)
{ 

}


int main()
{
   bf(h);
}

