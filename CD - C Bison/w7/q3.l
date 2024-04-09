%{
#define YYSTYPE double
#include "q3.tab.h"
#include <stdlib.h>
%}

white [ \t]+
digit [0-9]
integer {digit}+
real {integer}("."{integer})?

%%

{white} { }
{real} { yylval=atof(yytext); 
 return NUMBER;
}
"+" {return PLUS;}
"-" {return MINUS;}
"*" {return MUL;}
"/" {return DIV;}
"\n" {return NL;}
%%