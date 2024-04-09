import java.util.Scanner;
class Die{
  int sideUp;
  void roll(){
    sideUp =(int) (1+Math.random()*5);
  }
  public static void main(String args[]){
    Die a,b;
    a=new Die();
    b=new Die();
    a.roll();
    b.roll();
    System.out.println(a.sideUp+b.sideUp);
  }
}
