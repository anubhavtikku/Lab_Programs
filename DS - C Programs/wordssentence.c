#include <stdio.h>
#include <stdlib.h>
int main()
{    int i,j,k=0;
	 char s[80];
     printf("Enter string ");
     gets(s);
     char **table=(char **)malloc(sizeof(char));
     for(i=0;s[i]!='\0';i++)
     	{if(i==0)
          { 
          	table[k++]=(char *)malloc(sizeof(char));
          	table[k-1]=&s[i];
          }
          if((s[i]==' ')&&(s[i+1]!=' ')&&(s[i+1]!='\0'))
          { 
          	table[k++]=(char *)malloc(sizeof(char));
          	table[k-1]=&s[i+1];
          }
         }

     printf("Words are ");
     for(i=0;i<k-1;i++)
     	printf("%s",table[i]);
     for(i=0;i<k-1;i++)
     {	for(j=0;table[i][j]!=' ' ;j++)
     	printf("%c",table[i][j]);
        printf("\n");  }

printf("%s",table[k-1]);      
}