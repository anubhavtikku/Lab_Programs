#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<fcntl.h>
#include<string.h>
#include<unistd.h>
void main()
{
    int fp,l;
	fp=open("abc.txt",O_RDWR);
	char s[80];
	read(fp,s,sizeof(s));
	printf("%s",s);
	close(fp);
	fp=creat("c.txt",S_IRWXU);
	write(fp,s,strlen(s));
	close(fp);

}