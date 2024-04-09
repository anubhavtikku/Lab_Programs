#include<iostream>
using namespace std;
int fibo(int n)
{
    if(n<2)
        return n;
    else
        return fibo(n-1)+fibo(n-2);
}
int main()
{
    int n,i;
    cout<<"Enter the number of terms.";
    cin>>n;
    for(i=0;i<n;i++)
        cout<<fibo(i)<<endl;
    return 0;

}
