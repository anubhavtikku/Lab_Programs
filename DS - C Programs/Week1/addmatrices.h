void addmatrices(int a[10][10], int b[10][10],int m,int n,int c[10][10])
{
	int i,j;
	for(i=0;i<m;i++)
  	for(j=0;j<n;j++)
  		{ c[i][j]=a[i][j]+b[i][j];
  	      printf("%d \t",c[i][j]);}
}