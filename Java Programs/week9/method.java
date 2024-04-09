import java.io.*;
import java.util.*;

  class GenDemo<T>
  { 
    static<T extends Object> void print(T b[]) 
    { 
      int i;
      for(i=0;i<b.length;i++)
      System.out.println(b[i]);
     }
  
  } 
  
  class method
  { public static void main(String args[])
   { Integer a[]={1,2,3,4};
     GenDemo.print(a);
     String b[]={"aa","bb"};
     GenDemo.print(b);
     }
   }
