%{
int c=0;
%}

%%
" and " {c=1;}
" or " {c=1;}
" but " {c=1;}
. {}
%%

int main()
{yylex();
if(c==0)
printf("Simple Statement");
else
printf("Compound Statement");
}

int yywrap()
{return 1;
}
