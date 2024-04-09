#include<iostream>
using namespace std;
int main()
{  int x,y,z,largest;
   cout<<"Enter three numbers ";
   cin>>x>>y>>z;
    largest=x;
    if(y>largest)
        largest=y;
    if(z>largest)
        largest=z;
    cout<<"The largest no. is "<<largest;
    return 0;
}
