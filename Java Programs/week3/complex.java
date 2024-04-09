import java.io.*;
import java.util.*;

class comp
{int r;
 int i;
 
 void init(int x,int y)
 {r=x;
  i=y;  
 }

 void display()
 { System.out.println("Number is "+r+"+i"+i); }

 comp add(comp c1,comp c2)
 { comp a=new comp();
   a.r=c1.r+c2.r;
   a.i=c1.i+c2.i;
   System.out.println("Sum is "+a.r+"+i"+a.i);
   return a;
  }
 
  comp sub(comp c1,comp c2)
 { comp b=new comp();
   b.r=c1.r-c2.r;
   b.i=c1.i-c2.i;
   System.out.println("Diff is "+b.r+"+i"+b.i);
   return b;
  }
 
 };

class complex
{ public static void  main(String args[])
  { int x,y;
    Scanner s=new Scanner(System.in);
    System.out.println("Enter real and imaginary value of first number ");
    x=s.nextInt();
    y=s.nextInt();
    comp c1=new comp();
    c1.init(x,y);

    System.out.println("Enter real and imaginary value of second number ");
    x=s.nextInt();
    y=s.nextInt();
    comp c2=new comp();
    c2.init(x,y);
    comp c3=new comp();
    comp c4=new comp();
    
    c1.display();
    c2.display();
    c3=c3.add(c1,c2);
    c4=c4.sub(c1,c2);
     }  
}
