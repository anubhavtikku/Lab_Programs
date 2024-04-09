#include<iostream>
using namespace std;
int main()
{   int  a[10][10],i,j,n,t=1;
    cout<<"Enter dimension of square matrix ";
    cin>>n;
    cout<<"\nEnter its elements ";
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
        cin>>a[i][j];
    cout<<"\n\nThe matrix is \n";
    for(i=0;i<n;i++)
   { for(j=0;j<n;j++)
      { if(a[i][j]!=a[j][i])
       t=0;
       cout<<a[i][j]<<"\t";
      }
    cout<<"\n";
   }

if(t==1)
    cout<<"\nSymmetric Matrix ";
else
    cout<<"\nNon Symmetric Matrix ";
return 0;
}
