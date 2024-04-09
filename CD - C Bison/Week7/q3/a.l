%{
#include<stdio.h>
#include<stdlib.h>
#include "arith.tab.h"

int out=0;
char a='+';
%}

%%
[0-9]+ {//printf("%s\n",yytext);
        //out+=atoi(yytext);
        switch(a)
        { case '+':out+=atoi(yytext);
          break;
          case '-':out-=atoi(yytext);
	  break;
          case '*':out*=atoi(yytext);
          break;
          case '/':out/=atoi(yytext);
          break;
         }

        return NUMBER;}
\n {printf("\nOutput is %d\n",out);return NL;}
[a-zA-Z]+ {printf("%s\n",yytext);return ID;}
"+"|"-"|"*"|"/" {//printf("%s\n",yytext);
                a=yytext[0];return OP;}
%%

int yywrap()
{return 1;
}
