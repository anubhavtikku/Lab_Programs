%{
#include<stdio.h>
#include<stdlib.h>
int yylex();
int yyerror();
extern FILE *yyin;
%}

%token NL ID NUMBER INT CHAR SS CO

%%
stmt:DC NL
     ;
DC: DT IDL SS
     |
     ;
DT: INT
	| CHAR
     ;
IDL:ID
    | ID CO IDL
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
printf("Success\n");
}