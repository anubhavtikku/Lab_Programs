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

Node *getTNode()
{
  Node *newnode = (Node *) malloc (sizeof(Node));
  newnode->rc=newnode->lc= NULL;
  return newnode;
}

void create (Node **rt, int item)
{
  int ch;
  Node *t = *rt;
  Node *present = NULL;
  Node *newnode;
  if (*rt == NULL)
    {
      *rt = getTNode();
      (*rt)->data = item;
      return;
    }
  do
    {
      printf("1 to insert to left, 2 to insert to right\n");
      scanf("%d", &ch);
      present = t;
      if (ch == 1)
    t= t->lc;
      else
    t = t->rc;
      if (t == NULL)
    {
      newnode = getTNode();
      newnode->data = item;
      (ch == 1)?(present->lc=newnode):(present->rc=newnode);
      return;
    }
    }while (1);
}

void inorder(Node *rt)
{ if(rt==NULL)
  return ;

  inorder(rt->lc);
  printf("%d\t",rt->data);
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
       printf("%d\t",t->data);
       t=NULL;
     }

  }while(top!=-1);
}

int main()
 {Node *root=(Node *)malloc(sizeof(Node));
  root=NULL;
  int x=0,y,z,ele;
  
  do
  { 
    printf("\nEnter 1.Iterative Insertion 2. Display Inorder 3. Display Preorder 4.Display Postorder 5.Exit ");
    scanf("%d",&x);

      if(x==1)
      { printf("Enter node\n"); 
        scanf(" %d", &ele);
        create(&root, ele);
      }

       if(x==2)
       { inorder(root);
       }

       if(x==3)
       { preorder(root);
       }

       if(x==4)
       {
         postorder(root);
       }
 }while(x==1 || x==2 || x==3 ||x==4);
}