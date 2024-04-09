#include<iostream>
using namespace std;
int main()
{ int a[100],i,n,prime,j;
  cout<<"Enter the no. of numbers you want to input ";
  cin>>n;
  cout<<"Enter "<<n<<" numbers ";
  for(i=0;i<n;i++)
    cin>>a[i];
    cout<<"\nThe prime numbers in the array are\t";
  for(i=0;i<n;i++)
  { prime=1;
    for(j=2;j<a[i];j++)
        if(a[i]%j==0)
    { prime=0;
      break;
    }
   if(prime==1)
        cout<<a[i]<<"\t";

  }
return 0;
}
