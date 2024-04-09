//Function call is an identifier
//Function declaration is a function

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TableLength 30

int ind = 0;

typedef struct node{
	char dtype[10];
	char rtype[10];
	char name[10];
	char scope;
	int type;
	int index;
	int num;
	int argsList[10];
	char size;
	struct node* next;
}Node;

Node* Table[TableLength]; 	//Array of head pointers

void Initialize(){
	for (int i = 0; i < TableLength; ++i)
	{
		Table[i] = NULL;
	}
}

char* show(int type){
	if(type == 0)
		return "Identifier";
	else
		return "Function";
}

void printArgs(Node* temp){

	char c = '>';
	if(temp->num == 0){
		printf("None");
		return;
	}

	
	for (int i = 0; i < temp->num; ++i)
	{
		printf("id%d ", temp->argsList[i]);
	}
	
}

void display()
{
	char sep = '|';
	printf("-------------------------------------------------------------------------------------------\n");
	printf("\t\t\t\tSYMBOL TABLE\t\t\t\t\n");
	printf("--------------------------------------------------------------------------------------------\n\n");
	printf("| Index  |  Name  |  Size  |Return type|Data type|   Type     | No. of Args |   Args  \t | Scope\n");
	for(int i = 0; i < TableLength; i++) {
		Node *temp = Table[i];
		while(temp) {
			printf("|%5d | %6s | %6c | %6s | %7s | %10s | %11d | ",temp->index,temp->name,temp->size,temp->rtype,temp->dtype,show(temp->type), temp-> num);
			printf("\t< ");
			printArgs(temp);
			printf(">");
			printf("%10c %6c |\n", sep, temp->scope);
			temp = temp->next;
		}
	}
}

int hash_function(char *str) 
{
	unsigned long hash = 612;
	int c;	
	while(c = *str++) 
		hash  = hash*19 + c;

	return hash % TableLength;
}


int search(char *str)
{
	unsigned long hash_address = hash_function(str);
	Node *temp = Table[hash_address];

	while(temp) {
		if(strcmp(temp->name,str) == 0)
			return 1;
		temp = temp->next;
	}
	
	return 0;
}

void insert(Node* n)
{

	//printf("Inserting %s\n", n->name);
	//fflush(stdout);
	n->index = ind++;
	if(n->type == 0) {		//Identifier
		strcpy(n->rtype,"--");
		n->num = 0;
	}
	else{					//Function
		strcpy(n->dtype,"--");
		n->scope = 'G';
	}


	if(search(n->name))
		return;

	unsigned long hash_address = hash_function(n->name);
	
	hash_address = hash_address % 30;			//as Table length is 30
	
	
	n->next = NULL;
	
	
	if(Table[hash_address] == NULL) 
		Table[hash_address] = n;	
	
	else {
		Node *temp = Table[hash_address];
		
		while(temp->next != NULL) 
			temp = temp->next;
		
		temp->next = n;
	
	}
}