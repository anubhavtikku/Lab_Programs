#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct token
{char s1[80];
 int l;
 int c;
 char t[80];
};

typedef struct token Token;

Token a[500];
int tsize=0;

void createtoken(char s[],int *k,int l,int c)
{
	if(*k==0)
		return;
	s[*k]='\0';
	strcpy(a[tsize].s1,s);
	a[tsize].l=l;
	a[tsize].c=c-strlen(s);
	if(*k==1 && s[0]=='+'||s[0]=='-'||s[0]=='*'||s[0]=='/')
		strcpy(a[tsize].t,"Arithmetic");
	else if(*k==1 && s[0]=='>'||s[0]=='<')
		strcpy(a[tsize].t,"Relation");
	else if(*k==1 && s[0]=='('||s[0]==')'||s[0]=='{'||s[0]=='}')
		strcpy(a[tsize].t,"Bracket");
	else if(*k==1 && s[0]==';')
		strcpy(a[tsize].t,"Semi Colon");
	else if(*k==1 && s[0]==',')
		strcpy(a[tsize].t,"Comma");
	else if(*k==1 && s[0]=='=')
		strcpy(a[tsize].t,"Assignment");
	else if(s[0]=='"')
		strcpy(a[tsize].t,"Text");
	else	
        strcpy(a[tsize].t,"Identifier");

    tsize++;
}

int main()
{FILE *fp;
 char ca,cb;
 char s[2000];

 int line=1,col=0;
 
 fp=fopen("abc.c","r");

 if(fp==NULL)
 {
 	printf("Can't open file");
 	exit(0);
 }

 int i,z;
 int *k=(int *)malloc(sizeof(int *));
 *k=0;

 ca=getc(fp);

 while(ca!=EOF)
 {  z=0;
 	col++;
    
   if(ca=='/')
    {
    	cb=getc(fp);
    	if(cb=='/')
    	{while(ca!='\n'&&ca!=EOF)
    	 ca=getc(fp);
		 
		 line++;
		 col=0;
    	 *k=0;
    	 ca=getc(fp);
    	 z=1;
    	}
    	else if(cb=='*')
    	{

    	do{
    		while(ca!='*')
    			ca=getc(fp);
    		ca=getc(fp);
    	}while(ca!='/');

    	line++;
		 col=0;
    	 *k=0;
    	 ca=getc(fp);
    	 z=1;	
    	}

        else
        fseek(fp,SEEK_CUR,-1);
    }

    if(z==0){
    
    if(ca=='#')
    {   while(ca!='\n'&&ca!=EOF)
    	{ca=getc(fp);
       }

    	if(ca==EOF)
    		break; 
    	//createtoken(s,k,line,col);
    	line++;
    	
    	col=0;
    	*k=0;
    	//ca=getc(fp);
    	//continue;
    }
    
    else if(ca=='+'||ca=='-'||ca=='*'||ca=='/'||ca==';'||ca==','||ca==')'||ca=='('||ca=='{'||ca=='}'||ca=='=')
    { createtoken(s,k,line,col);
      s[0]=ca;
      *k=1;
      createtoken(s,k,line,col);
      *k=0;
    }
 	
    else if(ca==' ')
    {createtoken(s,k,line,col);
     *k=0;
    }

    else if(ca=='\n')
    {createtoken(s,k,line,col);
     line++;
     col=0;
     *k=0;
    }

     /*else if(ca=='/')
 	{cb=getc(fp);
 	if(cb=='/')
 	while(ca!='\n'||ca!=EOF)
        ca=getc(fp);
 	}*/

    else
    s[(*k)++]=ca;
  
    
    ca=getc(fp);
}

 }

fclose(fp);

for(i=0;i<tsize;i++)
	printf("%s %d %d %s\n\n",a[i].s1,a[i].l,a[i].c,a[i].t);
printf("tsize%d",tsize);
return 0;
}
