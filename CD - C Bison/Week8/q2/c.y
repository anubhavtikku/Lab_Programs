%{
	#include <stdio.h>	
	#include <stdlib.h>
	extern FILE *yyin;
   	int yyerror();
	int yylex();
%}

%token NUMBER ID DATATYPE ADDOP MULOP IF ELSE RELOP MAIN WHILE FOR

%%
program : MAIN '(' ')' '{' declarations statement_list '}' {printf("Success\n"); exit(0);};

declarations: DATATYPE identifier_list ';' declarations | ;

identifier_list: ID | ID '[' NUMBER ']' | ID ',' identifier_list | ID '[' NUMBER ']' ',' identifier_list;

statement_list: statement statement_list | ;

statement: assign_stat ';' | decision_stat |looping_stat ;

assign_stat: ID '=' expn;

looping_stat: WHILE '(' expn ')' '{' statement_list '}'
             | FOR '('assign_stat ';' expn ';' assign_stat ')' '{' statement_list '}'
		;

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

int main()
{
//	#ifdef YYDEBUG
//		yydebug=1;
//	#endif
	yyin = fopen("input.c", "r");
	yyparse();
        printf("Success");
return 1;
}
