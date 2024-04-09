%{
	#include "c.tab.h"

      
%}

%%
"main" {return MAIN;}

"char"|"int" {return DATATYPE;}

">"|"<"|"<="|">="|"!="|"==" {return RELOP;}

"while" {return WHILE;}

"for" {return FOR;}

"+"|"-" {return ADDOP;}

"*"|"/"|"%" {return MULOP;}

"if" {return IF;}

"else" {return ELSE;}


[0-9]+ {return NUMBER;}

[a-zA-Z][a-zA-Z0-9]* {return ID;}

" "|"\t"|"\n" {;}

. {return yytext[0];}
%%

int yywrap()
{
	return 1;
}
