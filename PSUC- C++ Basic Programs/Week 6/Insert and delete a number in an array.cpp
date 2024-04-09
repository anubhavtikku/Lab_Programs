#include<iostream>
using namespace std;
int main()
{   int a[100],i,n,x,p,temp;
    cout<<"Enter the number of elements you want to enter ";
    cin>>n;
    cout<<"Enter "<<n<<" elements ";
    for(i=0;i<n;i++)
        cin>>a[i];
    cout<<"\nEnter number you want to insert ";
    cin>>x;
    cout<<"Enter position at which you want to enter ";
    cin>>p;
    for(i=n-1;i>=(p-1);i--)
    {
        a[i+1]=a[i];
    }
    a[p-1]=x;
    n=n+1;
    for(i=0;i<n;i++)
        cout<<a[i]<<" ";

    cout<<"\nEnter the position of element you want deleted ";
    cin>>p;
    cout<<"\n";
    for(i=p-1;i<n;i++)
     a[i]=a[i+1];
    n=n-1;
    for(i=0;i<n;i++)
    cout<<a[i]<<" ";
    return 0;
}
