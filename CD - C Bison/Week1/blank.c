#include <stdio.h>
#include <stdlib.h>

int main()
{ FILE *fa,*fb;
  char ca,cb;
  fa=fopen("a.txt","r");
  if(fa==NULL)
  {
  	printf("Cannot open file\n");
  	exit(0);
  }
  fb=fopen("b.txt","w");
  ca=getc(fa);

  while(ca!=EOF)
  {
  	if(ca=='\t')
  	{putc(' ',fb);printf(" ");}

    else if(ca==' ')
    {cb=getc(fa);
     while(cb==' '&&cb!=EOF)
     cb=getc(fa);

     putc(ca,fb);
     if(cb!='\t')	
     putc(cb,fb);
     else
     putc(' ',fb);
     printf("%c%c",ca,cb);
    }

    else
    {putc(ca,fb);printf("%c",ca);}

    ca=getc(fa);
  }

  fclose(fa);
  fclose(fb);
}
