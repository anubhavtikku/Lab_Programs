%{
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "symTable.c"
#define TABLE_SIZE 10

TOKEN* SYMTABLE[TABLE_SIZE];

char keywords[32][20] = {"auto", 	"break", 	"case", 	"char",
"const", 	"continue", 	"default",	"do",
"double",	"else", 	"enum", 	"extern",
"float", 	"for", 	"goto", 	"if",
"int", 	"long", 	"register", 	"return",
"short", 	"signed", 	"sizeof", 	"static",
"struct", 	"switch", 	"typedef",	"union",
"unsigned", 	"void", 	"volatile", 	"while"};

int matchKeyword(char* word) {
	int i;
	for(i=0; i<32; i++) {
		if(strcmp(keywords[i],word)==0) {
			return 1;
		}
	}
	return 0;
}

int flag;
int countArgs(char* buf, int pos) {
	int res;
	if(buf[pos]==')')res=0;
    else res=1;
	while(buf[pos]!=')') {
		if(buf[pos++]==',')res++;
	}
	return res;
}

void handleFunction(char* buffer) {
	TOKEN* f = newToken();
	f->isFunction=1;
	int i=0,k=0;
	char rt[10], name[10];
	char argDatatype[10], argName[10];
	

	while(buffer[i]!=' ') {
		rt[k++] = buffer[i++];
	}
	rt[k] = '\0';
	strcpy(f->returnType,rt);

	
	i++;
	k=0;
	while(buffer[i]!='(') {
		name[k++] = buffer[i++];
	}
	name[k] = '\0';
	strcpy(f->name, name);
	

	i++;
	k=0;
	int argCount=countArgs(buffer,i);
	initialiseArgs(f,argCount);
	int counter=0;
	while(buffer[i]!=')') {
		while(buffer[i]!=' ') {
			argDatatype[k++] = buffer[i++];
		}
		argDatatype[k] = '\0';
		

		i++;
		k=0;
		while(buffer[i]!=',' && buffer[i]!=')') {
			argName[k++] = buffer[i++];
		}
		argName[k]='\0';
		int argIndex = searchTable(SYMTABLE,argName);
		if(argIndex==-1) {
			argIndex = hashFunction();
			TOKEN* argToken = newToken();
			argToken->index = argIndex;
			argToken->isFunction=0;
			argToken->scope = flag;
			strcpy(argToken->name,argName);
			strcpy(argToken->datatype,argDatatype);
			SYMTABLE[argToken->index] = argToken;
		}
		f->argsID[counter++] = argIndex;
		k=0;
		if(buffer[i]==')')break;
		i++;
		while(buffer[i]==' '||buffer[i]=='\t')i++;
	}
	f->index = hashFunction();
	f->scope = flag;
	SYMTABLE[f->index] = f;
}

void handleID(char* buffer) {
	int i=0,k=0;
	char datatype[10], varName[10];
	while(buffer[i]!=' ') {
		datatype[k++] = buffer[i++];
	}
	datatype[k] = '\0';
	if(matchKeyword(datatype)!=1)return;
	i++;
	k=0;
	while(buffer[i]!='\0') {
		varName[k++] = buffer[i++];
	}
	varName[k] = '\0';
	int index = searchTable(SYMTABLE,varName);
	if(index!=-1)return;
	TOKEN* t = newToken();
	t->isFunction=0;
	t->scope=flag;
	strcpy(t->name,varName);
	strcpy(t->datatype,datatype);
	index = hashFunction();
	t->index = index;
	SYMTABLE[index]=t;
}


%}
functionDatatype ["char"|"int"|"double"|"float"]
id [a-zA-Z_][a-zA-Z0-9_]*
functionName {functionDatatype}[(][.]*[)]

%%
{id}[ ]{id}"("[^)]*")" handleFunction(yytext);
{id}[ ]{id} handleID(yytext);
\{ {flag=1;}
\} {flag=0;}
%%

int main() {
	yyin=fopen("f1.c","r");
	yyout = fopen("f2.c","w");
	initialiseTable(SYMTABLE);
	yylex();
	printSymbolTable(SYMTABLE);
	return 0;
}
int yywrap() {
	return 1;
}