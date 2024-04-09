#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<string.h>
using namespace std;

int main()
{   char ch,pass[50];
    cout<<"Enter password ";
    int i=0;
    do{
        ch=getch();
        if(ch=='\r')
            break;
        pass[i++]=ch;
        putch('*');
     } while(ch!='\r');

    if(strcmp("psuc",pass)==0)
        cout<<"\nPassword is correct ";
        else
        cout<<"\nIncorrect Password ";
        return 0;
}
