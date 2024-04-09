#include<iostream>
using namespace std;
#include<math.h>

int main()
{   int n,d=-1;
    double x,sum,term;
    cout<<"Enter the number of terms till which you want Sine series evaluated ";
    cin>>n;
    cout<<"Enter the value of Sine ";
    cin>>x;
    x=(x*3.1415)/180;
    term=x;
    sum=term;

    for(int i=1;i<n;i++)
    {   term*=(d*x*x)/(2*i*(2*i+1));
        sum+=term;


    }
    cout<<"Sin Value is "<<sum;
    cout<<"\nLibrary value of sin is "<<sin(x);
    return 0;

}
