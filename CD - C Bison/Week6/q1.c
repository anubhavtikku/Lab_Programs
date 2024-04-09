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
	else if(!( strcmp(buffer,"if") && strcmp(buffer,"else") ))
		return 'k' ;        //keyword
	else if(!(strcmp(buffer,"break")))
		return 'b'; //break
	else if(!(strcmp(buffer,"case")))
		return 'c'; //case
	else if(!(strcmp(buffer,"switch")))
		return 's';
	else if(!(strcmp(buffer,"default")))
		return 'd';
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
	else if(array[i]==':')
	{
		col++;
		i++;
		tk.c=':';
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

void statement_list();
void switch_statement();
void br();
void CN();
void statement();



void switch_statement()
{
	if(current.c=='s')
	{
		printf("s\n");
		current=get_next();
		if(current.c=='(')
		{
			printf("(");
			current=get_next();
			if(current.c=='i')
			{
				printf("i\n");
				current=get_next();
				if(current.c==')')
				{
					printf(")\n");
					current=get_next();
					if(current.c=='{')
					{
						printf("{\n");
						current=get_next();
						printf("called statement_list\n");
						statement_list();
						printf("returned from statement_list\n");	
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
	if(current.c=='$')
	{
		printf("|______________________________________________|\n");
		printf("|--------------string matched------------------|\n");
		printf("|______________________________________________|\n");
		exit(0);
	}
}


void statement_list()
{
	if(current.c=='c')
	{
		printf("called CN");
		CN();
		printf("returned from CN\n");
		if(current.c==':')
		{
			printf(":\n");
			current=get_next();
			printf("calling statement\n");
			statement();
			printf("Returned from statement\n");
			printf("called br");
			br();
			printf("returned from br");
    	}
    	else
    		{
    			printf("Error occured at row: %d  col:%d\n",current.row,current.col );
		        exit(0);
            }
	}
	else if(current.c=='}')
		{
			return;
		}
	else if(current.c=='d')
		{
			printf("Called CN");
			CN();
			printf("returned from CN");
			if(current.c==':')
			{
				printf(":\n");
				current=get_next();
				printf("calling statement\n");
				statement();
				printf("Returned from statement\n");
				printf("called br");
				br();
				printf("returned from br");
    		}
    		else
    		{
    			printf("Error occured at row: %d  col:%d\n",current.row,current.col );
		        exit(0);
            }
			
		}
	else{
		printf("Error occured at row: %d  col:%d\n",current.row,current.col );
		exit(0);
        }

	
}

void CN()
{
	if(current.c=='c')
	{
		printf("c\n");
		current=get_next();
		if(current.c=='n')
		{
			printf("n\n");
			current=get_next();
			return;
		}
		else
		{
			printf("Error occured at row: %d  col:%d\n",current.row,current.col );
			exit(0);
		}
	}
	else if(current.c=='d')
	{
		printf("d\n");
		current=get_next();
		return;

	}
	else
	{
		printf("Error occured at row: %d  col:%d\n",current.row,current.col );
		exit(0);
	}

}

void br()
{
	if(current.c=='b')
	{
		printf("b\n");
		current=get_next();
		if(current.c==';')
		{
			printf(";\n");
			current=get_next();
			printf("called statement_list\n");
			statement_list();
			printf("returned from statement list\n");
		}
		else
		{
			printf("Error occured at row: %d  col:%d\n",current.row,current.col );
			exit(0);
		}
	}
	else {
		printf("called statement_list\n");
		statement_list();
		printf("returned from statement list\n");
	}
}






void statement()
{
	if(current.c=='s')
	{
		switch_statement();
	}
	

    else while(current.c!='b'&&current.c!='c'&& current.c!='}')
	{
		printf("%c\n",current.c );
		current=get_next();
		if(current.c=='s')
	    {
		switch_statement();
	    }
		
	}
	if(current.c=='b'||current.c=='c'||current.c=='}')
	{
		return;

	}
}





int main()
{
	FILE* fp = fopen("switch.c","r");
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
	switch_statement();

}