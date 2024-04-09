#include<iostream>
using namespace std;
int main()
{
  float r,s,v;
  cout<<"Enter radius "<<endl;
  cin>>r;
  s=4*3.14*r*r;
  v=4*3.14*r*r*r*0.33;
  cout<<"Surface Area "<<s<<endl;
  cout<<"Volume "<<v<<endl;
  return 0;

}
