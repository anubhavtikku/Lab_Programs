#include<stdio.h>
#include<stdlib.h>

struct node
{int data;
struct node *lt;
struct node *rt;
int b;
};

typedef struct node Node;

Node *insert(Node *h,int k)
{ if(h==NULL)
  {Node *newnode=(Node *)malloc(sizeof(Node *));
   newnode->data=k;
   newnode->lt=newnode->rt=NULL;
   return newnode;
  }
   
 else if(h->data<k)
 h->rt=insert(h->rt,k);

 else
 h->lt=insert(h->lt,k);

 return h;
}

int max(int a,int b)
{if(a>b)
 return a;
 return b;
}

int height(Node *h)
{ if(h==NULL)
  return 0;
 
  return 1+max(height(h->lt),height(h->rt));
}

void bf(Node *h)
{ if(h!=NULL)
  { h->b=height(h->lt)-height(h->rt);
    bf(h->lt);
    bf(h->rt);
  }

}

void inorder(Node *h)
{ if(h!=NULL)
  { 
    inorder(h->lt);
    printf("Node %d Balance Factor %d \n",h->data,h->b);
    inorder(h->rt);
  }

}

int main()
{Node *h=NULL;
 int k,x=1;
 while(x!=0) 
 {printf("Enter value to insert in tree (-1 for no value) ");
  scanf("%d",&k);
  if(k!=-1)
  h=insert(h,k);

  printf("Enter 1 to continue insertion 0 to stop ");
  scanf("%d",&x);
 }
 bf(h);
 inorder(h);
}
