#include<iostream>
using namespace std;
int gcd(int a,int b)
{
    if(b==0)
        return a;
    else
        return gcd(b,a%b);
}
int main()
{
    int a,b;
    cout<<"Entee the number";
    cin>>a>>b;
    if(b>a)
    {
        a=a+b;
        b=a-b;
        a=a-b;

}
cout<<"GCD is "<<gcd(a,b);
}
