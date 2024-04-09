import java.io.*;
import java.util.*;

class counter
{ static int count;
 
  counter()
  { count++;
  }

  static void showCount()
  { System.out.println("Counter value is "+count+"\n" );
     }

 };

class c
{ public static void main(String args[])
  { int i=0,x;
    
    
     do
    {
     System.out.println("Enter 1.To make new object 2.To Display Count 3.Exit ");
     Scanner s=new Scanner(System.in);
     x=s.nextInt();
    
     if(x==1)
     new counter();

     if(x==2)
     counter.showCount();
     
     if(x==3)
     break;

      }while(x==1 || x==2 );

  }
 }
