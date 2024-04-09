#include<iostream>
using namespace std;
int main()
{
    int sum=0,x,y,r;
    cout<<"Enter number ";
    cin>>x;
    y=x;
    while(y>0)
    { r=y%10;
      y=y/10;
      sum=sum+r*r*r;

    }

    if(sum==x)
        cout<<"Armstrong Number ";
    else
        cout<<"Not an Armstrong Number ";
    return 0;
}
