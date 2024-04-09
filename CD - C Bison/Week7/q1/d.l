%{
#include<stdio.h>
#include<stdlib.h>
#include "dec.tab.h"
%}

%%
[0-9]+ {printf("%s\n",yytext);return NUMBER;}
\n {return NL;}
"int" {printf("%s\n",yytext);return INT;}
[a-zA-Z]+ {printf("%s\n",yytext);return ID;}
"," {printf(",\n");return CO;}
";" {printf(";\n");return SS;}
%%

int yywrap()
{return 1;
}
