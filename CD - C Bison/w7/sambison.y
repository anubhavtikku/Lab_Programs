%{
	#include<stdio.h>
	#include<stdlib.h>
%}

%token NUMBER ID NL
%left '+'
%left '*'
%left '-'
%left '/'

%%
stmt: exp NL {printf("Valid Expression");exit(0);};
exp: exp op term | term
term: term op factor | factor
op: '+'|'-'|'*'|'/'
factor: ID | NUMBER;
%%

int yyerror(char *msg)
{
	printf("Invalid Expression\n");
	exit(0);
}

void main()
{
	printf("Enter the expression\n");
	yyparse();
}