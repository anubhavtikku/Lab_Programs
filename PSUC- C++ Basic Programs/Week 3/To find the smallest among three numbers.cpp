#include<iostream>
using namespace std;
int main()
{ float a,b,c,smallest;
  cout<<"Enter three numbers ";
  cin>>a>>b>>c;
  smallest=(a<b)?((a<c)?a:c):((b<c)?b:c);
  cout<<"The smallest number is "<<smallest;
  return 0;

}
