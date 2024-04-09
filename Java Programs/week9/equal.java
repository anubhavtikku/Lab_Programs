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
    
    
boolean absEqual(NumericFns<? extends Number> n){
System.out.println("Num1: "+ob.doubleValue()+"\nNum2: "+n.ob.doubleValue());
return Math.abs(ob.doubleValue())==Math.abs(n.ob.doubleValue());
}
    
    }

   
   
  class equal
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
     
     System.out.println("Numbers are equal - "+nu2.absEqual(nu));
    }    
    }
    
