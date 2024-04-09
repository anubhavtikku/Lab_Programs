#include<iostream>
using namespace std;
int main()
{
    int n,x,sum=0,fact,rem;
    cout<<"Enter number ";
    cin>>n;
    x=n;
    while(n>0)
    { rem=n%10;
      n=n/10;
      fact=1;
      for(int i=2;i<=rem;i++)
        fact=fact*i;
      sum=sum+fact;
        }
     if(x==sum)
      cout<<"Strong Number ";
     else
        cout<<"Not a Strong Number ";
     return 0;
}
