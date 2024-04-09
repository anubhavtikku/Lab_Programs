%{
int chars=0;
int words=0;
int lines=0;
int blanks=0;
%}

%%
[A-Za-z]+ {words++;chars+=strlen(yytext);}
\n {chars++;lines++;}
" " {chars++;blanks++;}
%%

int main(int argc,char *argv[])
{yylex();
printf("Lines=%d\nWords=%d\nBlanks=%d\nChars=%d\n",lines,words,blanks,chars);
}

int yywrap()
{return 1;}
