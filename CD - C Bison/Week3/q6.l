%{
	#include <stdio.h>
	#include <stdlib.h>
	int row=1, col=1;
%}

%%

"/*".*"*/" {int i=0;
	while(yytext[i]!='\0'){
		if(yytext[i]=='\n') {row++; col=1;}
		else col++;
		i++;
	}
}
"#".*"\n" {}
"//".*"\n" {row++; col=1;}
(\".*\") {col+=strlen(yytext);}
(\'.\') {col+=strlen(yytext);}
"\n" {row++; col=1;}
"if"|"else"|"for"|"while"|"int"|"float"|"double"|"do"|"char"|"return" {printf("lexeme:%s, row:%d, column:%d, type:Keyword\n", yytext, row, col); col+=strlen(yytext);}
"&&"|"||"|"!" {printf("lexeme:%s, row:%d, column:%d, type:Logical Operator\n", yytext, row, col); col+=strlen(yytext);}
"<"|">"|"<="|">="|"=="|"!=" {printf("lexeme:%s, row:%d, column:%d, type:Relational Operator\n", yytext, row, col); col+=strlen(yytext);}
"+"|"-"|"/"|"*"|"++"|"--"|"%" {printf("lexeme:%s, row:%d, column:%d, type:Arithmetic Operator\n", yytext, row, col); col+=strlen(yytext);}
"+="|"-="|"*="|"/="|"=" {printf("lexeme:%s, row:%d, column:%d, type:Assignment Operator\n", yytext, row, col); col+=strlen(yytext);}
","|";"|"["|"]"|"{"|"}"|"("|")" {printf("lexeme:%s, row:%d, column:%d, type:Special Symbol\n", yytext, row, col); col+=strlen(yytext);}
[a-z_][a-zA-Z0-9_]* {printf("lexeme:%s, row:%d, column:%d, type:Identifier\n", yytext, row, col); col+=strlen(yytext);}
. {col++;}

%%

int main(){
	yyin = fopen("f1.c", "r");
	yyout = fopen("f2.c", "w");
	yylex();
}

int yywrap(){
	return 1;
}

