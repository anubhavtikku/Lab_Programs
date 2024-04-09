void quadratic(int *x,int *y,int *z,int *r1,int *r2,int *fl)
{ int d;
	d= ((*y)*(*y))-(4*(*x)*(*z));
	
	if(d<0)
		{printf("Roots are imaginary ");
	      *fl=1;
	     }

	*r1= (-(*y) + sqrt(d) ) / (2*(*x));
	*r2= (-(*y) - sqrt(d) ) / (2*(*x));	

}