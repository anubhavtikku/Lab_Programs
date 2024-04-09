#include<iostream>
using namespace std;
int main()
{ int a[100],n,i,x,m=0;
  cout<<"Enter the no. of numbers you want to input ";
  cin>>n;
  cout<<"Enter "<<n<<" numbers ";
  for(i=0;i<n;i++)
    cin>>a[i];
  cout<<"\nEnter no. to be searched ";
  cin>>x;
  for(i=0;i<n;i++)
  if(a[i]==x)
     { cout<<"Element found at position "<<i+1;
       m=1;
       break;
     }
  if(m==0)
    cout<<"Element not found ";
  return 0;
}
