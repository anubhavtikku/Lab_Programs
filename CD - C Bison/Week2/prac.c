#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct token
{char type[100];
 char name[100];
};

struct token getNextToken(FILE *fp)
{ char s[80];
  char ca,cb;
  struct token t;
  int k;

  ca=getc(fp);
  
  if(ca==' ')
  while(ca==' ')
  ca=getc(fp);

  if(ca=='#')
  { while(ca!='\n')
    ca=getc(fp);
    
  }

  if(ca=='$')
  {s[0]=ca;
   k=1;
   ca=getc(fp);
   while(ca!=' '&&ca!='('&&ca!=';'&&ca!=EOF)
   {s[k++]=ca;
    ca=getc(fp);
   }
   if(ca==EOF)
   exit(0);   

   s[k]='\0';
   fseek(fp,SEEK_CUR,-1);
   strcpy(t.name,s);
   strcpy(t.type,"Identifier");
   return t;
  }
 
 if(ca=='('||ca==')'||ca=='{'||ca=='}'||ca==','||ca==';')
  {s[0]=ca;s[1]='\0';
   strcpy(t.name,s);
   strcpy(t.type,"Special Symbol");
   return t;
  }

 if(ca=='@')
 { cb=getc(fp);
   if(cb=='_')
   {
   strcpy(t.name,"@_");
   strcpy(t.type,"Special Symbol");
   return t;
  }
 fseek(fp,SEEK_CUR,-1);
 
 }

 if(ca=='+')
 { cb=getc(fp);
   if(cb=='=')
   {
   strcpy(t.name,"+=");
   strcpy(t.type,"Assignment Operator");
   return t;
  }
 fseek(fp,SEEK_CUR,-1);
  }

if(ca=='+'||ca=='@'||ca=='_')
  {s[0]=ca;s[1]='\0';
   strcpy(t.name,s);
   strcpy(t.type,"Symbol");
   return t;
  }

k=1;
while(ca!=' '&&ca!='('&&ca!=';'&&ca!=EOF)
   {s[k++]=ca;
    ca=getc(fp);
   }

if(ca!=EOF)
fseek(fp,SEEK_CUR,-1);
s[k]='\0';

strcpy(t.name,s);
strcpy(t.type,"Keywords");
return t;

}

int main()
{struct token t;
FILE *fp;
fp=fopen("aa.c","r");

if(fp==NULL)
{printf("Error");
exit(0);
}

while(!feof(fp))
{t=getNextToken(fp);
printf("Name:%s\tType:%s\n",t.name,t.type);
}

return 0;
}
