#include <stdio.h>
#include <stdlib.h>
#define PI 3.14

int main()
{FILE *fa,*fb;
 char ca,cb;
 int k=0; 

 fa=fopen("a1.c","r");
  if(fa==NULL)
  {
  	printf("Cannot open file\n");
  	exit(0);
  }
  fb=fopen("b1.c","w");
  ca=getc(fa);
  
  while(ca!=EOF)
  { if(ca=='#'&&(k==0||cb=='\n'))
    { while(ca!='\n'&&ca!=EOF)
      ca=getc(fa);
      
      if(ca==EOF)
      break;
      cb=ca;	
      ca=getc(fa);
    }
    else
    {putc(ca,fb);ca=getc(fa);}
    k=1;
  }

  fclose(fa);
  fclose(fb);
}
