#include<iostream>
using namespace std;
int main()
{   float l,m,y1,u,y2,h,i,j;
    cout<<"Enter the range of values ";
    cin>>l>>u;
    cout<<"Enter the initial value of y ";
    cin>>y1;
    cout<<"Enter h ";
    cin>>h;
    cout<<"\n";
    cout<<"y1="<<y1<<"\n";
    for(i=l,j=2;i<u+h;i=i+h,j++)
    {
        y2=y1 + h*i*y1;
        cout<<"x="<<i<<"\t"<<"y"<<j<<"="<<y2<<"\n";
        y1=y2;
    }
     return 0;
}
