#include<iostream>
using namespace std;
int main()
{
    int n,k;
    cout<<"Enter the multiplication table for n numbers up to k terms ";
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {for(int j=1;j<=k;j++)
     cout<<i<<"*"<<j<<"="<<i*j<<"\t";
     cout<<"\n";
    }
     return 0;
}
