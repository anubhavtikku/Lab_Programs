int *add(int *a,int *b)
{   int x;
	int *c=&x;
	*c = *a + *b;
	return(c);

  }