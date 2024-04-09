#include<iostream>
using namespace std;
#include<stdio.h>
#include<string.h>

void compare(char a[][20],int i)
{ char s[20];
  if( (strcmp(a[i],a[i+1]))>0)
    { strcpy(s,a[i]);
      strcpy(a[i],a[i+1]);
      strcpy(a[i+1],s);}
}

void Sort(char a[][20],int n)
{ int i,j;
  for(j=0;j<n;j++)
  for(i=0;i<n-j-1;i++)
    compare(a,i);
}

int main()
{ char a[10][20];
  int i,n;
  cout<<"Enter the no. of names you want to input ";
  cin>>n;
  n=n+1;
  cout<<"Enter the names ";
  for(i=0;i<n;i++)
  gets(a[i]);
  Sort(a,n);
  cout<<"\nThe sorted names are ";
  for(i=0;i<n;i++)
  cout<<a[i]<<"\n";
}
