#include<iostream>
using namespace std;
int main()
{
    int n,x,rev=0,rem;
    cout<<"Enter number ";
    cin>>n;
    x=n;
    while(n>0)
    {
        rem=n%10;
        rev=rev*10+rem;
        n=n/10;

    }

    if (x==rev)
    cout<<"Number is a Palindrome ";
    else
    cout<<"Number is not a Palindrome ";

    return 0;
}
