#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{FILE *fa;
 char ca,cb;
 int line=1,col=0;
 char c[][20]={"int","float","char","double"};
 char d[][20]={"INT","FLOAT","CHAR","DOUBLE"}; 

 fa=fopen("key.c","r");
  if(fa==NULL)
  {
  	printf("Cannot open file\n");
  	exit(0);
  }

char s[100];
int i,k=0;  

  while(ca!=EOF)
  { ca=getc(fa);col++;
    if(ca==' '||ca=='\n')
    {s[k++]='\0';
     
     for(i=0;i<4;i++)
     if(strcmp(c[i],s)==0)
     {int z=strlen(d[i]);printf("%s Line:%d Column:%d\n",d[i],line,col-z);}

     k=0;
     if(ca=='\n')
     {line++;col=0;}
    }

    else
    s[k++]=ca;
   
  }

  fclose(fa);
}
