%{
#include<stdio.h>
#include<stdlib.h>
int yylex();
int yyerror();
extern FILE *yyin;
%}

%token NL ID NUMBER OP
%left '+'
%left '-'
%left '*'
%left '/'

%%
stmt:DC NL
     ;

DC: DT|DT EXP DC 
     ;

DT:NUMBER
   ;
EXP: OP
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
yyin=fopen("in.txt","r");
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

