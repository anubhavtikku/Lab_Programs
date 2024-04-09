#include <stdio.h>
#include <ctype.h>
#include "token.c"
#include <string.h>
#define error printf("Error occured because of %s at %d,%d\n",lookahead->word,lookahead->row,lookahead->col);exit(0);
#define retract fseek(fp,-1*strlen(lookahead->word),SEEK_CUR);
#define disp printf("%s\n",lookahead->word);
#define nextT lookahead=getNextToken(fp);
struct token *lookahead;
FILE *fp;
void mulop();
void addop();
void relop();
void factor();
void tprime();
void term();
void seprime();
void simple_expn();
void eprime();
void expn();
void statement();
void statement_list();
void assign_stat();
void assign_stat_loop();
void decision_stat();
void dprime();
void switch_stat();
void case_stat_list();
void case_stat();
void looping_start()
{
    nextT;
    printf("%s\n",lookahead->word);
    if(strcmp(lookahead->word,"while")==0)
    {
        nextT;
        disp;
        if(strcmp(lookahead->word,"(")==0)
        {
            expn();
            nextT;
            disp;
            if(strcmp(lookahead->word,")")==0)
            {
                nextT;
                disp;
                if (strcmp(lookahead->word,"{")==0)
                {
                    statement_list();
                    nextT;
                    disp;
                    if(strcmp(lookahead->word,"}")==0)
                    {
                        printf("\t\tWHILE BLOCK\n");
                        return;
                    }
                    else
                        error;
                }
                else
                   	error;
            }
            else
                error;
        }
        else
            error;
    }
    else if(strcmp(lookahead->word,"for")==0)
    {
        nextT;
        disp;
        if(strcmp(lookahead->word,"(")==0)
        {
            assign_stat_loop();
            nextT;
            disp;
            if(strcmp(lookahead->word,";")==0)
            {
                expn();
                nextT;
                disp;
                if (strcmp(lookahead->word,";")==0)
                {
                    assign_stat_loop();
                    nextT;
                    disp;
                    if (strcmp(lookahead->word,")")==0)
                    {
                        nextT;
                        disp;
                        if(strcmp(lookahead->word,"{")==0)
                        {
                            statement_list();
                            nextT;
                            disp;
                            if(strcmp(lookahead->word,"}")==0)
                            {
                                printf("\t\tFOR BLOCK\n");
                                return;
                            }
                            else
                                error;
                        }
                        else
                            error;
                    }
                    else
                        error;
                }
                else
                    error;
            }
            else
                error;
        }
        else
            error;
    }
    else
        error;
    if(strcmp(lookahead->word,"EOL")==0)
        printf("Succes\n");
    else
        error;
}
void switch_stat()
{
    nextT;
    if(strcmp(lookahead->word,"switch")==0)
    {
        nextT;
        if(strcmp(lookahead->word,"(")==0)
        {
            expn();
            nextT;
            if(strcmp(lookahead->word,")")==0)
            {
                nextT;
                if(strcmp(lookahead->word,"{")==0)
                {
                    case_stat_list();
                    nextT;
                    if(strcmp(lookahead->word,"}")==0)
                    {
                        printf("\t\tSWITCH BLOCK\n");
                        return;
                    }
                    else
                        error;
                }
                else
                    error;
            }
            else
                error;
        }
        else
            error;
    }
    else
        error;
}
void case_stat_list()
{
    nextT;
    //printf("HI\n");
    disp;
    if(strcmp(lookahead->word,"}")!=0)
    {
            retract;
            //printf("hh\n");
            case_stat();
            case_stat_list();
            return;
    }
    else
    {
        retract;
        return;
    }
}
void case_stat()
{
    nextT;
    if (strcmp(lookahead->word,"case")==0)
    {
        factor();
        nextT;
        if(strcmp(lookahead->word,":")==0)
        {
            nextT;
            if(strcmp(lookahead->word,"{")==0)
            {
                statement_list();
                nextT;
                if(strcmp(lookahead->word,"}")==0)
                {
                    return;   
                }
                else
                    error;   
            }
            else
                error;
        }
        else
            error;
    }
    else if (strcmp(lookahead->word,"default")==0)
    {
        nextT;
        if(strcmp(lookahead->word,":")==0)
        {
            nextT;
            if(strcmp(lookahead->word,"{")==0)
            {
                statement_list();
                nextT;
                if(strcmp(lookahead->word,"}")==0)
                {
                    return;   
                }
                else
                    error;   
            }
            else
                error;
        }
        else
            error;
    }
    else
        error;
}
void assign_stat()
{
    lookahead=getNextToken(fp);
    //printf("%s\n",lookahead->word);
    if(isIdentifier(lookahead->word))
    {
        lookahead=getNextToken(fp);
        printf("%s\n",lookahead->word);
        if (strcmp(lookahead->word,"=")==0||strcmp(lookahead->word,"+=")==0||strcmp(lookahead->word,"-=")==0||strcmp(lookahead->word,"*=")==0||strcmp(lookahead->word,"/=")==0||strcmp(lookahead->word,"++")==0||strcmp(lookahead->word,"--")==0)
        {
            if(strcmp(lookahead->word,"++")!=0 && strcmp(lookahead->word,"--")!=0)
            {expn();}
            lookahead=getNextToken(fp);
            printf("%s\n",lookahead->word);
            if(strcmp(lookahead->word,";")==0)
            {
                return;
            }
            else
            {
                printf("Error occured because %s %d %d\n",lookahead->word,lookahead->row,lookahead->col);exit(0);
            }
        }
        else
        {
            printf("Error occured because %s %d %d\n",lookahead->word,lookahead->row,lookahead->col);exit(0);
        }
    }
    else
    {
        printf("Error occured because %s %d %d\n",lookahead->word,lookahead->row,lookahead->col);exit(0);
    }
}
void assign_stat_loop()
{
    lookahead=getNextToken(fp);
    printf("%s\n",lookahead->word);
    if(isIdentifier(lookahead->word))
    {
        lookahead=getNextToken(fp);
        printf("%s\n",lookahead->word);
        if (strcmp(lookahead->word,"=")==0||strcmp(lookahead->word,"+=")==0||strcmp(lookahead->word,"-=")==0||strcmp(lookahead->word,"*=")==0||strcmp(lookahead->word,"/=")==0||strcmp(lookahead->word,"++")==0||strcmp(lookahead->word,"--")==0)
        {
            if(strcmp(lookahead->word,"++")!=0 && strcmp(lookahead->word,"--")!=0)
            {expn();}
            return;
        }
        else
        {
            printf("Error occured because %s %d %d\n",lookahead->word,lookahead->row,lookahead->col);exit(0);
        }
    }
    else
    {
        printf("Error occured because %s %d %d\n",lookahead->word,lookahead->row,lookahead->col);exit(0);
    }
}
void decision_stat()
{
	nextT;
	if(strcmp(lookahead->word,"if")==0)
	{
		nextT;
		disp;
		if(strcmp(lookahead->word,"(")==0)
		{
			expn();
			nextT;
			disp;
			if(strcmp(lookahead->word,")")==0)
			{
				nextT;
				disp;
				if(strcmp(lookahead->word,"{")==0)
				{
					statement_list();
					nextT;
					disp;
					if(strcmp(lookahead->word,"}")==0)
					{
						dprime();
						printf("\t\tIF BLOCK\n");
						return;
					}
					else
						error;
				}
				else
					error;
			}
			else
				error;
		}
		else
			error;
	}
	else
		error;
}
void dprime()
{
	nextT;
	disp;
	if(strcmp(lookahead->word,"else")==0)
	{
		nextT;
		disp;
		if(strcmp(lookahead->word,"{")==0)
		{
			statement_list();
			nextT;
			disp;
			if(strcmp(lookahead->word,"}")==0)
			{
				return;
			}
			else
				error;
		}
		else
			error;
	}
	else
	{
		retract;
		return;
	}
}
void statement_list()
{
	nextT;
	//printf("HI\n");
	disp;
	if(strcmp(lookahead->word,"}")!=0)
	{
			retract;
			//printf("hh\n");
	    	statement();
	    	statement_list();
	    	return;
	}
	else
	{
		retract;
		return;
	}
}
void statement()
{
	nextT;
	//printf("%s\n",lookahead->word);
	if(strcmp(lookahead->word,"for")==0 || strcmp(lookahead->word,"while")==0)
	{
		retract;
		//lookahead=getNextToken(fp);
		//printf("%s\n",lookahead->word );
		//printf("ls\n");
		looping_start();
		return;
	}
	else if(strcmp(lookahead->word,"if")==0)
	{
		retract;
		//lookahead=getNextToken(fp);
		//printf("%s\n",lookahead->word );
		//printf("ls\n");
		decision_stat();
		return;
	}
    else if(strcmp(lookahead->word,"switch")==0)
    {
        retract;
        //lookahead=getNextToken(fp);
        //printf("%s\n",lookahead->word );
        //printf("ls\n");
        switch_stat();
        return;
    }
	else
	{
		retract;
		//printf("as\n");
		assign_stat();
		return;
	}
}
void expn()
{
    simple_expn();
    eprime();
    return;
}
void eprime()
{
	nextT;
	if (strcmp(lookahead->word,"==")==0 ||strcmp(lookahead->word,"!=")==0 ||strcmp(lookahead->word,"<=")==0 ||strcmp(lookahead->word,">=")==0 ||strcmp(lookahead->word,">")==0 ||strcmp(lookahead->word,"<")==0)
	{
		retract;
	    relop();
	    simple_expn();
	    return;
	}
	else
	{
		retract;
		return;
	}
}
void simple_expn()
{
    term();
    seprime();
    return;
}
void seprime()
{
	nextT;
	if(strcmp(lookahead->word,"+")==0 ||strcmp(lookahead->word,"-")==0)
	{
		retract;
	    addop();
	    term();
	    seprime();
	    return;
	}
	else
	{
		retract;
		return;
	}
}
void term()
{
    factor();
    tprime();
    return;
}
void tprime()
{
	nextT;
	if(strcmp(lookahead->word,"*")==0 ||strcmp(lookahead->word,"/")==0 || strcmp(lookahead->word,"%")==0)
	{
		retract;
	    mulop();
	    factor();
	    tprime();
	    return;
	}
	else
	{
		retract;
		return;
	}
}
void factor()
{
    nextT;
    disp;
    if(isIdentifier(lookahead->word))
    {
        return;
    }
    else if(isNumericConstant(lookahead->word))
    {
        return;
    }
    else
    {
        error;
    }
}
void relop()
{
    nextT;
    disp;
    if (strcmp(lookahead->word,"==")==0 ||strcmp(lookahead->word,"!=")==0 ||strcmp(lookahead->word,"<=")==0 ||strcmp(lookahead->word,">=")==0 ||strcmp(lookahead->word,">")==0 ||strcmp(lookahead->word,"<")==0)
    {
        return;
    }
    else
        error;
}
void addop()
{
    nextT;
    disp;
    if(strcmp(lookahead->word,"+")==0 ||strcmp(lookahead->word,"-")==0)
    {
        return;
    }
    else
        error;
}
void mulop()
{
    nextT;
    disp;
    if(strcmp(lookahead->word,"*")==0 ||strcmp(lookahead->word,"/")==0 || strcmp(lookahead->word,"%")==0)
    {
        return;
    }
    else
        error;
}
int main()
{
    fp=fopen("f3.txt","r");
   // nextT;
    
        decision_stat();
    
    return 0;
}
