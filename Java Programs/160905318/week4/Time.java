import java.util.Scanner;
class Time{
  int h,m,s;
  Time(){
    h=m=s=0;
  }
  Time(int sec){
    s=sec%60;
    sec/=60;
    m=sec%60;
    h=sec/60;
    if(h>=24){
      System.out.println("Entered time exceeds 24 hours");
      System.exit(0);
    }
  }
  Time(int m,int s){
    m+=s/60;
    s%=60;
    h=m/60;
    m%=60;
    this.s=s;
    this.m=m;
    if(h>=24){
      System.out.println("Entered time exceeds 24 hours");
      System.exit(0);
    }
  }
  Time(int h,int m,int s){
    m+=s/60;
    s%=60;
    h+=m/60;
    m%=60;
    this.s = s;
    this.m = m;
    this.h = h;
    if(h>=24){
      System.out.println("Entered time exceeds 24 hours");
      System.exit(0);
    }
  }
  void init(int h,int m,int s){
    m+=s/60;
    s%=60;
    h+=m/60;
    m%=60;
    this.s = s;
    this.m = m;
    this.h = h;
    if(h>24){
      System.out.println("Entered time exceeds 24 hours");
      System.exit(0);
    }
  }
  void display(){
    System.out.format("%02d:%02d:%02d\n",h,m,s);
  }
  Time add(Time b){
    Time sum = new Time();
    sum.h=h+b.h;
    sum.m=m+b.m;
    sum.s=s+b.s;
    sum.m+=sum.s/60;
    sum.h+=sum.m/60;
    sum.s%=60;
    sum.m%=60;
    return sum;
  }
  Time sub(Time b){
    int c=compare(b);
    Time t1,t2;
    t1=this;
    t2=b;
    if(c<0){
      t1=b;
      t2=this;
    }
    Time diff=new Time();
    diff.s = t1.s-t2.s;
    diff.m = t1.m-t2.m;
    diff.h = t1.h-t2.h;
    if(diff.s < 0){
      diff.s = 60+diff.s;
      diff.m--;
    }
    if(diff.m < 0){
      diff.m = 60+diff.m;
      diff.h--;
    }
    diff.m+=diff.s/60;
    diff.h+=diff.m/60;
    diff.s%=60;
    diff.m%=60;
    return diff;
  }
  int compare(Time b){
    if(h-b.h!=0)
      return h-b.h;
    if(m-b.m!=0)
      return m-b.m;
    if(s-b.s!=0)
      return s-b.s;
    return 0;
  }
  public static void main(String[] args){
    Scanner sc=new Scanner(System.in);
    Time t[]=new Time[2];
    for(int i=0;i<2;i++){
      System.out.println("Enter time "+(i+1));
      System.out.println("Enter 1 for only sec, 2 for min and sec and 3 for hour, min and sec"); 
      int c=sc.nextInt();
      System.out.println("Enter values in order");
      switch(c){
        case 1: t[i]=new Time(sc.nextInt());
                break;
        case 2: t[i]=new Time(sc.nextInt(),sc.nextInt());
                break;
        case 3: t[i]=new Time(sc.nextInt(),sc.nextInt(),sc.nextInt());
                break;
        default: i--;
      }
    } 
    Time sum = t[0].add(t[1]);
    Time diff = t[0].sub(t[1]);
    int cmp = t[0].compare(t[1]);
    System.out.print("Time 1 is ");
    t[0].display();
    System.out.print("Time 2 is ");
    t[1].display();
    System.out.print("Sum of the times is ");
    sum.display();
    System.out.print("Diff btwn the times is ");
    diff.display();
    String msg="";
    if(cmp<0)
      msg="second time greater than the first";
    else if(cmp>0)
      msg="first time greater than the second";
    else
      msg="Both times are equal";
    System.out.println(msg);
  }
}
