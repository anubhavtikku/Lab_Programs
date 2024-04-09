






int main() {
	int a,b[10],c,i;
	a=10;
	b[0]=5;
	if(a==10) {
		a=1;
	} else if(a==20){
		b=2;
	} else if(a==30) {
		c=3;
	} else {
		printf("bye\n");
	}
	switch(a) {
		case 1:
			b=2;
			printf("Hello World");
			break;
		case 2:
			a=a+b/9;
			printf("a is %d and b is %d",a,b);
		case 3:
			for(i=0; i<a; i=i+1) {
				b[i]=55;
			}
			break;
	}
	return 0;
}