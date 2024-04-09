#include <iostream>
using namespace std ;

int main()
{
    int n,i,j;
    float p,x[20],y[20],sum=0.0,temp = 1;
    cout<<"Enter the no of records ";
    cin>>n ;
    cout<<"\nEnter the value of x for which we want to find f(x) ";
    cin>>p;
    for(int i=0;i<n;i++)
    {
        cout<<"Enter the value of x"<<i<<": ";
        cin>>x[i];
        cout<<"Enter the value of f(x"<<i<<"): " ;
        cin>>y[i];
    }
    for (i=0;i<n;i++)
    {
         temp=1 ;
         for (j=0;j<n;j++)
         {
            if (i==j)
            {
            continue;
            }
            else
            {
            temp*= ( (p-x[j]) / (x[i]-x[j])) ;
            }

         }
         sum+= (temp * y[i]) ;
    }
    cout<<"\nf("<<p<<") = "<<sum;
}
