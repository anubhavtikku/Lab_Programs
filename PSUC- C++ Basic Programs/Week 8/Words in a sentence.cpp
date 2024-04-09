#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    char s[100];
    int count=1,i;
    cout<<"Enter a sentence ";
    gets(s);
    for(i=0;s[i]!='\0';i++)
        if((s[i] ==' ')&& (s[i+1]!=' '))
        count++;
    cout<<"\nNo. of words in sentence are "<<count;
}
