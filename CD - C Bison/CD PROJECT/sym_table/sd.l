%{
#include <stdio.h>
#include <stdlib.h>
#include "symbol1.h"

int scopeCount=0;
struct token *tk;

%}

%%
{
	("int"|"float"|"double"|"if"|"for"|"else"|"char"|"return"|"void"|"break"|"continue"|"callout"|"boolean") {
		struct keywordsPos ele;
		ele.keyword = malloc(100);
		strcpy(ele.keyword, yytext);
		ele.row = row;
		arr[cnt++] = ele;
		if(strcmp(yytext, "char")==0) {
			printf("%d\n", row);
		}
		col+=yyleng;
	}

	"{" {
		scopeCount+=1;
		col++;
	}

	"}" {
		scopeCount-=1;
		col++;
	}

	"class" {
		col+=yyleng;
	}
	
	"if(".*")"
          {col+=yyleng;
          }

	"Program" {
		col+=yyleng;
	}

	"main(".*")" {
		col+=yyleng;
	}

	"Print(".*")" {
		col+=yyleng;
	}

	"scanf(".*")" {
		col+=yyleng;
	}

	"#".* {
		row++;
		col=1;
	}

	"//".* {
		row++;
		col=1;
	}

	[/][*][^*]*[*]+([^*/][^*]*[*]+)*[/] {
		row++;
		col=1;
	}

	[a-zA-Z_][a-zA-Z0-9_]*"(".*")" {
		insert(yytext, FUNCTION, row, col, scopeCount);
		col+=yyleng;
	}

	[a-zA-Z_][a-zA-Z0-9]* {
		insert(yytext, IDENTIFIER, row, col, scopeCount);
		col+=yyleng;
	}

	[a-zA-Z_][a-zA-Z0-9]*"["[0-9]+"]" {
		insert(yytext, IDENTIFIER, row, col, scopeCount);
		col+=yyleng;
	}

	\n {
		row++;
		col=1;
	}

	. {
		col+=yyleng;
	}
}
%%

int main() {
	yyin = fopen("a1.txt", "r");
	yylex();
	display();
}

int yywrap() {
	return 1;
}

