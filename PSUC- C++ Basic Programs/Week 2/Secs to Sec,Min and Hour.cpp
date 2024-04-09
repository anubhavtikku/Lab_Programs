#include<iostream>
using namespace std;
int main()
{
    int sec,s,m,h;
    cout<<"Enter sec\n";
    cin>>sec;
    h=sec/3600;
    s=sec%60;
    m=(sec%3600)/60;
    cout<<"Hours "<<h<<" Minutes "<<m<<" Seconds "<<s;
    return 0;
}
