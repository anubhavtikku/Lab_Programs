#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

int main()
{char f[10],s[80];
 printf("Enter file name\n");
 scanf("%s",f);
 
 for(int i=0;i<80;i++)
 s[i]='\0';
 int fp,i; 
 fp=open(f,O_RDWR);
 read(fp,s,sizeof(s));
 close(fp);
 int ch=0,w=0,l=0;
 for(i=0;i<strlen(s);i++)
 {ch++;
  if(s[i]=='\n')
  l++;
  if(s[i]!=' ' && s[i+1]==' ' || s[i]=='\n')
  w++;
 }
 printf("No. of chars %d",ch);
 printf("\nNo. of words %d",w);
 printf("\nNo. of lines %d",l);
 
 return 0;

}
