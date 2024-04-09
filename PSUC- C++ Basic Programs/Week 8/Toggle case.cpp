#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{   char s[100];
    int i;
    cout<<"Enter string ";
    gets(s);

    for(i=0;s[i]!='\0';i++)
    {   int m=0;
        if((s[i]<91)&&(s[i]>64))
            m=1;
        if((s[i]<124)&&(s[i]>96))
            m=2;
        if(m==1)
            s[i]+=32;
        if(m==2)
            s[i]-=32;
        }
    cout<<"\n"<<s;
}
