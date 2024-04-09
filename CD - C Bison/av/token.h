#ifndef token_h
#define token_h
#include <string.h>

typedef struct {
	char* lexemeName;
	char* type;
	unsigned int row,col; //Line numbers.
}TOKEN;

TOKEN* newToken() {
	TOKEN* temp = (TOKEN*)malloc(sizeof(TOKEN));
	temp->lexemeName = (char*)calloc(20,sizeof(char));
	temp->type = (char*)calloc(20,sizeof(char));
	return temp;
}

void printToken(TOKEN* token) {
	printf("<%s,%s,%d,%d>\n",token->lexemeName,token->type,token->row,token->col);
}

#endif

