#include <stdio.h>
#include <stdlib.h>

struct node
{   int data;
	struct node *rt;
	struct node *lt;
};

typedef struct node Node;

Node* insert(Node *h,int k)
{
	
     if(h==NULL)
	{	Node *newnode=(Node *)malloc(sizeof(Node *));
		newnode->data=k;
		newnode->rt=NULL;
		newnode->lt=NULL;
		return newnode;
	}

	else if(h->data <k)
	{
        h->rt=insert(h->rt,k);
	}

	else if(h->data >k)
	{
		h->lt=insert(h->lt,k);
	}

	return h;

}

void inorder(Node *h)
{
	if(h!=NULL)
	{
		inorder(h->lt);
		printf("%d \t",h->data);
		inorder(h->rt);
	}
}

void preorder(Node *h)
{
	if(h!=NULL)
	{	printf("%d \t",h->data);
		preorder(h->lt);
		preorder(h->rt);
	}
}

void postorder(Node *h)
{
	if(h!=NULL)
	{
		postorder(h->lt);
		postorder(h->rt);
		printf("%d \t",h->data);
	}
}

int search(Node *temp,int i)
{
	
    while(1)
    { 
      if(temp==NULL)
    	 return 0;
      
      else if(temp->data==i)
      	return 1;

      else if(temp->data < i)
      	temp=temp->rt;

	  else if(temp->data > i)
      	temp=temp->lt;           

     }

}

int main()
{   Node *h=NULL;
	printf(" To Create an BST (No Duplicates )\n\n");
	int x=1,k;
	while(x==1)
	{ printf("Insert value ");
      scanf("%d",&k);
      h=insert(h,k);
      printf("\nWish to Continue 1-Yes 2-No ");
      scanf("%d",&x);
	}
    
    x=1;
	while(x!=5)
	{
		printf("\n\nEnter 1.Search Value 2.Inorder 3.Preorder 4.Postorder 5.Exit ");
        scanf("%d",&x);
        
        if(x==1)
        {
        	int j=3000,flag=0;
        	printf("Enter value to be searched ");
            scanf("%d",&j);
            flag=search(h,j);
            if (flag==1)
            {
            	printf("Element found ");
            }
            else
            {   printf("Element not found ");
                h=insert(h,j);
        		printf("Element inserted ");
            }


        }
        if(x==2)
        {  printf("Inorder ");
          inorder(h);
    	}

    	if(x==3)
    		{  printf("Preorder ");
               preorder(h);
    	     }
        
        if(x==4)
       		{  printf("Postorder ");
               postorder(h);
    	     }

	}

	return 1;
}