#include<iostream>
using namespace std;

void taylor(int n,float x);

int main()
{
    int n;
    float sum,x;
    cout<<"Enter value of x : ";
    cin>>x;
    cout<<"Enter n for the sum of n terms of taylor series : ";
    cin>>n;
    taylor(n,x);
    return 0;
}

void taylor(int n,float x)
{
    float sum=1,c=1,i;

    for(i=1;i<=n;i++)
        {
        c=c*x;
        c=c/i;
        sum=sum+c;
        }
    cout<<"Value is "<<sum;

}

