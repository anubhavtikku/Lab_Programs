#include <stdio.h>
#include <stdlib.h>
#include "token.h"
#include "unwanted.h"
#include "getNextToken.c"


void assign_stat(FILE* fa, int* row, int* col);
void case_stat(FILE* fa, int* row, int* col);
void declarations(FILE* fa, int* row, int* col);
void decision_stat(FILE* fa, int* row, int* col);
void default_stat(FILE* fa, int* row, int* col);
int equals(char* a, char* b);
void Error(int* row, int* col, char*msg );
void expression(FILE* fa, int* row, int* col);
void e_prime(FILE* fa, int* row, int* col);
void factor(FILE* fa, int* row, int* col);
void for_stat(FILE* fa, int* row, int* col);
TOKEN* identifier_list(FILE* fa, int* row, int* col);
int isAddOp(TOKEN* lookahead);
int isEquality(TOKEN* lookahead);
int isLooping(TOKEN* lookahead);
int isMulOp(TOKEN* lookahead);
int isRelop(TOKEN* lookahead);
int isTerm(TOKEN* lookahead);
void i_prime(FILE* fa, int* row, int* col);
void matchLexemeName(FILE* fa,int* row, int* col, char* symbol);
void output_stat(FILE* fa, int* row, int* col);
void program(FILE* fa);
void return_stat(FILE* fa, int* row, int* col);
void se_prime(FILE* fa, int* row, int* col);
void simple_expression(FILE* fa, int* row, int* col);
void statement_list(FILE* fa, int* row, int* col);
void switch_stat(FILE* fa, int* row, int* col);
void while_stat(FILE* fa, int* row, int* col);

void assign_stat(FILE* fa, int* row, int* col) {
	TOKEN* lookahead = getNextToken(fa,row,col);
	printToken(lookahead);
	if(!equals(lookahead->type,"identifier")) {
		Error(row,col,"Expected identifier");
	}
	lookahead = getNextToken(fa,row,col);
	if(equals(lookahead->lexemeName,"[")) {
		lookahead = getNextToken(fa,row,col);
		printToken(lookahead);
		if(isTerm(lookahead)) {
			matchLexemeName(fa,row,col,"]");
		} else {
			Error(row,col,"Expected identifier or numeric value");
		}
	} else {
		retract(fa,row,col,lookahead);
	}
	matchLexemeName(fa,row,col,"=");
	expression(fa,row,col);
}

void case_stat(FILE* fa, int* row, int* col) {
	// case_stat-->case term: statement_list case_stat| epsilon
	TOKEN* lookahead = getNextToken(fa,row,col);
	printToken(lookahead);
	printf("in case_stat\n");
	if(equals(lookahead->lexemeName,"case")) {
		lookahead = getNextToken(fa,row,col);
		printToken(lookahead);
		if(isTerm(lookahead)) {
			matchLexemeName(fa,row,col,":");
			statement_list(fa,row,col);
			lookahead = getNextToken(fa,row,col);
			printToken(lookahead);
			if(equals(lookahead->lexemeName,"break")) {
				matchLexemeName(fa,row,col,";");
			} else {
				retract(fa,row,col,lookahead);
			}
			case_stat(fa,row,col);
		}
	} else {
		retract(fa,row,col,lookahead);
	}
}

void declarations(FILE* fa, int* row, int* col) {
	TOKEN* lookahead = getNextToken(fa,row,col);
	printToken(lookahead);
	if(equals(lookahead->lexemeName,"int")||equals(lookahead->lexemeName,"char")|| equals(lookahead->lexemeName,"void")) {
		lookahead = identifier_list(fa,row,col);
		retract(fa,row,col,lookahead);
		matchLexemeName(fa,row,col,";");
		declarations(fa,row,col);
	} else {
		retract(fa,row,col,lookahead);
	}
}

void decision_stat(FILE* fa, int* row , int* col) {
	matchLexemeName(fa,row,col,"(");
	expression(fa,row,col);
	matchLexemeName(fa,row,col,")");
	matchLexemeName(fa,row,col,"{");
	statement_list(fa,row,col);
	matchLexemeName(fa,row,col,"}");
	TOKEN* lookahead = getNextToken(fa,row,col);
	if(equals(lookahead->lexemeName,"else")) {
		printToken(lookahead);
		lookahead = getNextToken(fa,row,col);
		if(equals(lookahead->lexemeName, "if")) {
			printToken(lookahead);
			decision_stat(fa,row,col);
		} else {
			retract(fa,row,col,lookahead);
			matchLexemeName(fa,row,col,"{");
			statement_list(fa,row,col);
			matchLexemeName(fa,row,col,"}");
		}
	} else {
		retract(fa,row,col,lookahead);
	}
}

void default_stat(FILE* fa, int* row, int* col) {
	TOKEN* lookahead = getNextToken(fa,row,col);
	printToken(lookahead);
	if(equals(lookahead->lexemeName,"default")) {
		matchLexemeName(fa,row,col,":");
		statement_list(fa,row,col);
	} else {
		retract(fa,row,col,lookahead);
	}
}

int equals(char* a, char* b) {
	if(strcmp(a,b)==0 )return 1;
	else return 0;
}

void Error(int *row, int *col, char*msg ) {
	(*col) = (*col)-strlen(msg);
	printf("Error at line %d col %d: %s\n",*row,*col,msg);
	exit(0);
}

void expression(FILE* fa, int* row, int* col) {
	// printf("in expression\n");
	simple_expression(fa,row,col);
	e_prime(fa,row,col);
	// matchLexemeName(fa,row,col,";");
}

void e_prime(FILE* fa, int* row, int* col) {
	// printf("in e_prime\n");
	TOKEN* lookahead = getNextToken(fa,row,col);
	printToken(lookahead);
	if(isRelop(lookahead) || isEquality(lookahead)) {
		simple_expression(fa,row,col);
	} else {
		// printf("retracting from e_prime\n");
		retract(fa,row,col,lookahead);
	}
}

void factor(FILE* fa, int* row, int* col) {
	// printf("in factor\n");
	TOKEN* lookahead = getNextToken(fa,row,col);
	printToken(lookahead);
	if(isTerm(lookahead)) {
		lookahead = getNextToken(fa,row,col);
		printToken(lookahead);
		if(isMulOp(lookahead)) {
			lookahead = getNextToken(fa,row,col);
			printToken(lookahead);
			if(isTerm(lookahead)) {
				retract(fa,row,col,lookahead);
				factor(fa,row,col);
			}
		} else {
			// printf("retracting from factor\n");
			retract(fa,row,col,lookahead);
		}
	}
}

void for_stat(FILE* fa, int* row, int* col) {
	// for_stat--> for(assign_stat;expression;assign_stat){statement_list}
	matchLexemeName(fa,row,col,"(");
	assign_stat(fa,row,col);
	matchLexemeName(fa,row,col,";");
	expression(fa,row,col);
	matchLexemeName(fa,row,col,";");
	assign_stat(fa,row,col);
	matchLexemeName(fa,row,col,")");
	matchLexemeName(fa,row,col,"{");
	printf("here\n");
	statement_list(fa,row,col);
	matchLexemeName(fa,row,col,"}");
}

TOKEN* identifier_list(FILE* fa, int* row, int* col) {
	TOKEN* lookahead = getNextToken(fa,row,col);
	printToken(lookahead);
	if(equals(lookahead->type,"identifier")) {
		lookahead = getNextToken(fa,row,col);
		printToken(lookahead);
		// id'
		if(equals(lookahead->lexemeName,",")) {
			lookahead = identifier_list(fa,row,col);
		} else if(equals(lookahead->lexemeName,"[")) {
			lookahead = getNextToken(fa,row,col);
			printToken(lookahead);
			if(equals(lookahead->type,"number")) {
				lookahead = getNextToken(fa,row,col);
				printToken(lookahead);
				if(equals(lookahead->lexemeName,"]")) {
					lookahead = getNextToken(fa,row,col);
					printToken(lookahead);
					// id"
					if(equals(lookahead->lexemeName,",")) {
						identifier_list(fa,row,col);
					}
				} else {
					Error(row,col,"missing ]");
				}
			} else {
				Error(row,col,"expected numeric value");
			}
		}
	}
	return lookahead;
}

void input_stat(FILE* fa, int* row, int* col) {
	matchLexemeName(fa,row,col,"scanf");
	matchLexemeName(fa,row,col,"(");
	TOKEN* lookahead = getNextToken(fa,row,col);
	printToken(lookahead);
	if(equals(lookahead->type,"stringLiteral")) {
		matchLexemeName(fa,row,col,",");
		i_prime(fa,row,col);
	} else {
		Error(row,col,"Missing \"");
	}
}



int isAddOp(TOKEN* lookahead) {
	if(equals(lookahead->lexemeName,"+") || equals(lookahead->lexemeName,"-")) return 1;
	return 0;
}

int isEquality(TOKEN* lookahead) {
	if(equals(lookahead->type,"equality")) return 1;
	return 0;
}

int isLooping(TOKEN* lookahead) {
	if(equals(lookahead->lexemeName,"for")|| equals(lookahead->lexemeName,"while")|| equals(lookahead->lexemeName,"switch")) return 1;
	return 0;
}

int isMulOp(TOKEN* lookahead) {
	if(equals(lookahead->lexemeName,"*") || equals(lookahead->lexemeName,"/") || equals(lookahead->lexemeName,"%")) return 1;
	return 0;
}

int isRelop(TOKEN* lookahead) {
	if(equals(lookahead->lexemeName,">") || equals(lookahead->lexemeName,"<") || equals(lookahead->lexemeName,"<=") || equals(lookahead->lexemeName,">=") || equals(lookahead->lexemeName,"!=")) return 1;
	return 0;
}


int isTerm(TOKEN* lookahead) {
	if(equals(lookahead->type,"number")||equals(lookahead->type,"identifier"))return 1;
	return 0;
}

void i_prime(FILE* fa, int* row, int* col) {
	TOKEN* lookahead = getNextToken(fa,row,col);
	printToken(lookahead);
	if(equals(lookahead->lexemeName,"&")) {
		lookahead = getNextToken(fa,row,col);
		printToken(lookahead);
		if(!equals(lookahead->type,"identifier")) {
			Error(row,col,"expected identifier");
		}
	} else if(equals(lookahead->type,"identifier")) {
		// do nothing

	} else {
		Error(row,col,"expected identifier");
	}
	matchLexemeName(fa,row,col,")");
	matchLexemeName(fa,row,col,";");
}

void matchLexemeName(FILE* fa,int* row, int* col, char* symbol) {
	TOKEN* lookahead = getNextToken(fa,row,col);
	printToken(lookahead);
	if(!equals(lookahead->lexemeName,symbol)) {
		Error(row,col,symbol);
	}
}

void output_stat(FILE* fa, int* row, int* col) {
	printf("in output_stat\n");
	matchLexemeName(fa,row,col,"printf");
	matchLexemeName(fa,row,col,"(");
	TOKEN* lookahead = getNextToken(fa,row,col);
	printToken(lookahead);
	if(equals(lookahead->type,"stringLiteral")) {
		lookahead = getNextToken(fa,row,col);
		if(equals(lookahead->lexemeName,",")) {
			identifier_list(fa,row,col);
			matchLexemeName(fa,row,col,";");
		} else if(equals(lookahead->lexemeName,")")) {
			matchLexemeName(fa,row,col,";");
			return;
		}
	} else {
		Error(row,col,"Missing \"");
	}
}

void program(FILE* fa) {
	// program --> main() { declarations statement_list }
	int row=1,col=1;
	TOKEN* lookahead = getNextToken(fa,&row,&col);
	printToken(lookahead);
	if(equals(lookahead->lexemeName,"int")) {
		matchLexemeName(fa,&row,&col,"main");
		matchLexemeName(fa,&row,&col,"(");
		matchLexemeName(fa,&row,&col,")");
		matchLexemeName(fa,&row,&col,"{");
		// printf("matched int main() {\n");
		declarations(fa,&row,&col);
		statement_list(fa,&row,&col);
		matchLexemeName(fa,&row,&col,"}");
		printf("SUCCESS\n");
	}
}

void return_stat(FILE* fa, int* row, int* col) {
	TOKEN* lookahead = getNextToken(fa,row,col);
	if(isTerm(lookahead)) {
		matchLexemeName(fa,row,col,";");
	} else {
		Error(row,col,"expected id or num");
	}
}

void se_prime(FILE* fa, int* row, int* col) {
	// printf("in se_prime\n");
	TOKEN* lookahead = getNextToken(fa,row,col);
	printToken(lookahead);
	if(isAddOp(lookahead)) {
		factor(fa,row,col);
		se_prime(fa,row,col);
	} else {
		// printf("retracting from se_prime\n");
		retract(fa,row,col,lookahead);
	}
}


void simple_expression(FILE* fa, int* row, int* col) {
	// printf("in simple_expression\n");
	factor(fa,row,col);
	se_prime(fa,row,col);
}


void statement_list(FILE* fa, int* row, int* col){
	TOKEN* lookahead = getNextToken(fa,row,col);
	printToken(lookahead);
	printf("in statement_list\n");
	if(equals(lookahead->type,"identifier")) {
		retract(fa,row,col,lookahead);
		assign_stat(fa,row,col);
		matchLexemeName(fa,row,col,";");
		statement_list(fa,row,col);
	} else if(isLooping(lookahead)){
		if(strcmp(lookahead->lexemeName,"for")==0) {
			for_stat(fa,row,col);
		} else if(strcmp(lookahead->lexemeName,"while")==0) {
			while_stat(fa,row,col);
		} else if(strcmp(lookahead->lexemeName,"switch")==0) {
			switch_stat(fa,row,col);
		} 
		statement_list(fa,row,col);
	} else if(strcmp(lookahead->lexemeName,"if")==0) {
		decision_stat(fa,row,col);
		statement_list(fa,row,col);
	} else if(equals(lookahead->lexemeName,"return")) {
		return_stat(fa,row,col);
		statement_list(fa,row,col);
	} else if(equals(lookahead->lexemeName,"printf")) {
		printf("retracting from printf\n");
		retract(fa,row,col,lookahead);
		output_stat(fa,row,col);
		statement_list(fa,row,col);
	} else if(equals(lookahead->lexemeName,"scanf")) {
		retract(fa,row,col,lookahead);
		input_stat(fa,row,col);
		statement_list(fa,row,col);
	} else {
		retract(fa,row,col,lookahead);
	}
}

void switch_stat(FILE* fa, int* row, int* col) {
	// switch_stat--> switch(term) {case_stat default_stat}
	matchLexemeName(fa,row,col,"(");
	TOKEN* lookahead = getNextToken(fa,row,col);
	printToken(lookahead);
	if(isTerm(lookahead)) {
		matchLexemeName(fa,row,col,")");
		matchLexemeName(fa,row,col,"{");
		case_stat(fa,row,col);
		default_stat(fa,row,col);
		matchLexemeName(fa,row,col,"}");
	}

}

void while_stat(FILE* fa, int* row, int* col) {
	// while_stat-->while(expression){statement_list}
	matchLexemeName(fa,row,col,"(");
	expression(fa,row,col);
	matchLexemeName(fa,row,col,")");
	matchLexemeName(fa,row,col,"{");
	statement_list(fa,row,col);
	matchLexemeName(fa,row,col,"}"); 
}

int main() {
	FILE* inputStream = fopen("input.c","r");
	FILE* intermediate = fopen("intermediate.c","w");
	removeUnwanted(inputStream,intermediate);
	fclose(inputStream);
	fclose(intermediate);

	// intermediate contains code devoid of extra spaces, preprocessors, etc
	FILE* newInputStream = fopen("intermediate.c","r");
	FILE* outputStream = fopen("output.c","w");
	program(newInputStream);

}