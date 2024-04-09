#include<iostream>
using namespace std;
int main()
{
   int x[]={0,1,2,3},y[]={0,2,8,27};
   double t1,t2,t3,t4,z,sum;
   cout<<"Enter number whose function value is to be found ";
   cin>>z;

   t1=((z-1)*(z-2)*(z-3)*y[0])/((-1)*(-2)*(-3));
   t2=( (z)*(z-2)*(z-3)*y[1])/(1*(-1)*(-2));
   t3=( (z)*(z-1)*(z-3)*y[2])/(2*1*(-1));
   t4=( (z)*(z-1)*(z-2)*y[3])/(3*2*1);
   sum=t1+t2+t3+t4;
   cout<<"Value of f("<<z<<") is "<<sum;
   return 0;
}
