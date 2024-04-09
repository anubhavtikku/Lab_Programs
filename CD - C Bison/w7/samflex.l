%{
	#include "sambison.tab.h"
	#include <stdio.h>
	#include <stdlib.h>
%}

%%
[0-9]+ {return NUMBER;}
\n {return NL;}
[a-zA-Z][a-zA-Z0-9]* {return ID;}
. {return yytext[0];}
%%
