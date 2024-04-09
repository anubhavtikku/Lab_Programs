import java.io.*;
import java.util.*;

 
  class NumericFns<T extends Number>
  { T ob;
    
    NumericFns(T o)
    { ob=o;
      }
      
    public Double reciprocal()
    { 
           return 1/ob.doubleValue() ;
     }
     
    public Double fraction()
    {
         return (ob.doubleValue()-ob.intValue());
    } 
    
    }

   
   
  class boundsdemo
  { public static void main(String args[])
   { Scanner s=new Scanner(System.in);
     System.out.println("Enter integer "); 
     int x=s.nextInt();
     NumericFns<Integer> nu=new NumericFns<Integer>(x);
     System.out.println("Reciprocal is "+nu.reciprocal());
     System.out.println("Fraction is "+nu.fraction());
     
     System.out.println("\nEnter number "); 
     double y=s.nextDouble();
     NumericFns<Double> nu2=new NumericFns<Double>(y);
     System.out.println("Reciprocal is "+nu2.reciprocal());
     System.out.println("Fraction is "+nu2.fraction());
    }    
    }
    
    
