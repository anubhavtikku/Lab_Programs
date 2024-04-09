import java.io.*;
import java.util.*;

public class Largest
{
 public static void main(String[] args)
{ int x,y,z,a;
System.out.println("Enter three numbers ");
Scanner s=new Scanner(System.in);
x=s.nextInt();
y=s.nextInt();
z=s.nextInt();

a=large(x,y,z);
System.out.println("Largest number is " + a);
}

static int large(int x,int y,int z)
{ if ((x>y)&&(x>z))
   return x;
  if ((y>x)&&(y>z))
   return y;
  if ((z>x)&&(z>y))
   return z;
   
  return 0;
}

}
