#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{ int i,j,k,t=1;
  char s[100],b[100];
  cout<<"Enter string ";
  gets(s);

  for(i=0;s[i]!='\0';i++);

  for(k=0,j=i-1;j>=0;j--,k++)
    b[k]=s[j];
  for(i=0;s[i]!='\0';i++)
    if(s[i]!=b[i])
     t=0;

   if(t==0)
    cout<<"Not a palindrome ";
   else
    cout<<"Palindrome ";
    return 0;
}
