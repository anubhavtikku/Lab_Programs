#include<iostream>
using namespace std;
int main()
{
    int x=1,n,i,j;
    cout<<"Enter limit of Floyds Triangle ";
    cin>>n;
    for(i=1;i<=n;i++)
    {  for (j=0;j<i;j++)
       { cout<<x<<"\t";
         x=x+1;
       }
    cout<<"\n";
    }
    return 0;

}
