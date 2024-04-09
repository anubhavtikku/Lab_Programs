import java.io.*;
import java.util.*;
import java.lang.*;

class Patient
{ String name;
  int age;
  int hospitalnumber;

  Scanner s=new Scanner(System.in);

  void input()
  { System.out.println("Enter name ");
    name=s.nextLine();

    System.out.println("Enter age ");
    age=s.nextInt();

    System.out.println("Enter hospital number ");
    hospitalnumber=s.nextInt();

   }

   void output()
   { System.out.println("\nName "+name +"\nAge "+age+"\nHospital No "+hospitalnumber);
   }

  };

 class Inpatient extends Patient
  { String dname;
    GregorianCalendar addate;
    String roomtype;

   void in()
  { System.out.println("Enter department name ");
    String cls=s.nextLine();
    dname=s.nextLine();

    System.out.println("Enter admission date-year first followed by month and then date ");
    addate=new GregorianCalendar(s.nextInt(),s.nextInt(),s.nextInt());

    System.out.println("Enter room type- Special , SemiSpecial , General ");
    cls=s.nextLine();
    roomtype=s.nextLine();

   }
    
   void ou()
  { System.out.println("Department Name "+dname+"\nAdmission Date "+addate.get(Calendar.DATE)+"-"+addate.get(Calendar.MONTH)+"-"+
     addate.get(Calendar.YEAR));
    }

   };

 class Billing extends Inpatient
  { GregorianCalendar rdate;

    void i()
    { System.out.println("Enter release date-year first followed by month and then date ");
      rdate=new GregorianCalendar(s.nextInt(),s.nextInt(),s.nextInt());                        
     }

   void o()
    { System.out.println("Release Date "+rdate.get(Calendar.DATE)+"-"+rdate.get(Calendar.MONTH)+"-"+rdate.get(Calendar.YEAR));
      int b,d,p=1;
      d=(rdate.get(Calendar.YEAR)-super.addate.get(Calendar.YEAR))*365+(rdate.get(Calendar.MONTH)-super.addate.get(Calendar.MONTH))*30+
       (rdate.get(Calendar.DATE)-super.addate.get(Calendar.DATE));
              
      if(super.roomtype.equals("Special"))
      p=10;
      
      if(super.roomtype.equals("SemiSpecial"))
      p=5;

      if(p==10)
      p=1200;
      
      if(p==5)
      p=600;
     
      if(p==1)
      p=150;

      b=d*p;
      
      System.out.println("Bill Amount is "+b);     
        }

  };
    
 class fin
 { public static void main(String args[])
   { Billing s1=new Billing();
     s1.input();
     s1.in();
     s1.i();
     s1.output();
     s1.ou();
     s1.o();
     }
  }
      
