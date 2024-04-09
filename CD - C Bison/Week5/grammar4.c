#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void lexp();
void lexp_seq();
void lexp_seqq();

char str[100];

int k=0;

void error()
{ printf("Error String not part of grammer ");
  exit(0);
}

void lexp()
{
  if(strncmp(str+k,"number",6)==0)
  k=k+6;

  else if(strncmp(str+k,"identifier",10)==0)
  k=k+10;
 
  else if(str[k]=='(')
  {     k++;
	lexp_seq();
        if(str[k]==')')
        k++;
        else
        error();
  }
  
  else
  error();
}

void lexp_seq()
{ lexp();
  lexp_seqq();
}

void lexp_seqq()
{ 

  if(strncmp(str+k,"number",6)==0)
  {k=k+6;lexp_seqq();}

  else if(strncmp(str+k,"identifier",10)==0)
  {k=k+10;lexp_seqq();}
 
  else if(str[k]=='(')
  {     k++;
	lexp_seq();
        if(str[k]==')')
        k++;
        else
        error();
        lexp_seqq();
  }

}

int main()
{printf("Enter the string ");
scanf("%s",str);

int l=strlen(str);

str[l]='$';

lexp();

if(k==l)
printf("String is a part of grammar ");
else
printf("String is not a part of grammar ");

return 0;
}
