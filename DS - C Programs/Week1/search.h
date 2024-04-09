int search(int a[10],int n,int i)
{ int j=0;
  for(j=0;j<n;j++)
   if(a[j]==i)
   return 1;

  return 0; }