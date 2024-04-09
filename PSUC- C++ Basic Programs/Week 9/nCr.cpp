#include<iostream>
using namespace std;

int fact(int x)
{ int count=1;
  for(int i=x;i>0;i--)
    count=count*i;
  return count;

}

int main()
{ int v,n,r;
 cout<<"Enter value of n and r in nCr ";
 cin>>n>>r;
 v=fact(n)/(fact(n-r)*fact(r));
 cout<<"Value of nCr is "<<v;
 return 0;
}

