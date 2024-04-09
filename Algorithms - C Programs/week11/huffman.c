#include <stdio.h>
#include <stdlib.h>

struct node 
{char data;
 float freq;
 struct node *lt,*rt;
};

typedef struct node Node;

void sort(Node *a[10],int n)
{ Node *temp=NULL;
  int i,j=0;
  for(i=0;i<n;i++)
  for(j=0;j<n-1-i;j++)
  if(a[j]->freq > a[j+1]->freq)
  {temp=a[j];
   a[j]=a[j+1];
   a[j+1]=temp;
  }

}

void join(Node *a[10],int n)
{ Node *b=(Node *)malloc(sizeof(Node *));
  Node *c=(Node *)malloc(sizeof(Node *));
  int i;
  *b=*a[0];
  *c=*a[1];
   a[0]->lt=b;a[0]->rt=c;a[0]->freq=b->freq+c->freq;a[0]->data='I';
   for(i=1;i<n-1;i++)
   a[i]=a[i+1];
}


void print(Node *h,int arr[],int k)
{if(h->lt)
 {arr[k]=0;
  print(h->lt,arr,k+1);
 }

 if(h->rt)
 {arr[k]=1;
  print(h->rt,arr,k+1);
 }

 if(h->lt==NULL && h->rt==NULL)
 {printf("\n%c\t",h->data);
  for(int i=0;i<k;i++)
  printf("%d",arr[i]);
 }

}

int main()
{int n,i,d,f;
 int arr[100];
 int k=0;
 printf("Enter no. of chars ");
 scanf("%d",&n);
 printf("Enter the chars and their frequencies ");
 
 Node *a[10];
 char da;
 float fa; 

 for(i=0;i<n;i++)
 {a[i]=(Node *)malloc(sizeof(Node *));
  a[i]->lt=a[i]->rt=NULL;
  scanf(" %c",&da);
  scanf("%f",&fa);
  a[i]->data=da;
  a[i]->freq=fa;
 }

 
 
 while(n>1)
 {sort(a,n);
  join(a,n);
  n=n-1;
 }
 
 print(a[0],arr,k);
}
