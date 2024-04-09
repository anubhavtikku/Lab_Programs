#include<iostream>
using namespace std;
int main()
{
    int a[10][10],i,j,m,n,x,temp,e,f;

    cout<<"Enter dimensions of matrix ";
    cin>>m>>n;

    cout<<"\nEnter its elements ";
    for(i=0;i<m;i++)
    for(j=0;j<n;j++)
    cin>>a[i][j];

    cout<<"\nMatrix is\n";
    for(i=0;i<m;i++)
    {for(j=0;j<n;j++)
     cout<<a[i][j]<<"\t";
     cout<<"\n";}


    cout<<"\nEnter 1 to interchange rows and 2 to interchange columns ";
    cin>>x;

    if(x==1)
    { cout<<"Enter the two rows to be interchanged ";
      cin>>e>>f;
      for(j=0;j<n;j++)
      { temp=a[e-1][j];
        a[e-1][j]=a[f-1][j];
        a[f-1][j]=temp;
      }

     cout<<"\nThe new matrix is\n\n";
     for(i=0;i<m;i++)
    { for(j=0;j<n;j++)
      cout<<a[i][j]<<"\t";
      cout<<"\n";}
    }

if(x==2)
 { cout<<"Enter the two columns to be interchanged ";
      cin>>e>>f;
      for(i=0;i<n;i++)
      {temp=a[i][e-1];
       a[i][e-1]=a[i][f-1];
       a[i][f-1]=temp;  }

cout<<"\nThe new matrix is\n\n";
     for(i=0;i<m;i++)
    {for(j=0;j<n;j++)
     cout<<a[i][j]<<"\t";
     cout<<"\n";}
}

return 0;
}
