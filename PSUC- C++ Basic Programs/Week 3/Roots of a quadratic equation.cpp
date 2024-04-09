#include<iostream>
using namespace std;
#include<math.h>
int main()
{ float a,b,c,d,re,im,r1,r2;
  int i;
  cout<<"Enter the coefficients of a quadratic equation ax^2+bx+c ";
  cin>>a>>b>>c;
  d=(b*b)-(4*a*c);
   if(d>0)
   i=1;

   else if(d==0)
   i=0;

   else
   i=2;

  switch(i)
  {
      case 0: r1=r2=((-1)*b)/(2*a);
              cout<<"The roots are real and equal : "<<r1<<" and "<<r2;
              break;

      case 1: r1= ((-1)*b+sqrt(d))/(2*a);
              r2= ((-1)*b-sqrt(d))/(2*a);
              cout<<"The roots are real : "<<r1<<" and "<<r2;
              break;

      case 2: d=d*(-1);
              r1= ((-1)*b)/(2*a);
              im= sqrt(d)/(2*a);
              cout<<"The roots are imaginary: "<<r1<<"+i"<<im<<" and "<<r1<<"-i"<<im;
              break;

  }
  return 0;
}
