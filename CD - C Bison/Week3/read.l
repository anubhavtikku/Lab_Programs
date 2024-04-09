%{
int p=0;
int s=0;
%}

%%
printf {p++;fprintf(yyout,"write");}
scanf {s++;fprintf(yyout,"read");}
%%

int main()
{yyin=fopen("f1.c","r");
yyout=fopen("f2.c","w");
yylex();
printf("Printf=%d\nScanf=%d",p,s);
}

int yywrap()
{return 1;}
