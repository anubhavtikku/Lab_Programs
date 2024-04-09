#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

int main()
{ char a[10][20];
  char s[20];
  int i,j,n;
  cout<<"Enter the no. of strings you want to enter ";
  cin>>n;
  n=n+1;
  cout<<"Enter strings ";
  for(i=0;i<n;i++)
        { gets(a[i]);}
  for(i=0;i<n;i++)
  for(j=0;j<n-1-i;j++)
  if((strcmpi(a[j],a[j+1]))>0)
  {
   strcpy(s,a[j]);
   strcpy(a[j],a[j+1]);
   strcpy(a[j+1],s);
  }

  cout<<"\nThe arranged strings are ";
  for(i=0;i<n;i++)
    cout<<"\n"<<a[i];

  return 0;
}
