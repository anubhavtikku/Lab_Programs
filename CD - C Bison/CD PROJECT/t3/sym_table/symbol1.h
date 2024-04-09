#include <stdio.h>
#define MAXLEN 10

int id=0;

enum TYPE {IDENTIFIER, FUNCTION};

	char *TYPES[] = {"IDENTIFIER", "FUNCTION"};

	struct keywordsPos {
		char *keyword;
		int row;
	};

	struct keywordsPos arr[100];
	int cnt = 0;
	char scope = 'G';

	struct token {
		char *lexeme, *varType, *returnType, *args;
		char scope;
		unsigned int row, col, index, argc, size;
		enum TYPE type;
	};

	struct ListElement {
		struct token tok;
		struct ListElement *next;
	};

	struct ListElement *TABLE[MAXLEN] = {NULL};
	unsigned int row=1, col=1;

	void functionArgs(char *str, char *args) {
		while(*str!='(') {
			str++;
		}

		char argv[100] = "<";

		char *temp = str;

		while((temp = strstr(temp, "char"))!=NULL) {
			strcat(argv, "char");
			strcat(argv, ",");
			temp++;
		}

		temp = str;

		while((temp = strstr(temp, "int"))!=NULL) {
			strcat(argv, "int");
			strcat(argv, ",");
			temp++;
		}

		
		argv[strlen(argv)-1] = '\0';
		strcat(argv,">");
		strcpy(args, argv);
	}

	unsigned long hash(char *str){
        unsigned long hash = 5381;
        int c;

        while (c = *str++)
            hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

        return hash;
	}

	int Search(char *str){
		unsigned long hashvalue;
		hashvalue = hash(str);
		hashvalue %= MAXLEN;
		if(TABLE[hashvalue]==NULL)
			return 0;
		struct ListElement *cur = TABLE[hashvalue];
		while(cur!=NULL){
			if(strcmp(str,cur->tok.lexeme)==0)
				return 1;
			cur=cur->next;
		}
		return 0;
	}

	void insert(char *str, enum TYPE type, unsigned int row, unsigned int col, int scopeCount) {

		if(Search(str)) {
			return;
		}

		struct ListElement *ele = malloc(sizeof(struct ListElement));
		struct token tok;
		tok.lexeme = malloc(100);
		tok.varType = malloc(100);
		tok.returnType = malloc(100);
		tok.args = malloc(100);
		strcpy(tok.args, "- ");
		if(scopeCount>0) {
			tok.scope = 'L';
		} else {
			tok.scope = 'G';
		}
		strcpy(tok.returnType, "-");
		tok.type = type;

		if(type == FUNCTION) {
			strcpy(tok.varType, "func");
			int lbpos = 0, commaCnt = 0;

			char temp[100];
			strcpy(temp, str);

			for(int i=0;i<strlen(str);i++) {
				if(str[i]=='(') {
					lbpos = i;
				} else if(str[i]==',') {
					commaCnt += 1;
				}
			}

			functionArgs(temp, tok.args);

			str[lbpos] = '\0';

			for(int i=0;i<cnt;i++) {
				if(arr[i].row == row) {
					strcpy(tok.returnType, arr[i].keyword);
					break;
				}
			}

			tok.argc = commaCnt+1;
			tok.size = 0;
		} else {

			for(int i=0;i<cnt;i++) {
				if(arr[i].row == row) {
					strcpy(tok.varType, arr[i].keyword);
					break;
				}
			}

			int sbPos = -1;

			for(int i=0;i<strlen(str);i++) {
				if(str[i]=='[') {
					sbPos = i;
				}
			}

			int size = 0;
			if(sbPos!=-1) {
				for(int i=sbPos+1;str[i]!=']';i++) {
					size *= 10;
					size += (str[i]-'0');
				}
				str[sbPos] = '\0';
			}

			if(size==0) {
				size=1;
			}

			if(strcmp(tok.varType,"int")==0) {
				size *= 4;
			} else if(strcmp(tok.varType, "float")==0) {
				size *= 4;
			} else if(strcmp(tok.varType, "double")==0) {
				size *= 16;	
			}

			tok.argc = -1;
			tok.size = size;
		}


		

		tok.index = ++id;
		tok.row = row;
		strcpy(tok.lexeme, str);
		ele->tok = tok;
		ele->next = NULL;

		int val;
		val = hash(tok.lexeme);
		val %= MAXLEN;
		

		if(TABLE[val]==NULL)
			TABLE[val]=ele;
		else{
			struct ListElement *ptr = TABLE[val];
			while(ptr->next!=NULL)
				ptr=ptr->next;
			ptr->next=ele;
		}
	}

	void display() {
		//sort();
		printf("No:\tName\tType\tScope\tArgument size\tArguments\tSize\tRetType\n\n");
		for(int i=0;i<MAXLEN;i++) {
			struct ListElement *ptr = TABLE[i];
			while(ptr!=NULL) {
				printf("%d\t%s\t%s\t%c\t%d\t\t%s\t\t%d\t%s\n", ptr->tok.index, ptr->tok.lexeme, 
														ptr->tok.varType, ptr->tok.scope, 
														ptr->tok.argc, ptr->tok.args,
														ptr->tok.size, ptr->tok.returnType);
				ptr = ptr->next;
			}
		}
	}