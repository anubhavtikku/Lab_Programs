#include <stdio.h>
#include <math.h>
#include "getdata.h"
#include "quadratic.h"
#include "print_roots.h"

int main()
{ int a,b,c,d,e,f,g;
  int *x=&a,*y=&b,*z=&c,*r1=&d,*r2=&e,*fl=&g;
  *fl=0;
  getdata(x,y,z);
  quadratic(x,y,z,r1,r2,fl);
  if((*fl)==0)
    print_roots(r1,r2);
  
 return 0;
}