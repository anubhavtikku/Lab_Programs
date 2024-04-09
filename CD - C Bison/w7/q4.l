%{
	#include "q4b.tab.h"
	#include <stdio.h>
	#include <stdlib.h>
%}

%%
[0-9] {printf("num %s\n",yytext);return NUMBER;}
"+" {return PLUS;}
"-" {return MINUS;}
"*" {return MUL;}
"/" {return DIV;}
"^" {return POW;}
\n {printf("Newline\n");return NL;}
%%
