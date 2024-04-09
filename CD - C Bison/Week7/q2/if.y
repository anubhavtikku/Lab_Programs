%{
	#include <stdio.h>	
	#include <stdlib.h>
	extern FILE *yyin;
%}

%token NUMBER ID DATATYPE ADDOP MULOP IF ELSE RELOP MAIN

%%
program : MAIN '(' ')' '{' declarations statement_list '}' {printf("Success\n"); exit(0);};

declarations: DATATYPE identifier_list ';' declarations | ;

identifier_list: ID | ID '[' NUMBER ']' | ID ',' identifier_list | ID '[' NUMBER ']' ',' identifier_list;

statement_list: statement statement_list | ;

statement: assign_stat ';' | decision_stat;

assign_stat: ID '=' expn;

expn: simple_exp eprime;

eprime: RELOP simple_exp | ;

simple_exp: term seprime;

seprime: ADDOP term seprime | ;

term: factor tprime;

tprime: MULOP factor tprime | ;

factor: ID | NUMBER;

decision_stat: IF '(' expn ')' '{' statement_list '}' dprime;

dprime: ELSE '{' statement_list '}' | ;

%%

int yyerror(char *msg)
{
	printf("Invalid Expression\n");
	exit(0);
}

void main()
{
	yyin = fopen("input.c", "r");
	yyparse();
}
