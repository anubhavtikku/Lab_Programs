#include<iostream>
using namespace std;
int main()
{ int x,y,z;
  cout<<"Enter number ";
  cin>>x;
  y=x>>1;
  z=x<<1;
  cout<<"\nLeft Shift Operator on "<<x<<" produces "<<z;
  cout<<"\nRight Shift Operator on "<<x<<" produces "<<y;
  return 0;
}
