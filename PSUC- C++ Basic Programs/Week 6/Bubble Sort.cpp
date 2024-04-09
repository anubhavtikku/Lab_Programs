#include<iostream>
using namespace std;
int main()
{
    int a[100],n,i,j,temp,m;
    cout<<"Enter the number of elements you want to enter ";
    cin>>n;
    cout<<"Enter "<<n<<" elements ";
    for(i=0;i<n;i++)
        cin>>a[i];

    cout<<"\nTo arrange in Ascending order press 1 and to arrange in descending order press 2 ";
    cin>>m;
    cout<<"\n";
    if(m==2)
    { for(j=n-1;j>=0;j--)  //Desc
        for(i=0;i<j;i++)
        if(a[i+1]>a[i])
        { temp=a[i];
          a[i]=a[i+1];
          a[i+1]=temp;
        }
    for(i=0;i<n;i++)
        cout<<a[i]<<"\n";
    }
   else if(m==1)
   { for(j=n;j>=0;j--)  //Asce
        for(i=0;i<j;i++)
        if(a[i]>a[i+1])
        { temp=a[i];
          a[i]=a[i+1];
          a[i+1]=temp;
        }
   for(i=0;i<n;i++)
    cout<<a[i]<<"\n";
   }
   else
    cout<<"Wrong No. pressed ";
    return 0;
}
