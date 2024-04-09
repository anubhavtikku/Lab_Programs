#include<stdio.h>
#include<stdlib.h>

typedef struct node
{int value;
 struct node *next;
}Node;

int op=0;

void insert(Node *a[],int z,int k)
{
  Node *newnode=(Node *)malloc(sizeof(Node *));
  newnode->value=z;
  newnode->next=NULL;
  
 if(a[k]==NULL)
 {a[k]=newnode; 
  return;
 }

 Node *y=a[k];
 while(y->next!=NULL)
 {
   y=y->next;
  }

  y->next=newnode;
 
}

int search(Node *a[],int z,int k)
{ 
  if(a[k]==NULL)
  return 0;
  
  Node *y=a[k];
  op++;
  while(y)
  { if(y->value==z)
    return 1;
    y=y->next;
    op++;
  }

return 0;
}

int main()
{ Node *a[10];
  int n,i,y,k,hf=7,res;

  for(i=0;i<10;i++)
  {a[i]=NULL;
  }

  printf("Enter no. of elements to insert ");
  scanf("%d",&n);
  printf("Enter elements ");
  for(i=0;i<n;i++)
  {scanf("%d",&y);
   k=y%hf;
   insert(a,y,k);}

  printf("Enter element to be searched ");
  scanf("%d",&y);
  res=search(a,y,y%hf);
  if(res==1)
  printf("Element found ");
  else
  printf("Element not found ");
  printf("\nOpcode is %d",op);
} 
