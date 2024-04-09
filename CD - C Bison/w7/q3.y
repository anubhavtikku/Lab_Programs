%{
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define YYSTYPE double
int yylex();
int yyerror();
extern FILE *yyin;
%}

%token NUMBER PLUS MINUS MUL DIV NL
%left PLUS MINUS MUL DIV

%start input
%%
input:
     | input line
	;
line:NL
     | exp NL { printf("Result: %f\n", $1); }
	;
exp:
     NUMBER { $$=$1; }
| exp PLUS exp { $$=$1+$3; }
| exp MINUS exp { $$=$1-$3; }
| exp MUL exp { $$=$1*$3; }
| exp DIV exp { $$=$1/$3; }
;
%%

int yyerror(char *msg)
{
printf("Invalid Expression\n");
return 1;
}

void main()
{
//printf("Enter the expression\n");
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