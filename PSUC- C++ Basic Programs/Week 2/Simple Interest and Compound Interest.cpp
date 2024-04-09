#include<iostream>
using namespace std;
#include<math.h>
int main()
{
    float p,r,t,si,ci;
    cout<<"Enter principle,rate and time : \n";
    cin>>p>>r>>t;
    si=(p*r*t)/100;
    ci=p*pow( (1+(r/100)),t)-p;
    cout<<"Simple Inteerest "<<si<<endl;
    cout<<"Compound Interest "<<ci<<endl;
    return 0;
}
