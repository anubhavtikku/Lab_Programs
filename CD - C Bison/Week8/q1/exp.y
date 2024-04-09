%{
	#include <stdio.h>	
	#include <stdlib.h>
	extern FILE *yyin;
   	int yyerror();
	int yylex();
%}

%token NUMBER ID ARITH REL LOG

%%
stmt: VAR ARITH EX | VAR LOG EX | VAR REL EX
    ;

EX:VAR ARITH EX| VAR LOG EX | VAR REL EX|VAR
   ;
VAR:NUMBER|ID
   ;
%%

int yyerror(char *msg)
{
	printf("Invalid Expression\n");
	exit(0);
}

void main()
{       printf("Enter the expression");
	//yyin = fopen("input.c", "r");
	yyparse();
        printf("Success");
}
