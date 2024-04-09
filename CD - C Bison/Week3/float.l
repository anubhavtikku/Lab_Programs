%{
int pint=0;
int nint=0;
int pfloat=0;
int nfloat=0;
%}

%%
[+]?[0-9]+ {pint+=1;}
[+]?[0-9]+[\.][0-9]+ {pfloat+=1;}
[-][0-9]+ {nint+=1;}
[-][0-9]+[\.][0-9]+ {nfloat+=1;}
%%

int main()
{yylex();
printf("Positive Integers=%d\nNegative Integers=%d\nPositive Floats=%d\nNegative Floats=%d\n",pint,nint,pfloat,nfloat);
}

int yywrap()
{return 1;}
