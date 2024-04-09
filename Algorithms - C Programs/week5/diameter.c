#include<stdio.h>
#include<stdlib.h>

struct node
{ int data;
struct node* lt;
struct node* rt;
};

typedef struct node Node;

Node *insert(Node *h,int x)
{ Node *newnode=(Node *)malloc(sizeof(Node *));
 if(x!=-1)
 { newnode->data=x;

   int a,b;
   printf("Enter left node value for %d ",newnode->data);
   scanf("%d",&a);
   newnode->lt=insert(newnode->lt,a); 
  
   printf("Enter right node value for %d ",newnode->data);
   scanf("%d",&b);
   newnode->rt=insert(newnode->rt,b);

  return newnode; 
 }
 else
 return NULL;
}

void inorder(Node *h)
{if(h!=NULL)
 { inorder(h->lt);
   printf("%d \t",h->data);
   inorder(h->rt);
  }
}

int max(int a,int b)
{ if(a>b)
  return a;

 return b;
}

int height(Node *h)
{ if(h==NULL)
  return 0;

  return(1+max(height(h->lt),height(h->rt)));
}

int diameter(Node *h)
{ 
   if(h==NULL)
   return 0;

  int lh=height(h->lt);
  int rh=height(h->rt);

  int ld=diameter(h->lt);
  int rd=diameter(h->rt);

  return max(1+lh+rh,max(ld,rd));
}

int main()
{Node *h=(Node *)malloc(sizeof(Node *));
 int x,d=0;
 printf("Enter value for root -1 for no value ");
 scanf("%d",&x);
 h=insert(h,x);
 printf("\nInorder traversal\n");
 inorder(h);
 d=diameter(h);
 printf("\n\nDiameter of tree is %d",d);
 
}




