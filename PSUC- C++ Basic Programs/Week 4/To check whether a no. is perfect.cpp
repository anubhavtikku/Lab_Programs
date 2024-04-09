#include<iostream>
using namespace std;
int main()
{   int n,sum=1;
    cout<<"Enter number ";
    cin>>n;
    for(int i=2;i<=n/2;i++)
        if(n%i==0)
        sum=sum+i;
    if(sum==n)
        cout<<"Perfect Number ";
    else
        cout<<"Not a Perfect Number ";
    return 0;
}
