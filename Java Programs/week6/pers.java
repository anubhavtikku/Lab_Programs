import java.io.*;
import java.util.*;


class Person
{ String name;
  Calendar Date;
  
  Scanner s=new Scanner(System.in);
  
  Person()
  { name="";
    Date=new GregorianCalendar();
   }

  void input()
  { System.out.println("Enter name ");
    name=s.nextLine();

    System.out.println("Enter Birth date-year first , followed by month and date ");
    Date=new GregorianCalendar(s.nextInt(),s.nextInt(),s.nextInt());

   }

  void output()
  {  System.out.println("\nName "+name +"\nDOB "+Date.get(Calendar.DATE)+"-"+Date.get(Calendar.MONTH)+"-"+Date.get(Calendar.YEAR));
    }

  String n()
  { return name;
   }

  Calendar d()
  { return Date;
   }

   };
    
class CollegeGraduate extends Person
{ double GPA;
  int year;
  
  CollegeGraduate()
  { GPA=0;
    year=2000;
  }
  
 void in()
 { System.out.println("Enter GPA ");
    GPA=s.nextDouble();

   System.out.println("Enter year of Graduation ");
    year=s.nextInt();
  }
  
 void di()
 { System.out.println("GPA "+GPA+"\nGraduation Year "+year); 
   }
};

class pers
{ public static void main(String args[])
  { CollegeGraduate s1=new CollegeGraduate();
    s1.input();
    s1.in();
    s1.output();
    s1.di();
    }
 }

