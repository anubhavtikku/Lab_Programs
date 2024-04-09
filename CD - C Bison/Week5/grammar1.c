#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void s();
void t();
void tt();

char str[100];

int k=0;

void error()
{ printf("Error String not part of grammer ");
  exit(0);
}

void s()
{
  if(str[k]=='a')
  k++;
  else if(str[k]=='>')
  k++;
  else if(str[k]=='(')
  {k++;
   t();
   if(str[k]==')')
   k++;
   else
   error();
  }
  else
  error();

  
}

void t()
{
  s();
  tt();
}

void tt()
{

 if(str[k]==',')
 {k++;
  s();
  tt();
 }
 
 
}

int main()
{

printf("Enter the string ");
scanf("%s",str);

int l=strlen(str);

str[l]='$';

s();

if(k==l)
printf("String is a part of grammar ");
else
printf("String is not a part of grammar ");

return 0;
}
