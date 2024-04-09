#include<iostream>
using namespace std;
int main()
{
    int a[10][10],b[10][10],c[10][10],i,j,m,n,x,y,k;
    cout<<"Enter dimensions of first matrix ";
    cin>>m>>n;
    cout<<"\nEnter its elements ";
    for(i=0;i<m;i++)
    for(j=0;j<n;j++)
    cin>>a[i][j];
    cout<<"\nEnter dimensions of second matrix ";
    cin>>x>>y;
    cout<<"\nEnter its elements ";
    for(i=0;i<x;i++)
    for(j=0;j<y;j++)
    cin>>b[i][j];
    if(n==x)
    {
    for(i=0;i<m;i++)
    for(j=0;j<y;j++)
        c[i][j]=0;

    for(i=0;i<m;i++)
    for(j=0;j<y;j++)
    for(k=0;k<n;k++)
    c[i][j]+=a[i][k]*b[k][j];
    cout<<"\n\nThe product matrix is\n\n";
    for(i=0;i<m;i++)
    { for(j=0;j<y;j++)
        cout<<c[i][j]<<"\t";
      cout<<"\n";}

    }
else
    cout<<"Multiplication not possible ";

return 0;
}
