#include <stdio.h>
#include <ctype.h>
#include "token.c"
#include <string.h>
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
    lookahead=getNextToken(fp);
    //printf("%s\n",lookahead->word);
    if(strcmp(lookahead->word,"while")==0)
    {
        lookahead=getNextToken(fp);
        printf("%s\n",lookahead->word);
        if(strcmp(lookahead->word,"(")==0)
        {
            expn();
            lookahead=getNextToken(fp);
            printf("%s\n",lookahead->word);
            if(strcmp(lookahead->word,")")==0)
            {
                lookahead=getNextToken(fp);
                printf("%s\n",lookahead->word);
                if (strcmp(lookahead->word,"{")==0)
                {
                    statement_list();
                    lookahead=getNextToken(fp);
                    printf("%s\n",lookahead->word);
                    if(strcmp(lookahead->word,"}")==0)
                    {
                        printf("\t\t\t\twhile block matched\n");
                        return;
                    }
                    else
                        printf("Err@ %s %d %d\n",lookahead->word,lookahead->row,lookahead->col);exit(0);
                }
                else
                   	printf("Err@ %s %d %d\n",lookahead->word,lookahead->row,lookahead->col);exit(0);
            }
            else
                printf("Err@ %s %d %d\n",lookahead->word,lookahead->row,lookahead->col);exit(0);
        }
        else
            printf("Err@ %s %d %d\n",lookahead->word,lookahead->row,lookahead->col);exit(0);
    }
    else if(strcmp(lookahead->word,"for")==0)
    {
        lookahead=getNextToken(fp);
        printf("%s\n",lookahead->word);
        if(strcmp(lookahead->word,"(")==0)
        {
            assign_stat_loop();
            lookahead=getNextToken(fp);
            printf("%s\n",lookahead->word);
            if(strcmp(lookahead->word,";")==0)
            {
                expn();
                lookahead=getNextToken(fp);
                printf("%s\n",lookahead->word);
                if (strcmp(lookahead->word,";")==0)
                {
                    assign_stat_loop();
                    lookahead=getNextToken(fp);
                    printf("%s\n",lookahead->word);
                    if (strcmp(lookahead->word,")")==0)
                    {
                        lookahead=getNextToken(fp);
                        printf("%s\n",lookahead->word);
                        if(strcmp(lookahead->word,"{")==0)
                        {
                            statement_list();
                            lookahead=getNextToken(fp);
                            printf("%s\n",lookahead->word);
                            if(strcmp(lookahead->word,"}")==0)
                            {
                                printf("\t\t\t\tfor block matched\n");
                                return;
                            }
                            else
                                printf("Err@ %s %d %d\n",lookahead->word,lookahead->row,lookahead->col);exit(0);
                        }
                        else
                            printf("Err@ %s %d %d\n",lookahead->word,lookahead->row,lookahead->col);exit(0);
                    }
                    else
                        printf("Err@ %s %d %d\n",lookahead->word,lookahead->row,lookahead->col);exit(0);
                }
                else
                    printf("Err@ %s %d %d\n",lookahead->word,lookahead->row,lookahead->col);exit(0);
            }
            else
                printf("Err@ %s %d %d\n",lookahead->word,lookahead->row,lookahead->col);exit(0);
        }
        else
            printf("Err@ %s %d %d\n",lookahead->word,lookahead->row,lookahead->col);exit(0);
    }
    else
        printf("Err@ %s %d %d\n",lookahead->word,lookahead->row,lookahead->col);exit(0);
    if(strcmp(lookahead->word,"EOL")==0)
        printf("Succes\n");
    else
        printf("Err@ %s %d %d\n",lookahead->word,lookahead->row,lookahead->col);exit(0);
}
void switch_stat()
{
    lookahead=getNextToken(fp);
    if(strcmp(lookahead->word,"switch")==0)
    {
        lookahead=getNextToken(fp);
        if(strcmp(lookahead->word,"(")==0)
        {
            expn();
            lookahead=getNextToken(fp);
            if(strcmp(lookahead->word,")")==0)
            {
                lookahead=getNextToken(fp);
                if(strcmp(lookahead->word,"{")==0)
                {
                    case_stat_list();
                    lookahead=getNextToken(fp);
                    if(strcmp(lookahead->word,"}")==0)
                    {
                        printf("\t\t\t\tswitch block matched\n");
                        return;
                    }
                    else
                        printf("Err@ %s %d %d\n",lookahead->word,lookahead->row,lookahead->col);exit(0);
                }
                else
                    printf("Err@ %s %d %d\n",lookahead->word,lookahead->row,lookahead->col);exit(0);
            }
            else
                printf("Err@ %s %d %d\n",lookahead->word,lookahead->row,lookahead->col);exit(0);
        }
        else
            printf("Err@ %s %d %d\n",lookahead->word,lookahead->row,lookahead->col);exit(0);
    }
    else
        printf("Err@ %s %d %d\n",lookahead->word,lookahead->row,lookahead->col);exit(0);
}
void case_stat_list()
{
    lookahead=getNextToken(fp);
    //printf("HI\n");
    printf("%s\n",lookahead->word);
    if(strcmp(lookahead->word,"}")!=0)
    {
            fseek(fp,-1*strlen(lookahead->word),SEEK_CUR);
            //printf("hh\n");
            case_stat();
            case_stat_list();
            return;
    }
    else
    {
        fseek(fp,-1*strlen(lookahead->word),SEEK_CUR);
        return;
    }
}
void case_stat()
{
    lookahead=getNextToken(fp);
    if (strcmp(lookahead->word,"case")==0)
    {
        factor();
        lookahead=getNextToken(fp);
        if(strcmp(lookahead->word,":")==0)
        {
            lookahead=getNextToken(fp);
            if(strcmp(lookahead->word,"{")==0)
            {
                statement_list();
                lookahead=getNextToken(fp);
                if(strcmp(lookahead->word,"}")==0)
                {
                    return;   
                }
                else
                    printf("Err@ %s %d %d\n",lookahead->word,lookahead->row,lookahead->col);exit(0);   
            }
            else
                printf("Err@ %s %d %d\n",lookahead->word,lookahead->row,lookahead->col);exit(0);
        }
        else
            printf("Err@ %s %d %d\n",lookahead->word,lookahead->row,lookahead->col);exit(0);
    }
    else if (strcmp(lookahead->word,"default")==0)
    {
        lookahead=getNextToken(fp);
        if(strcmp(lookahead->word,":")==0)
        {
            lookahead=getNextToken(fp);
            if(strcmp(lookahead->word,"{")==0)
            {
                statement_list();
                lookahead=getNextToken(fp);
                if(strcmp(lookahead->word,"}")==0)
                {
                    return;   
                }
                else
                    printf("Err@ %s %d %d\n",lookahead->word,lookahead->row,lookahead->col);exit(0);   
            }
            else
                printf("Err@ %s %d %d\n",lookahead->word,lookahead->row,lookahead->col);exit(0);
        }
        else
            printf("Err@ %s %d %d\n",lookahead->word,lookahead->row,lookahead->col);exit(0);
    }
    else
        printf("Err@ %s %d %d\n",lookahead->word,lookahead->row,lookahead->col);exit(0);
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
	            printf("Err@ %s %d %d\n",lookahead->word,lookahead->row,lookahead->col);exit(0);
	        }
        }
        else
        {
            printf("Err@ %s %d %d\n",lookahead->word,lookahead->row,lookahead->col);exit(0);
        }
    }
    else
    {
        printf("Err@ %s %d %d\n",lookahead->word,lookahead->row,lookahead->col);exit(0);
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
            printf("Err@ %s %d %d\n",lookahead->word,lookahead->row,lookahead->col);exit(0);
        }
    }
    else
    {
        printf("Err@ %s %d %d\n",lookahead->word,lookahead->row,lookahead->col);exit(0);
    }
}
void decision_stat()
{
	lookahead=getNextToken(fp);
	if(strcmp(lookahead->word,"if")==0)
	{
		lookahead=getNextToken(fp);
		printf("%s\n",lookahead->word);
		if(strcmp(lookahead->word,"(")==0)
		{
			expn();
			lookahead=getNextToken(fp);
			printf("%s\n",lookahead->word);
			if(strcmp(lookahead->word,")")==0)
			{
				lookahead=getNextToken(fp);
				printf("%s\n",lookahead->word);
				if(strcmp(lookahead->word,"{")==0)
				{
					statement_list();
					lookahead=getNextToken(fp);
					printf("%s\n",lookahead->word);
					if(strcmp(lookahead->word,"}")==0)
					{
						dprime();
						printf("\t\t\t\tif block matched\n");
						return;
					}
					else
						printf("Err@ %s %d %d\n",lookahead->word,lookahead->row,lookahead->col);exit(0);
				}
				else
					printf("Err@ %s %d %d\n",lookahead->word,lookahead->row,lookahead->col);exit(0);
			}
			else
				printf("Err@ %s %d %d\n",lookahead->word,lookahead->row,lookahead->col);exit(0);
		}
		else
			printf("Err@ %s %d %d\n",lookahead->word,lookahead->row,lookahead->col);exit(0);
	}
	else
		printf("Err@ %s %d %d\n",lookahead->word,lookahead->row,lookahead->col);exit(0);
}
void dprime()
{
	lookahead=getNextToken(fp);
	printf("%s\n",lookahead->word);
	if(strcmp(lookahead->word,"else")==0)
	{
		lookahead=getNextToken(fp);
		printf("%s\n",lookahead->word);
		if(strcmp(lookahead->word,"{")==0)
		{
			statement_list();
			lookahead=getNextToken(fp);
			printf("%s\n",lookahead->word);
			if(strcmp(lookahead->word,"}")==0)
			{
				return;
			}
			else
				printf("Err@ %s %d %d\n",lookahead->word,lookahead->row,lookahead->col);exit(0);
		}
		else
			printf("Err@ %s %d %d\n",lookahead->word,lookahead->row,lookahead->col);exit(0);
	}
	else
	{
		fseek(fp,-1*strlen(lookahead->word),SEEK_CUR);
		return;
	}
}
void statement_list()
{
	lookahead=getNextToken(fp);
	//printf("HI\n");
	printf("%s\n",lookahead->word);
	if(strcmp(lookahead->word,"}")!=0)
	{
			fseek(fp,-1*strlen(lookahead->word),SEEK_CUR);
			//printf("hh\n");
	    	statement();
	    	statement_list();
	    	return;
	}
	else
	{
		fseek(fp,-1*strlen(lookahead->word),SEEK_CUR);
		return;
	}
}
void statement()
{
	lookahead=getNextToken(fp);
	//printf("%s\n",lookahead->word);
	if(strcmp(lookahead->word,"for")==0 || strcmp(lookahead->word,"while")==0)
	{
		fseek(fp,-1*strlen(lookahead->word),SEEK_CUR);
		//lookahead=getNextToken(fp);
		//printf("%s\n",lookahead->word );
		//printf("ls\n");
		looping_start();
		return;
	}
	else if(strcmp(lookahead->word,"if")==0)
	{
		fseek(fp,-1*strlen(lookahead->word),SEEK_CUR);
		//lookahead=getNextToken(fp);
		//printf("%s\n",lookahead->word );
		//printf("ls\n");
		decision_stat();
		return;
	}
    else if(strcmp(lookahead->word,"switch")==0)
    {
        fseek(fp,-1*strlen(lookahead->word),SEEK_CUR);
        //lookahead=getNextToken(fp);
        //printf("%s\n",lookahead->word );
        //printf("ls\n");
        switch_stat();
        return;
    }
	else
	{
		fseek(fp,-1*strlen(lookahead->word),SEEK_CUR);
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
	lookahead=getNextToken(fp);
	if (strcmp(lookahead->word,"==")==0 ||strcmp(lookahead->word,"!=")==0 ||strcmp(lookahead->word,"<=")==0 ||strcmp(lookahead->word,">=")==0 ||strcmp(lookahead->word,">")==0 ||strcmp(lookahead->word,"<")==0)
	{
		fseek(fp,-1*strlen(lookahead->word),SEEK_CUR);
	    relop();
	    simple_expn();
	    return;
	}
	else
	{
		fseek(fp,-1*strlen(lookahead->word),SEEK_CUR);
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
	lookahead=getNextToken(fp);
	if(strcmp(lookahead->word,"+")==0 ||strcmp(lookahead->word,"-")==0)
	{
		fseek(fp,-1*strlen(lookahead->word),SEEK_CUR);
	    addop();
	    term();
	    seprime();
	    return;
	}
	else
	{
		fseek(fp,-1*strlen(lookahead->word),SEEK_CUR);
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
	lookahead=getNextToken(fp);
	if(strcmp(lookahead->word,"*")==0 ||strcmp(lookahead->word,"/")==0 || strcmp(lookahead->word,"%")==0)
	{
		fseek(fp,-1*strlen(lookahead->word),SEEK_CUR);
	    mulop();
	    factor();
	    tprime();
	    return;
	}
	else
	{
		fseek(fp,-1*strlen(lookahead->word),SEEK_CUR);
		return;
	}
}
void factor()
{
    lookahead=getNextToken(fp);
    printf("%s\n",lookahead->word);
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
        printf("Err@ %s %d %d\n",lookahead->word,lookahead->row,lookahead->col);exit(0);
    }
}
void relop()
{
    lookahead=getNextToken(fp);
    printf("%s\n",lookahead->word);
    if (strcmp(lookahead->word,"==")==0 ||strcmp(lookahead->word,"!=")==0 ||strcmp(lookahead->word,"<=")==0 ||strcmp(lookahead->word,">=")==0 ||strcmp(lookahead->word,">")==0 ||strcmp(lookahead->word,"<")==0)
    {
        return;
    }
    else
        printf("Err@ %s %d %d\n",lookahead->word,lookahead->row,lookahead->col);exit(0);
}
void addop()
{
    lookahead=getNextToken(fp);
    printf("%s\n",lookahead->word);
    if(strcmp(lookahead->word,"+")==0 ||strcmp(lookahead->word,"-")==0)
    {
        return;
    }
    else
        printf("Err@ %s %d %d\n",lookahead->word,lookahead->row,lookahead->col);exit(0);
}
void mulop()
{
    lookahead=getNextToken(fp);
    printf("%s\n",lookahead->word);
    if(strcmp(lookahead->word,"*")==0 ||strcmp(lookahead->word,"/")==0 || strcmp(lookahead->word,"%")==0)
    {
        return;
    }
    else
        printf("Err@ %s %d %d\n",lookahead->word,lookahead->row,lookahead->col);exit(0);
}
int main()
{
    fp=fopen("f2.txt","r");
    lookahead=getNextToken(fp);
    if (strcmp(lookahead->word,"switch")==0)
    {
        fseek(fp,-1*strlen(lookahead->word),SEEK_CUR);
        switch_stat();
    }
    else
    {
        fseek(fp,-1*strlen(lookahead->word),SEEK_CUR);
        looping_start();
    }
    return 0;
}