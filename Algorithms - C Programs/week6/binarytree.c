#include<stdio.h>
#include<stdlib.h>

struct node
{int data;
struct node *lt;
struct node *rt;
};

typedef struct node Node;
int op=0;

Node *insert(int x)
{
 if(x!=-1)
 {Node *newnode=(Node *)malloc(sizeof(Node *));
  newnode->data=x;
  int a,b;
  printf("Enter left node value for %d (-1 for no value) ",x);
  scanf("%d",&a);
  printf("Enter right node value for %d (-1 for no value) ",x);
  scanf("%d",&b);
  newnode->lt=insert(a);
  newnode->rt=insert(b);
  return newnode;
 }
 else
 return NULL;
}

int count(Node *h)
{ if(h==NULL)
   return 0;

 op++;
 return(1+count(h->lt)+count(h->rt));
}

int main()
{int k,c;
 Node *h=(Node *)malloc(sizeof(Node *));
 printf("Enter root value of tree (-1 for no value) ");
 scanf("%d",&k);
 h=insert(k);
 c=count(h);
 printf("The no. of nodes in tree is %d",c);
 printf("\nThe opcount is %d",op);
}
