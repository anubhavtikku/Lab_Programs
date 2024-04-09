#include <stdio.h>
#include <stdlib.h>


typedef struct node
{ int data;
  struct node* lc;
  struct node* rc;

}Node;

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

void iterinorder(Node *rt)
{  Node *t=rt;

	while(1)
	{
		while(t)
		{
			push(t);
			t=t->lc;
		}
       
        t=pop();
        if(t==NULL)
        	break;

        
         printf("%d\t",t->data);
         t=t->rc;
     
	}


}

void search(Node *ptr,int x,int *y)
{ 
   if(ptr!=NULL)
   { if(x==ptr->data)
   	 { printf("Element found\n");
   	 	*y=1;
       return;
   	 }
   	 search(ptr->lc,x,y);   	 
   	 search(ptr->rc,x,y);
   }

}

void preorder(Node *ptr)
{
   if(ptr!=NULL)
   { 
   	 printf("%d\t",ptr->data);
   	 preorder(ptr->lc);   	 
   	 preorder(ptr->rc);
   }

} 

void postorder(Node *ptr)
{
   if(ptr!=NULL)
   { 
   	 postorder(ptr->lc);   	 
   	 postorder(ptr->rc);
   	 printf("%d\t",ptr->data);
   }

}

int c[100];
int b[100];
int l=0;

void in(Node *rt ,int k)
{
   if(rt!=NULL)
   {
       if((rt->lc==NULL)&&(rt->rc==NULL))
       {
            c[l]=rt->data;
            b[l]=k;
            l=l+1;
       }
       in(rt->lc,k+1);
       in(rt->rc,k+1);

   }


}

int main()
{
  Node *root=(Node *)malloc(sizeof(Node));
  root=NULL;
  int x=0,y,z;
  
  root=create();
  in(root,0);
  int i,j=1000;
  for(i=0;i<l;i++)
  { if(b[i]<j)
  	j=b[i];
  }
  for(i=0;i<l;i++)
  {
  	if(b[i]==j)
  		printf("%d\t",c[i]);
  }
printf("hello");
 /* do
  { 
    printf("\nEnter 1. Search element 2. Display Inorder 3. Display Preorder 4.Display Postorder 5.Exit ");
    scanf("%d",&x);

       if(x==1)
       {int k=0;
        printf("Enter element to be searched ");
        scanf("%d",&y);
        search(root,y,&k);
        if(k==0)
          printf("Not found ");

       }

       if(x==2)
       { iterinorder(root);
       }

       if(x==3)
       { preorder(root);
       }

       if(x==4)
       {
         postorder(root);
       }
       
  }while(x==1 || x==2 || x==3 ||x==4 );
*/}