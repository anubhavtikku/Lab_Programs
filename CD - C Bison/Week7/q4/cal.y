%{
#include<stdio.h>
#include<stdlib.h>
int yylex();
int yyerror();
extern FILE *yyin;
%}

%token NUMBER NL OP N

%%
INPUT:INPUT LINE
      |
     ;
LINE: NL | EXP NL
      ;
EXP:NUMBER | EXP EXP OP | EXP N
    ;

%%

int yyerror(char *msg)
{
printf("Invalid Expression\n");
return 1;
}

void main()
{
printf("Enter the expression\n");
//yyin=fopen("in.txt","r");
//yyin=stdin;

do
{
if(yyparse())
{
printf("\nFailure");
exit(0);}
}while(!feof(yyin));

printf("Success ");
}

