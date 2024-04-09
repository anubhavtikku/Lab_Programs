#include <stdio.h>
#include <stdlib.h>


typedef struct node
{ int data;
  struct node* lc;
  struct node* rc;

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

int main()
{
  Node *root=(Node *)malloc(sizeof(Node));
  root=NULL;
  int x=0,y,z;

  do
  { 
  	printf("\nEnter 1.To insert in tree 2.Search element 3. Display Inorder 4. Display Preorder 5.Display Postorder 6.Exit ");
    scanf("%d",&x);

       if(x==1)
       {printf("Enter node ");
        scanf("%d",&y);
        root=create(root,y);
         }

       if(x==3)
       { iterinorder(root);
       }

       if(x==4)
       { preorder(root);
       }

       if(x==5)
       {
       	 postorder(root);
       }

       if(x==2)
       {int k=0;
       	printf("Enter element to be searched ");
        scanf("%d",&y);
        search(root,y,&k);
        if(k==0)
        	printf("Not found ");

       }

  
  }while(x==1 || x==2 || x==3 ||x==4 ||x==5);
}

