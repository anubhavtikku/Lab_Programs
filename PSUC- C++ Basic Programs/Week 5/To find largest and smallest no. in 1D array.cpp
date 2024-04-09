#include<iostream>
using namespace std;
int main()
{ int i,n,a[100],largest,smallest;
  cout<<"Enter the no. of numbers you want to input ";
  cin>>n;
  cout<<"Enter "<<n<<" numbers ";
  for(i=0;i<n;i++)
        cin>>a[i];
  largest=a[0];
  smallest=a[0];
  for(i=0;i<n;i++)
  { if(a[i]<smallest)
     smallest=a[i];
    if(a[i]>largest)
     largest=a[i];
    }
   cout<<"Largest No. is "<<largest;
   cout<<"\nSmallest No. is "<<smallest;
   return 0;
}
