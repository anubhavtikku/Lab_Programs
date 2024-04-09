#include <stdio.h>

int s(char a[10],int k);

int main()
{ char a[10];
	int i,k=0,l;
   printf("Enter string ");
   gets(a);
   for(i=0;a[i]!='\0';i++)
   k++;
   l=s(a,k);
}

int s(char a[10],int k)
{ static int i=0;
   
   if(i>=k/2)
   	 {  printf("Palindrome ");
   	 	return 0;
   	 }

   
   if(a[i]!=a[k-i-1])
   	{   printf("Not a Palindrome ");
   		return 1;}
   
   i++;
   s(a,k);
   }