import java.io.*;
import java.util.*;

public class Pyramid
{
 public static void main(String[] args)
{ int n;
 System.out.println("Enter number ");
 Scanner s=new Scanner(System.in);
 n=s.nextInt();
System.out.println();
 stars(n);
 
}


static int stars(int n)
{ int i,j;
   for(i=1;i<=n;i++)
   { for(j=1;j<=i;j++)
   {  System.out.print("*");}
    System.out.print("\n");
    }
   

  return 0;
}

}
