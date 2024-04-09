import java.io.*;
import java.util.*;
import buildin.*;

class buildho
{ public static void main(String args[])
  { Building t1=new Building();
  	House t2=new House();
  	School t3=new School();
   
   t1.setPar(1000,1);
   System.out.println("Square feet "+t1.getsq()+" Building "+t1.getst());

   t2.setP(3,2);
   System.out.println("Bed Rooms "+t2.getbe()+" Baths "+t2.getba());
   
   t3.setPare(5,"Elementary");
   System.out.println("No. of classes "+t3.getnc()+" Grade Level "+t3.getgl());

  }


}