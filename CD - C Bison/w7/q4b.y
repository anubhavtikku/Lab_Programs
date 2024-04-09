%{
	#include<stdio.h>
	#include<stdlib.h>
	int yylex();
	int yyerror();
	extern FILE *yyin;
%}

%token NUMBER NL PLUS  MINUS MUL DIV POW
%left PLUS MINUS MUL DIV POW

%%
input: input line
		| 
		;
line: NL | exp NL
		;
exp: NUMBER | exp exp PLUS |exp exp MINUS |exp exp MUL |exp exp DIV |exp exp POW| exp NL
		;
%%

int yyerror(char *msg)
{
printf("%s",msg);
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