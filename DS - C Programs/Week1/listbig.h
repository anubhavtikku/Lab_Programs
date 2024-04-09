int listbig(int a[],int n)
{ int x=a[0],i;
	for(i=0;i<n;i++)
		if(a[i]>x)
			x=a[i];

	return x;

}