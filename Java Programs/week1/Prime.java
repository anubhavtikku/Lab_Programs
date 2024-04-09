import java.io.*;
import java.util.*;

public class Prime
{ public static void main(String[] args)
  { int x;
    Scanner s=new Scanner(System.in);
    System.out.println("Enter number ");
    x=s.nextInt();
    System.out.println("Prime numbers till there are ");
    pno(x);
  }

  public static void pno(int n)
 { int i,j,s;
   for(i=2;i<n;i++)
   { s=0;
     for(j=2;j<i;j++)
     if(i%j==0)
     s=1;
     
   if(s==0)
   System.out.print(i + "\t");
     }
   
   }


}   
