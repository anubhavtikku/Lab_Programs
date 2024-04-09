#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
void main()
{
	int fp,l;
	fp=creat("abc.txt",S_IRWXU);
	char s[80];
	printf("Enter string ");
	fgets(s,sizeof(s),stdin);
	write(fp,s,strlen(s));
	close(fp);

}