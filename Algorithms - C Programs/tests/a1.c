//Check Whether given binary tree is BST or not 
#include<stdio.h>
#include<stdlib.h>

struct node
{ int data;
struct node *lt;
struct node *rt;
};

typedef struct node Node;

int a[100];
int k=0;

void inorder(Node *h)
{ if(h!=NULL)
  { inorder(h->lt);
    a[k++]=h->data;
    inorder(h->rt);
   }
}

Node *insert(Node *h,int y)
{ Node *temp=(Node *)malloc(sizeof(Node *));
  if(y!=-1)
  { temp->data=y;
    temp->lt=temp->rt=NULL;
    int a,b;
 
 printf("Enter left node and right node value -1 for NULL");
 scanf("%d",&a);
 scanf("%d",&b);
 temp->lt=insert(temp,a);
 temp->rt=insert(temp,b);
 return temp;
  }
 
 else 
  return NULL; 
}

int main()
{ 
  Node *h=(Node *)malloc(sizeof(Node *));
  int y;
  printf("Enter data for the root of tree - -1 for NULL ");
  scanf("%d",&y);
  h=insert(h,y);
  
  int i;
  int flag=0;
  inorder(h);
 // for(i=0;i<k-1;i++)
 //  printf("%d",a[i]);
   
  for(i=0;i<k-1;i++)
  {if(a[i]>a[i+1])
   flag=1;
  }

  if(flag==0 && k>0)
  printf("BST");
  else
  printf("Not a BST");
}
