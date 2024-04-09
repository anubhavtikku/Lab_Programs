import java.util.Scanner;
class Complex{
  double a,b;
  void init(double a,double b){
    this.a = a;
    this.b = b;
  }
  void display(){
    if(b<0)
      System.out.println(a+" -i "+(-b));
    else
      System.out.println(a+" +i "+b);
  }
  Complex add(Complex b){
    Complex sum = new Complex();
    sum.a = this.a+b.a;
    sum.b = this.b+b.b;
    return sum;
  }
  Complex subtract(Complex b){
    Complex diff = new Complex();
    diff.a = this.a-b.a;
    diff.b = this.b-b.b;
    return diff;
  }
  public static void main(String[] args){
    Scanner sc=new Scanner(System.in);
    Complex a=new Complex();
    System.out.println("Enter real and complex part of number 1");
    a.init(sc.nextDouble(),sc.nextDouble());
    System.out.println("Enter real and complex part of number 2");
    Complex b=new Complex();
    b.init(sc.nextDouble(),sc.nextDouble());
    Complex sum = a.add(b);
    Complex diff = a.subtract(b);
    System.out.print("Sum is ");
    sum.display();
    System.out.print("Difference is ");
    diff.display();
  }
}
