#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void s();
void A();
void AA();
void B();

char str[100];

int k=0;

void error()
{ printf("Error String not part of grammer ");
  exit(0);
}

void s()
{
  if(str[k]=='a')
  {k++;
   A();

   if(str[k]=='c')
   k++;
   else
   error();

   B();

   if(str[k]=='e')
   k++;
   else
   error();

  }
  else
  error();

  
}

void A()
{
  if(str[k]=='b')
  {k++;
   AA();
   }

   else
   error();
  
}

void AA()
{
  if(str[k]=='b')
  {k++;
   AA();
  }

}

void B()
{

 if(str[k]=='d')
 k++;
 
 else
 error();
 
}


int main()
{printf("Enter the string ");
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
