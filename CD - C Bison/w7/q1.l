%{
	#include "q1.tab.h"
	#include <stdio.h>
	#include <stdlib.h>
%}

%%
[0-9]+ {printf("%s\n",yytext);return NUMBER;}
\n {printf("Newline\n");return NL;}
"int" {printf("%s\n",yytext);return INT;}
"char" {printf("%s\n",yytext);return CHAR;}
[a-zA-Z][a-zA-Z0-9]* {printf("%s\n",yytext);return ID;}
";" {printf(";\n");return SS;}
"," {printf(",\n");return CO;}
%%
