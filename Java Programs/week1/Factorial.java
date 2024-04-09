import java.io.*;
import java.util.*;

public class Factorial
{ 
public static void main(String[] args)

{ int x,n,r,c;
  Scanner s=new Scanner(System.in);
  System.out.println("Enter no. for factorial ");
  x=s.nextInt();
  int f=fact(x);
  System.out.println("The factorial of no. is "+f); 
  System.out.println("Enter n and r for nCr "); 
  n=s.nextInt();
  r=s.nextInt();
  c=fact(n)/(fact(r)*fact(n-r));
  System.out.println("nCr is "+c);

}

static int fact(int n)
{if (n==1)
     return 1;
 else
  return (n*fact(n-1));

}

}
