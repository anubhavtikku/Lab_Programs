import java.io.*;
import java.util.*;

class no
{ public static void main(String args[])
  {  String a,b="";
    int x,i,k=-1,l=0;
    char s1;
    Scanner s=new Scanner(System.in);
    System.out.println("Enter String of numbers ");
    a=s.nextLine();
    x=a.length();

    for(i=x-1;i>=0;i--)
    {   b=a.charAt(i)+b;
        l=l+1;
        if((l==3)&&(i!=0))	
        { b=','+b;
          l=0;
        }
    }
   System.out.println("\nOld String is " + a);
   System.out.println("\nModified String is " + b);
                                             
  }
 } 
