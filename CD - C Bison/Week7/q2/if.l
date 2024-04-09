%{
	#include "if.tab.h"

      int l=0;
%}

%%
"main" {return MAIN;}

"char"|"int" {return DATATYPE;}

">"|"<"|"<="|">="|"!=" {return RELOP;}

"+"|"-" {return ADDOP;}

"*"|"/"|"%" {return MULOP;}

"if" {l++;printf("Level is %d\n",l);return IF;}

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
