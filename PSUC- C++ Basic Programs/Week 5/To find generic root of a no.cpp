#include<iostream>
using namespace std;
int main()
{   int x,z,sum,rem,y=0;
    cout<<"Enter number ";
    cin>>x;
    z=x;
       do
       {
         sum=0;
        while(x>0)
        { rem=x%10;
          x=x/10;
          sum+=rem;
        }
        if(sum!=0)
            y=sum;
        x=sum;

       } while(sum>9);

    cout<<"The generic root of "<<z<<" is "<<y;
    return 0;
    }

