#include<iostream>
using namespace std;
int main()
{
    int a[10][10],b[10][10],c[10][10],i,j,m,n,e,f;
    cout<<"Enter the dimensions of first matrix ";
    cin>>m>>n;
    cout<<"\nEnter its elements ";
    for(i=0;i<m;i++)
    for(j=0;j<n;j++)
    cin>>a[i][j];
    cout<<"\nEnter the dimensions of second matrix ";
    cin>>e>>f;
    cout<<"\nEnter its elements ";
    for(i=0;i<e;i++)
    for(j=0;j<f;j++)
    cin>>b[i][j];
    if((e!=m)||(f!=n))
    cout<<"Addition not possible ";
    else
    { for(i=0;i<m;i++)
      for(j=0;j<n;j++)
      c[i][j]=a[i][j]+b[i][j];
      cout<<"\n\nThe sum of matrices is\n";
      for(i=0;i<m;i++)
      {for(j=0;j<n;j++)
       cout<<c[i][j]<<"\t";
       cout<<"\n";
        }
    }
return 0;
}
