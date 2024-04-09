#include<iostream>
using namespace std;
int main()
{
    int a[10][10],i,j,b[10],n,temp;
    cout<<"Enter dimension of square matrix ";
    cin>>n;
    cout<<"Enter its elements ";
    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
    { cin>>a[i][j];
      if(i==j)
      b[i]=a[i][j];
     }

    cout<<"\nThe matrix is\n\n";
    for(i=0;i<n;i++)
    { for(j=0;j<n;j++)
         cout<<a[i][j]<<"\t";
      cout<<"\n";}

    for(i=0,j=n-1;j>=0;j--,i++)
    { temp=a[i][j];
      a[i][j]=b[i];
      b[i]=temp;
    }

    for(i=0;i<n;i++)
    for(j=0;j<n;j++)
        if(i==j)
        a[i][j]=b[i];

    cout<<"\nNew Matrix after interchanging diagnols \n\n";

    for(i=0;i<n;i++)
    { for(j=0;j<n;j++)
         cout<<a[i][j]<<"\t";
      cout<<"\n";}

      return 0;
}
