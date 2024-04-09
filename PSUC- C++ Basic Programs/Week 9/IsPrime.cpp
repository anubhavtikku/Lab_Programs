#include<iostream>
using namespace std;
int isprime(int x)
{
    int t=1;
    for(int i=2;i<x;i++)
        if(x%i==0)
        { t=0;
          break;}
    if(t==1)
    return 1;
    else
    return 0;
}

int main()
{
    int n,a=0;
    cout<<"No. of prime numbers wanted ";
    cin>>n;
    for(int i=2;;i++)
    { if(a==n)
      break;

      if(isprime(i)==1)
      { ++a;
         cout<<i<<"\t";
      }

    }
   return 0;
}
