#include <stdio.h>
#include <stdlib.h>

typedef struct node
{ int data;
  struct node* lc;
  struct node* rc;

}Node;

Node a[10];
int top=-1;

void push(Node *t)
{ if(top==10)
  {
       printf("Stack is full ");
       return;
  }
  ++top;
    a[top]=*t;
  
}

Node* pop()
{ if(top==-1)
  {
      return NULL ;
    }
   
    return &a[top--];
}

Node *create()
{   Node *rt=(Node *)malloc(sizeof(Node));
    int x;
    printf("\nEnter data (-1 for no data ) ");
    scanf("%d",&x);
    if(x!=-1)
    rt->data=x;
    else
      {rt=NULL;
       return rt;   }

    printf("Enter left child for %d",rt->data);
    rt->lc=create();

    printf("Enter right child for %d",rt->data);
    rt->rc=create();   

    return rt; 
}

void inorder(Node *rt)
{ if(rt==NULL)
  return ;

  inorder(rt->lc);
  printf("%d",rt->data);
  inorder(rt->rc);

}

void preorder(Node *rt)
{ Node *t=rt;

  while(1)
{ 
  while(t)
  { 
    printf("%d\t",t->data);
    if(t->rc)
    push(t->rc);
    t=t->lc;  
  }
   
  t=pop();
  if(t==NULL)
    break;

}
}

void postorder(Node *rt)
{ Node *t=rt;

  if(rt==NULL)
    return;

  do
  {
     while(t)
     { 
       push(t);
       if(t->rc)
       push(t->rc);
       t=t->lc;
     }

     t=pop();
     if(t==NULL)
     break;

    if((t->rc) && (&(a[top])==t->rc))
     { pop();
       push(t);
       t=t->rc;
     }

     else
     {
       printf("%d",t->data);
       t=NULL;
     }

  }while(top!=-1);

}

int main()
 {Node *root=(Node *)malloc(sizeof(Node));
  root=NULL;
  int x=0,y,z;
  
  root=create();

  do
  { 
    printf("\nEnter 1. Display Inorder 2. Display Preorder 3.Display Postorder 4.Exit ");
    scanf("%d",&x);

       if(x==1)
       { inorder(root);
       }

       if(x==2)
       { preorder(root);
       }

       if(x==3)
       {
         postorder(root);
       }
 }while(x==1 || x==2 || x==3);
}