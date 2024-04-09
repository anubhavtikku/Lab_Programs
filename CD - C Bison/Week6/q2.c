#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_SOURCE_SIZE 0x10000

char* array;
int i=0;
int line=0,col=0;
char buffer[20];
int start_column=0;

typedef struct 
{
	char c;
    int row;
    int col;
} token;
token current;




char check(char *buffer)
{
	if(!strcmp(buffer,"while"))
		return 'w';        //while
	else if(!strcmp(buffer,"for"))
		return 'f';         //for
	else if(!( strcmp(buffer,"if") && strcmp(buffer,"else") && strcmp(buffer,"break")))
		return 'k' ;        //keyword
	else
		 return 'i' ; //identifier
}




token get_next()
{
	token tk;
	if(array[i]==' ')
	{
		i++;
		col++;
		return get_next();
	}
	else if(array[i]>='0' && array[i]<='9')
	{
		while(array[i]>='0' && array[i]<='9')
		{

			i++;
			col++;
		}
		//printf("line: %d    col:%d           char %c \n",line ,col,'n' );
        tk.c='n';
        tk.row=line;
        tk.col=col;
        return tk;      //number
	}
	else if(array[i]>='a' && array[i]<='z'|| array[i]>='A' && array[i]<='Z' || array[i]=='_')
	{
		int t=0;
		start_column=col;
		while((array[i]>='a' && array[i]<='z')|| (array[i]>='A' && array[i]<='Z') ||
		                         array[i]=='_'||(array[i]>='0' && array[i]<='9'))
		{
			buffer[t++]=array[i];
			i++;
			col++;
		}
		buffer[t]='\0';
		//printf("line: %d    col:%d           char %c \n",line ,start_column,check(buffer) );
		tk.c=check(buffer);
        tk.row=line;
        tk.col=start_column;
        return tk; 
        //return check(buffer);
 

	}
	else if (array[i]=='(')
	{
		i++;
		col++;
		//printf("line: %d    col:%d           char %c \n",line ,col,'(' );
		tk.c='(';
        tk.row=line;
        tk.col=col;
        return tk; 
		//return ('(');
	}
	else if(array[i]==')')
	{
		i++;
		col++;
		//printf("line: %d    col:%d           char %c \n",line ,col,')' );
        tk.c=')';
        tk.row=line;
        tk.col=col;
        return tk; 
		//return ')';
	}
	else if(array[i]=='$')
	{
		i++;
		col++;
		//printf("line: %d    col:%d           char %c \n",line ,col,'$' );
		tk.c='$';
        tk.row=line;
        tk.col=col;
        return tk; 
		//return '$';
	}
	else if(array[i]=='\n')
	{
		line++;
		i++;
		col=0;
		return get_next();
	}
	else if(array[i]==';')
	{
		col++;
		i++;
		//printf("line: %d    col:%d           char %c \n",line ,col,';' );
		//return ';';
		tk.c=';';
        tk.row=line;
        tk.col=col;
        return tk; 
	}
	else if(array[i]=='<'||array[i]=='>'|| array[i]=='='||array[i]=='!')
	{
		char ki=array[i];
		start_column=col;
		col++;
		i++;
		if(array[i]=='=')
		{
			i++;
			col++;
			//printf("line: %d    col:%d           char %c \n",line ,start_column,'r' );
			//return 'r' ; //relop
			tk.c='r';
        	tk.row=line;
        	tk.col=start_column;
        	return tk; 
		}
		else
		{
			//col--;
			//i--;
			//printf("line: %d    col:%d           char %c \n",line ,col,'r' );
			//return 'r'  ;//relop
			tk.c='r';
        	tk.row=line;
        	tk.col=start_column;
        	return tk; 
		}
	}
	else if(array[i]=='{')
	{
		i++;
		col++;
		//printf("line: %d    col:%d           char %c \n",line ,col,'{' );
		//return '{';
		tk.c='{';
       	tk.row=line;
        tk.col=start_column;
       	return tk; 

	}
	else if(array[i]=='}')
	{
		i++;
		col++;
		//printf("line: %d    col:%d           char %c \n",line ,col,'}' );
		//return '}';
		tk.c='}';
        tk.row=line;
       	tk.col=start_column;
       	return tk; 


	}
	else if(array[i]=='+'||array[i]=='-'||array[i]=='*'||array[i]=='/')
	{
		col++;
		i++;
		tk.c='a';//arithmetic
		tk.row=line;
		tk.col=col;
		return tk;
	}
	else
	{
		i++;
		col++;
		return get_next();
	}

}

void looping_statement();
void statement_list();
void expression();
void term();
void assign_statement();
void T();


void looping_statement()
{
	if(current.c=='w')
	{
		printf("w\n");
		current=get_next();
		if(current.c=='(')
		{
			printf("(\n");
			current=get_next();
			printf("Called expression\n");
			expression();
			printf("returned from expression\n");
			if(current.c==')')
			{
				printf(")\n");
				current=get_next();
				if(current.c=='{')
				{
					current=get_next();
					printf("{\n");
					printf("called statement_list\n");
					statement_list();
					printf("Returned from statement_list\n");
					if(current.c=='}')
					{
						printf("}\n");
						current=get_next();
					}
					else{
						printf("Error occured at row: %d  col:%d\n",current.row,current.col );
						exit(0);
					}
				}
				else{
					printf("Error occured at row: %d  col:%d\n",current.row,current.col );
					exit(0);

				}


			}
			else
			{
				printf("Error occured at row: %d  col:%d\n",current.row,current.col );
				exit(0);
			}
		}
		else
		{
			printf("Error occured at row: %d  col:%d\n",current.row,current.col );
			exit(0);
		}
	}
	else if(current.c=='f')
	{
		printf("f\n");
		current=get_next();
		if(current.c=='(')
		{
			printf("(\n");
			current=get_next();
			printf("Called assign_statement\n");
			assign_statement();
			printf("Returned from assign statement\n");
			if(current.c==';')
			{
				printf(";\n");
				current=get_next();
				printf("Called expression\n");
				expression();
				printf("returned from expression\n");
				if(current.c==';')
				{
					printf(";\n");
					current=get_next();
					printf("Called assign_statement\n");
					assign_statement();
					printf("Returned from assign statement\n");
					if(current.c==')')
					{
						current=get_next();
						printf(")\n");
						if(current.c=='{')
						{
							printf("{\n");
							current=get_next();
							printf("called statement_list\n");
							statement_list();
							printf("retuned from statement_list\n");
							if(current.c=='}')
							{
								printf("}\n");
								current=get_next();
							}
							else
							{
								printf("Error occured at row: %d  col:%d\n",current.row,current.col );
								exit(0);

							}
						}
						else
						{
							printf("Error occured at row: %d  col:%d\n",current.row,current.col );
							exit(0);
						}
					}
					else
					{
						printf("Error occured at row: %d  col:%d\n",current.row,current.col );
						exit(0);
					}

				}
				else
				{
					printf("Error occured at row: %d  col:%d\n",current.row,current.col );
					exit(0);
				}
		    }
		    else
		    {
		    	printf("Error occured at row: %d  col:%d\n",current.row,current.col );
				exit(0);
		    }
			
		}
		else
		{
			printf("Error occured at row: %d  col:%d\n",current.row,current.col );
			exit(0);
		}
		


	}
	else 
	{
		printf("Error occured\n");
	}
	if(current.c=='$')
	{
		printf("----------------------------------------------\n");
		printf("--------------string matched------------------\n");
		printf("----------------------------------------------\n");
		exit(0);
	}

}
void expression()
{
	if(current.c=='i'||current.c=='n')
	{
		printf("called term\n");
		term();
		printf("returned from term\n");
		if(current.c=='r')
		{
			printf("r\n");
			current=get_next();
			printf("called term\n");
			term();
			printf("returned from term\n");

		}
		else{
			printf("Error occured at row: %d  col:%d\n",current.row,current.col );
			exit(0);
		}
	}
}

void term()
{
	if(current.c=='i'||current.c=='n')
	{
		printf("%c\n",current.c);
		current=get_next();
		return;
	}
	else{
		printf("Error occured at row: %d  col:%d\n",current.row,current.col );
		exit(0);
	}
}

void assign_statement()
{
	if(current.c=='i')
	{
		printf("i\n");
		current=get_next();
		if(current.c=='r')
		{
			current=get_next();
			printf("=\n");
			printf("called term\n");
			term();
			printf("retuned from term\n");
			printf("called T\n");
			T();
			printf("retuned from T\n");

		}
		else
		{
			printf("Error occured at row: %d  col:%d\n",current.row,current.col );
			exit(0);
		}
	}
	else
	{
		return;
	}
}

void statement_list()
{
	//printf("statement_list current=%c",current);
	if(current.c=='w'||current.c=='f')
	{
		looping_statement();
	}
	/*else if(current.c=='i')
	{
      current=get_next();
		printf("i\n");
	}
	else if(current.c==';')
	{
		current=get_next();
		printf(";\n");
	}
	else
	{
		return;
	}*/

    else while(current.c!='}')
	{
		printf("%c\n",current.c );
		current=get_next();
		if(current.c=='w'||current.c=='f')
	    {
		looping_statement();
	    }
		
	}
}

void T()
{
	if(current.c=='a')
	{
		printf("a\n");
		current=get_next();
		printf("calling term\n");
		term();
		printf("retuned from term\n");
		if(current.c=='a')
		{
			printf("calling T");
			T();
			printf("Returned from T\n");

		}
		else
		{
			return;
		}
	}
	else if(current.c==';'||current.c==')')
	{
		return;
	}
	else
	{
		printf("Error occured at row: %d  col:%d\n",current.row,current.col );
		exit(0);
	}

}


int main()
{
	FILE* fp = fopen("loops.c","r");
	if(!fp){
		fprintf(stderr,"Failed to load file.\n");
		getchar();
		exit(1);
	}
	array = (char*) calloc(MAX_SOURCE_SIZE,sizeof(char));
	int source_size = fread(array,1,MAX_SOURCE_SIZE,fp);
	fclose(fp);
	/*int t=25;
	char c;
	while(c!='$')
	{
		c=get_next();

	}*/
	current=get_next();
	looping_statement();

}