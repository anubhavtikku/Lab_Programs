#include<stdio.h>
//IGNORE
int main()
/*IGNORE*/
{FILE *fp;
 char s[80];
 int line=1,col=0;
 
 fp=open("abc.c",r);

 if(fp==NULL)
 {
 printf("Can't open file");
 exit(0);
 }

 char s[100];
 int i,k=0;

 while(fscanf(fp,s)!=EOF)
 {
 printf("%s\n",s);

 }
//
}

