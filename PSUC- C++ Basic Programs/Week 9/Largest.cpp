#include<iostream>
using namespace std;

void largest(int a[],int n)
{ int i,l;
  l=a[0];
  for(i=0;i<n;i++)
    if(a[i]>l)
    l=a[i];

  cout<<"Largest value is "<<l;
}

int main()
{ int a[10],n,i;
  cout<<"Enter the no. of numbers you want to input ";
  cin>>n;
  cout<<"\nEnter numbers ";
  for(i=0;i<n;i++)
    cin>>a[i];
  largest(a,n);
}
