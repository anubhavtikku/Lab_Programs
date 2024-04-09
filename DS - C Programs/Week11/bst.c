#include <stdio.h>
#include <stdlib.h>

typedef struct node
{ int data;
  struct node *lc;
  struct node *rc;
 }Node;

Node *create(Node *root,int x)
{	
    if(root==NULL)
    {root=(Node *)malloc(sizeof(Node));
     root->data=x;
     root->lc=root->rc=NULL;
    }

    else if(x > root->data)
    	root->rc=create(root->rc,x);
    
    else if(x < root->data)
    	root->lc=create(root->lc,x);

    else
    {
    	printf("Duplicate node\n");
    	
    }

    return(root);

}

Node *delete(Node *rt,int key)
{ if(rt==NULL)
    return NULL;

    else if(key < rt->data)
    rt->lc=delete(rt->lc,key);

    else if(key > rt->data)
    rt->rc=delete(rt->rc,key);

 else
 {
    if(rt->lc ==NULL && rt->rc==NULL)
     {
        free(rt);
        return NULL;
     }

     Node *q=(Node *)malloc(sizeof(Node));

    if(rt->lc==NULL)
    {   q=rt->rc;
        free(rt);
        return q;
    }

    if(rt->rc==NULL)
     { q=rt->lc;
       free(rt);
       return q;
     }

    q=rt->rc;

    while(q->lc)
    q=q->lc;

    rt->data=q->data;
    rt->rc=delete(rt->rc,q->data);
 }

   return rt;
}

void printlevel(Node *rt,int i)
{ if(rt==NULL)
   return;

   if(i==1)
    printf("%d\t",rt->data);

   else
   {
     printlevel(rt->lc,i-1);
     printlevel(rt->rc,i-1);
   }
}

int max(int a,int b)
{ if(a>b)
    return a;

  return b;
}

int height(Node *rt)
{
   if(rt==NULL)
    return 0;

return(1+max(height(rt->lc),height(rt->rc)));
}

void levelorderdisplay(Node *rt)
{ int i,k=height(rt);
  for(i=0;i<=k;i++)
    { printlevel(rt,i);
    printf("\n");}
}

int main()
{ int x=1;
  Node *rt=(Node *)malloc(sizeof(Node));
  rt=NULL;
  do
  { printf("Enter 1.Create BST 2.Delete element 3.Display elements 4.Exit ");
    scanf("%d",&x);

    if(x==1)
    { int z=0;
      printf("Enter elements (-999 to stop and No duplicate nodes ) ");
      do{
      printf("Enter element ");
      scanf("%d",&z);
      if(z!=-999)
      rt=create(rt,z);
     }while(z!=-999);
   }

    if(x==2)
    { int k;
      printf("Enter element to be deleted ");
      scanf("%d",&k);
      delete(rt,k);
     } 

    if(x==3)
    levelorderdisplay(rt);   

  }while(x==1 || x==2 || x==3);

}