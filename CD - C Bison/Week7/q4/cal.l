%{
#include<stdio.h>
#include<stdlib.h>
#include "cal.tab.h"

%}

%%
"+"|"-"|"*"|"/"|"^" {return OP;}
[0-9]    {return NUMBER;}
'n' {return N;}
\n {return NL;}
%%

int yywrap()
{return 1;
}
