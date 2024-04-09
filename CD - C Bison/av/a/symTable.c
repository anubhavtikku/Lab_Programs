#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TABLE_SIZE 10

int hashIndex=0;

typedef struct {
	int index;
	char name[10];
	int scope;
	char datatype[10];
	int isFunction;
	char returnType[10];
	int argCount;
	int* argsID;
}TOKEN;

TOKEN* newToken() {
	TOKEN* temp = (TOKEN*)malloc(sizeof(TOKEN));
	return temp;
}
TOKEN* initialiseArgs(TOKEN* f, int argCount) {
	f->argCount = argCount;
	f->argsID = (int*)calloc(argCount,sizeof(int));
	int i;
	for(i=0; i<argCount; i++) {
		f->argsID[i]=-1;
	}
}


int hashFunction() {
	return hashIndex++;
}

void initialiseTable(TOKEN* SYMTABLE[TABLE_SIZE]) {
	int i;
	for(i=0; i<TABLE_SIZE; i++) {
		SYMTABLE[i] = NULL;
	}
}

void printToken(TOKEN* t) {
	printf("%d\t%s\t",t->index,t->name );
	if(t->isFunction==1) {
		printf("%s\t%d\t",t->returnType, t->argCount);
		int i;
		for(i=0; i<t->argCount; i++) {
			printf("%d\t",t->argsID[i]);
		}
	} else {
		printf("%s\t",t->datatype);
	}
	t->scope==1?printf("L\n"): printf("G\n");
}

void printSymbolTable(TOKEN* SYMTABLE[]) {
	int i;
	for(i=0; i<TABLE_SIZE; i++) {
		if(SYMTABLE[i]==NULL)
			continue;
		printToken(SYMTABLE[i]);
	}
}

int searchTable(TOKEN* SYMTABLE[TABLE_SIZE], char* item) {
	int i; 
	for(i=0; i<TABLE_SIZE; i++) {
		if(SYMTABLE[i]!=NULL && strcmp(SYMTABLE[i]->name,item)==0) return i;
	}
	return -1;
}
