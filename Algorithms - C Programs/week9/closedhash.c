#include<stdio.h>
#include<stdlib.h>
int op=0;

void insert(int a[],int y,int z,int hf)
{ if(a[z]==-999)
  {a[z]=y;
   return;}
  
  int temp=z;
  z=(z+1)%hf;
 
  while(z!=temp)
  { if(a[z]==-999)
    {a[z]=y;
     return;}    
    
    z=(z+1)%hf;
  }
  
  printf("Closed Hash Table is full ");

}

int search(int a[],int y,int z,int hf)
{ 
  if(a[z]==-999)
   return 0;
  op++;
  if(a[z]==y)
  return 1;

 int temp=z;
 z=(z+1)%hf;
 
 op++;
 while(temp!=z)
 { if(a[z]==y)
   return 1;
   
   else if(a[z]==-999)
   return 0;

   z=(z+1)%hf;
   op++;
 }

return 0;
}

int main()
{int a[100];
 int i,n,j,hf=7,y,res;
 for(i=0;i<100;i++)
 a[i]=-999;

  printf("Enter no. of elements to insert ");
  scanf("%d",&n);
  printf("Enter elements ");
  for(i=0;i<n;i++)
  {scanf("%d",&y);
   insert(a,y,y%hf,hf);
  }

  printf("\nEnter element to be searched ");
  scanf("%d",&y);
  res=search(a,y,y%hf,hf);
  if(res==0)
  printf("Element not found ");
  else
  printf("Element found ");
  printf("\nOpcode is %d",op);
}
