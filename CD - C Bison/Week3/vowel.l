%{
int vowels=0;
int consonants=0;
%}

%%
[aeiouAEIOU] {vowels+=1;}
[A-Za-z^aeiouAEIOU] {consonants+=1;}
%%

int main()
{yylex();
printf("Vowels=%d\n",vowels);
printf("\nConsonants=%d\n",consonants);
}

int yywrap()
{return 1;
}
