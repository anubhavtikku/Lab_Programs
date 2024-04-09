#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void e();
void ee();
void t();
void tt();
void f();

char str[100];

int k=0;

void error()
{ printf("Error String not part of grammer ");
  exit(0);
}

void e()
{t();
 ee();
}

void ee()
{

if(str[k]=='+')
{k++;
 t();
 ee();
}
} 

void t()
{f();
 tt();
}

void tt()
{
  if(str[k]=='*')
  {k++;
   f();
   tt();
  }

}

void f()
{
if(str[k]=='(')
 {k++;
  e();
  if(str[k]==')')
  k++;
  else
  error();
 }

 else if(str[k]=='i' && str[k+1]=='d')
 k=k+2;
   
 else
 error();
}

int main()
{printf("Enter the string ");
scanf("%s",str);

int l=strlen(str);

str[l]='$';

e();

if(k==l)
printf("String is a part of grammar ");
else
printf("String is not a part of grammar ");

return 0;
}
