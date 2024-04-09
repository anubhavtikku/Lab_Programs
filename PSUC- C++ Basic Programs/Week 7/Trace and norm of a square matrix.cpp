#include<iostream>
using namespace std;
#include<math.h>
int main()
{
    int a[10][10],trace=0,norm=0,n,i,j;
    cout<<"Enter dimension of square matrix ";
    cin>>n;

    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    cin>>a[i][j];

    cout<<"\n";

    for(i=0;i<n;i++)
    {for(j=0;j<n;j++)
    { if(i==j)
      trace+=a[i][j];
      norm+=a[i][j]*a[i][j];
      cout<<a[i][j]<<"\t";
    }
     cout<<"\n";}
     norm=sqrt(norm);
cout<<"\nTrace = "<<trace;
cout<<"\nNorm = "<<norm;
return 0;
}
