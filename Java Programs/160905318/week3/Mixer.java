import java.util.Scanner;
class Mixer{
  int arr[];
  int n;
  Mixer(int n){
    this.n=n;
    arr=new int[n];
  }
  void accept(){
    Scanner sc=new Scanner(System.in);
    System.out.println("Enter numbers:");
    int p=Integer.MIN_VALUE;
    for(int i=0;i<n;i++){
      int a=sc.nextInt();
      if(a<=p){
        System.out.println("Input is not in ascending order");
        System.exit(0);
      }
      p=a;
      arr[i]=a;
    }
  }
  Mixer mix(Mixer A){
    int n = this.n+A.n;
    Mixer ob=new Mixer(n);
    int a=0,b=0,i=0;
    for(i=0;i<n && a<this.n && b<A.n;i++){
      ob.arr[i]=(arr[a]>A.arr[b]?A.arr[b++]:arr[a++]);
    }
    while(a<this.n)
      ob.arr[i++]=arr[a++];
    while(b<A.n)
      ob.arr[i++]=A.arr[b++];
    return ob;
  }
  void display(){
    for(int i:arr)
      System.out.print(i+" ");
    System.out.println();
  }
  public static void main(String args[]){
    Scanner sc=new Scanner(System.in);
    System.out.println("Enter number of elements in array1");
    Mixer A = new Mixer(sc.nextInt());
    A.accept();
    System.out.println("Enter number of elements in array2");
    Mixer B = new Mixer(sc.nextInt());
    B.accept();
    Mixer mix = A.mix(B);
    System.out.println("Mixed matrix:");
    mix.display();
  }
}

