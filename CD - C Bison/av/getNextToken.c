#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "token.h"

char keywords[32][20] = {"auto", 	"break", 	"case", 	"char",
"const", 	"continue", 	"default",	"do",
"double",	"else", 	"enum", 	"extern",
"float", 	"for", 	"goto", 	"if",
"int", 	"long", 	"register", 	"return",
"short", 	"signed", 	"sizeof", 	"static",
"struct", 	"switch", 	"typedef",	"union",
"unsigned", 	"void", 	"volatile", 	"while"};

char builtIn[2][20] = {"printf","scanf"};

char arithmeticOperator[4] = {'+','-','/','*'};
char bitwise[3] = {'&','|','^'};
char relational[2] = {'<','>'};
char specialSymbol[12] = {'(',')','{','}',',',';',':','.','\'','\"','[',']'};
char num[10] = {'0','1','2','3','4','5','6','7','8','9'};

int isAlpha(char c) {
	if((c>='a'&&c<='z') || (c>='A' && c<='Z') || c=='_') {
		return 1;
	}
	return 0;
}

int isNum(char c) {
	int i;
	for(i=0; i<10; i++) {
		if(c==num[i]) return 1;
	}
	return 0;
}

int checkKeyword(char word[20]) {
	int i=0;
	for(i=0; i<32; i++) {
		if(strcmp(keywords[i],word)==0) return 1;
	}
	return 0;
}

int checkBuiltIn(char word[20]) {
	int i=0;
	for(i=0; i<2; i++) {
		if(strcmp(builtIn[i],word)==0)return 1;
	}
	return 0;
}

int checkSymbol(char c) {
	int i=0;
	for(i=0; i<12; i++) {
		if(specialSymbol[i]==c)return 1;
	}
	return 0;
}

int checkBitwise(char c) {
	int i=0;
	for(i=0; i<3; i++) {
		if(bitwise[i]==c)return 1;
	}
	return 0;
}

int checkOperator(char c) {
	int i=0;
	for(i=0; i<4; i++) {
		if(arithmeticOperator[i]==c) return 1;
	}
	return 0;
}

int checkRelational(char c) {
	int i;
	for(i=0; i<4; i++) {
		if(relational[i]==c)return 1;
	}
	return 0;
}

TOKEN* getNextToken(FILE* fa, int *row, int *col) {
	TOKEN* token = newToken();
	int ca,cb,k=0;
	ca = getc(fa);
	char* word = (char*)calloc(50,sizeof(char));
	if(ca=='\n') {
		(*row)++;
		*col=1;
		ca = getc(fa);
		while(ca=='\n') {
			(*row)++;
			ca = getc(fa);
		}
	}
	if(ca==' '||ca=='\t'||ca=='\n') {
		if(ca==' ') {
			(*col)+=1;
		} else if(ca=='\t') {
			(*col)+=4;
		} else if(ca=='\n') {
			(*row)++;
			*col=1;
		}
		ca = getc(fa);
		while(ca==' ') {
			(*col)+=1;
			ca = getc(fa);
		}
		while(ca=='\t') {
			(*col)+=4;
			ca = getc(fa);
		}
		while(ca=='\n') {
			(*row)+=1; 
			ca = getc(fa);
		}
	}
	if(ca=='\"' || ca=='\'') {
		// string literal
		ca = getc(fa);
		(*col)+=1;
		while(ca!='\"' && ca!='\'') {
			word[k++] = ca;
			ca = getc(fa);
			(*col)+=1;
		}
		word[k] = '\0';
		strcpy(token->type,"stringLiteral");
	}else if(isAlpha(ca)) {
		word[k++] = ca;
		ca = getc(fa);
		while((isAlpha(ca)==1) || (isNum(ca)==1)) {
			word[k++] = ca;
			ca = getc(fa);
		}
		word[k] = '\0';
		if(checkKeyword(word)==1) {
			 strcpy(token->type,"keyword");
		} else if(checkBuiltIn(word)==1) {
			strcpy(token->type,"builtIn");
		} else {
			// identifier
			strcpy(token->type,"identifier");
		}
		fseek(fa,(long)(-1),SEEK_CUR);
	} else if(isNum(ca)) {
		word[k++] = ca;
		ca = getc(fa);
		while(isNum(ca)==1) {
			word[k++] = ca;
			ca = getc(fa);
		}
		word[k] = '\0';
		fseek(fa,(long)(-1),SEEK_CUR);
		strcpy(token->type,"number");
	} 
	else if(checkSymbol(ca)==1) {
		word[k++] = ca;
		word[k] = '\0';
		strcpy(token->type, "specialSymbol");
	} else if(checkOperator(ca)==1) {
		while(checkOperator(ca)==1) {
			word[k++] = ca;
			ca = getc(fa);
		}
		word[k] = '\0';
		strcpy(token->type, "arithmeticOP");
		fseek(fa,(long)(-1),SEEK_CUR);
	} else if(checkRelational(ca)==1) {
		word[k++] = ca;
		ca = getc(fa);
		if(ca=='=') {
			word[k++] = ca;
		} else {
			fseek(fa,(long)(-1),SEEK_CUR);
		}
		word[k] = '\0';
		strcpy(token->type, "relationalOP");
	} else if(checkBitwise(ca)==1) {
		word[k++] = ca;
		int bitwiseFlag=1;
		ca = getc(fa);
		if(checkBitwise(ca)==1) {
			// relational
			word[k++] = ca;
			bitwiseFlag=0;
		} else {
			fseek(fa,(long)(-1),SEEK_CUR);
		}
		word[k] = '\0';
		if(bitwiseFlag) {
			strcpy(token->type,"bitwiseOperator");
		} else {
			strcpy(token->type,"logicalOperator");
		}
	} else if(ca=='=' || ca=='!') {
		word[k++] = ca;
		int assignmentFlag = 1;
		ca = getc(fa);
		if(ca=='=') {
			word[k++] = ca;
			assignmentFlag=0;
		} else {
			fseek(fa,(long)(-1),SEEK_CUR);
		}
		word[k]=  '\0';
		if(assignmentFlag) {
			strcpy(token->type,"assignmentOperator");
		} else {
			strcpy(token->type,"equality");
		}
	} else if(ca==EOF){
		// EOF
		return NULL;
	}
	strcpy(token->lexemeName,word);
	token->row = *row;
	token->col= *col;
	(*col)+=strlen(word);
	return token;
}

void retract(FILE* fa, int* row, int* col, TOKEN* tk) {
	int len = strlen(tk->lexemeName);
	*col = *col-len;
	// Not changing row
	fseek(fa,(long)(-len),SEEK_CUR);
	return;
}

