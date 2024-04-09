import java.io.*;
import java.util.*;

class time
{int h;
 int m;
 int s;

 void assign(int hours,int min,int sec)
 {h=hours;
  m=min;
  s=sec;}

 void disp()
 {System.out.println("Time is "+h+" hours "+m+" min "+s+" sec ");
  }

 time add(time t1,time t2)
 { time a=new time();
   a.s=(t1.s+t2.s)%60;
   a.m=(t1.s+t2.s)/60;
   a.m+=t1.m+t2.m;
   a.h=a.m/60;
   a.m=a.m%60;
   a.h+=t1.h+t2.h;
   a.h=a.h%24;
   return a;
  }

 time sub(time t1,time t2)
 { time b=new time();
   b.h=t1.h-t2.h;
   b.m=t1.m-t2.m;
   b.s=t1.s-t2.s;
   b.m-=(t1.s-t2.s)/60;
   b.s=b.s%60; 
   b.h-=b.m/60;
   b.m=b.m%60;
   b.h=b.h%24;
   return b;
  }
 
 int compare(time t1,time t2)
 {  int i=0;
    if((t1.h==t2.h)&&(t1.m==t2.m)&&(t1.s==t2.s))
    { System.out.println("Objects are equal ");
      return 0;}
    if( (t1.h>t2.h) || ((t1.h==t2.h)&&(t1.m>t2.m)) || ((t1.h==t2.h)&&(t1.m==t2.m)&&(t1.s>t2.s)) )
     System.out.println("Objects 1 is greater ");
    else
     System.out.println("Objects 2 is greater ");
    
   return 0;
 }
};

class t
{ public static void main(String args[])
  { time t1=new time();
    time t2=new time();
    time t3=new time();
    time t4=new time();
    int x,y,z;
    Scanner s=new Scanner(System.in);
    System.out.println("Enter time in hours, min and sec for object 1");
    x=s.nextInt();
    y=s.nextInt(); 
    z=s.nextInt();
    t1.assign(x,y,z);
    System.out.println("Enter time in hours, min and sec for object 2");
    x=s.nextInt();
    y=s.nextInt(); 
    z=s.nextInt();
    t2.assign(x,y,z);
    t3=t3.add(t1,t2);
    t4=t4.sub(t1,t2);
    t3.disp();
    t4.disp();
    t1.compare(t1,t2);
   }
}
