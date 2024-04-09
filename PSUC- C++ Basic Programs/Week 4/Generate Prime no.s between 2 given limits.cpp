#include<iostream>
using namespace std;
int main()
{   int i,m,n;
    cout<<"Enter lower limit and upper limit ";
    cin>>m>>n;

    for(i=m+1;i<n;i++)
    {
        int Prime=1;
        for(int j=2;j<i;j++)
            if(i%j==0)
        { Prime=0;
          break;
        }
        if(Prime==1)
            cout<<"\n"<<i<<" is prime ";

    }
    return 0;
}
