%{
	#include "exp.tab.h"

      
%}

%%
[0-9]+ {return NUMBER;}
[_A-Za-z] {return ID;}
"+"|"-"|"*"|"/"|"^" {return ARITH;}
"=="|">="|"<="|"!="|">"|"<" {return REL;}
"&&"|"||"|"!" {return LOG;}

%%

int yywrap()
{
	return 1;
}
