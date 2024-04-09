#include<stdio.h>
#include<stdlib.h>

int main()
{ int k=0,j=0,i;
  char a[100],b[100];
  
  printf("Enter string ");
  gets(a);
  
  printf("Enter substring to be searched ");
  gets(b);
  
  for(i=0;a[i]!='\0';i++)
  {
     j=0;
     while(a[i+j]==b[j])
     { j++;
       if(b[j]=='\0')
       { k=1;
         break;
         }
       if(a[i+j]=='\0')
       break;
     }
     
     if(k==1)
     break;
  }
  
  if(k==1)
  printf("Substring found ");
  else
  printf("Substring not found	");
  
}
