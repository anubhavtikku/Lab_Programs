import java.util.Scanner;
class Time{
  int h,m,s;
  void init(int h,int m,int s){
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
    Time t1 = new Time();
    System.out.println("Enter first time(h,m,s)");
    t1.init(sc.nextInt(),sc.nextInt(),sc.nextInt());
    Time t2 = new Time();
    System.out.println("Enter second time(h,m,s)");
    t2.init(sc.nextInt(),sc.nextInt(),sc.nextInt());
    Time sum = t1.add(t2);
    Time diff = t1.sub(t2);
    int cmp = t1.compare(t2);
    System.out.print("Sum of the times is ");
    sum.display();
    System.out.print("Diff btwn the times is ");
    diff.display();
    String msg=" time greater than the ";
    if(cmp<0)
      msg="second"+msg+"first";
    else if(cmp>0)
      msg="first"+msg+"second";
    else
      msg="Both times are equal";
    System.out.println(msg);
  }
}
