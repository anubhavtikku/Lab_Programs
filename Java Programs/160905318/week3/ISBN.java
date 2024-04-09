import java.util.Scanner;
class ISBN{
  long isbn;
  void inputISBN(long n){
    isbn=n;
  }
  boolean checkISBN(){
    if(isbn<1000000000 || isbn>9999999999l){
      System.out.println("Should be 10 digits");
      System.exit(0);
    }
    int c=10;
    long sum=0,n=isbn;
    while(n>0){
      sum+=(n%10)*c;
      c--;
      n/=10;
    }
    return sum%11 == 0;
  }
  public static void main(String[] args){
    Scanner sc=new Scanner(System.in);
    System.out.println("Enter isbn number");
    ISBN ob=new ISBN();
    ob.inputISBN(sc.nextLong());
    if(ob.checkISBN())
      System.out.println("Legal ISBN");
    else
      System.out.println("Illegal ISBN");
  }
}
