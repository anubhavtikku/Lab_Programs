//Count no. of leaf and non leaf nodes in a BST
#include<stdio.h>
#include<stdlib.h>

struct node
{int data;
struct node *lt;
struct node *rt;
};

typedef struct node Node;

Node *insert(Node *h,int x)
{ if(h==NULL)
   {Node *temp=(Node *)malloc(sizeof(Node *));
    temp->lt=NULL;
    temp->rt=NULL;
    temp->data=x;
    return temp;
   }

  else if(x > h->data)
  { h->rt=insert(h->rt,x);
   }
  
  else
  {h->lt=insert(h->lt,x);
   }

 return h;
}

void inorder(Node *h)
{ if(h!=NULL)
  {inorder(h->lt);
   printf("%d \t",h->data);
   inorder(h->rt);
  }
}

int count=0;

void cou(Node *h)
{ if(h!=NULL)
  {cou(h->lt);
   if(h->lt==NULL && h->rt==NULL)
   { count=count+1;
   }
   cou(h->rt);
  }
}

int co(Node *h)
{ if(h==NULL)
  return 0;
  
  if(h->lt==NULL && h->rt==NULL)
  return 1;
  
  return(co(h->lt)+co(h->rt));
}

int main()
{ int i=1,x,k=0;
  Node *h=NULL;
  while(i)
  { printf("Enter data to be inserted in tree ");
    scanf("%d",&x);
    h=insert(h,x);
    k++;

   printf("Continue to Enter Yes-1 No-0 ");
   scanf("%d",&i); 
  }

inorder(h);
printf("\n");
cou(h);
printf("Total Nodes %d",k);
printf("\nLeaf Nodes %d",count);
printf("\nLeaf Nodes %d",co(h));
}
