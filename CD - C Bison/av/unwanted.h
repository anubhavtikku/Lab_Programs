#ifndef unwanted_h
#define unwanted_h
#include <unistd.h>

void removeUnwanted(FILE* fa, FILE* fb) {
	int ca,cb;
	ca = getc(fa);
	while(ca!=EOF) {
		if(ca=='"') {
			// ignore anything within quotes
			putc(ca,fb);
			cb = getc(fa);
			while(cb!='"') {
				putc(cb,fb);
				cb = getc(fa);
			}
			putc(cb,fb);
		} else if(ca=='/') {
			// remove comment
			cb = getc(fa);
			if(cb=='/') {
				ca = getc(fa);
				while(ca!='\n' && ca!=EOF) {
					// putc(ca,fb);
					ca = getc(fa);
				}
				if(ca==EOF)break;
				putc(ca,fb);
			} else if (cb=='*') {
				// putc(cb,fb);
				printf("multi line\n");
				while(1) {
					ca = getc(fa);
					if(ca=='\n') {
						printf("yes\n");
						putc(ca,fb);
					}else if(ca=='*') {
						ca = getc(fa);
						if(ca=='/') {
							break;
						}
					}
				}

			} else {
				putc(ca,fb);
				fseek(fa,(long)(-1),SEEK_CUR);
			}
		} else if(ca=='#') {
			// remove preprocessor
			cb = getc(fa);
			while(cb!='\n' && cb!=EOF) {
				cb = getc(fa);
			}
			if(cb==EOF)break;
			putc(cb,fb);
		} else {
			putc(ca,fb);
		}
		ca = getc(fa);
	}
}

#endif