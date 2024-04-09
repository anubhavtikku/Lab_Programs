import java.util.Scanner;
class Stack{
  int a[],top;
  Stack(int c){
    a=new int[c];
    top=0;
  }
  void push(int n){
    if(top==a.length){
      System.out.println("Stack Overflow");
      return;
    }
    a[top++]=n;
  }
  int pop(){
    if(top==0){
      System.out.println("Stack Underflow");
      return Integer.MIN_VALUE;
    }
    top--;
    return a[top];
  }
  void display(){
    for(int i=0;i<top;i++){
      System.out.print(a[i]+" ");
    }
    System.out.println();
  }
  public static void main(String[] args){
    Scanner sc=new Scanner(System.in);
    System.out.println("Enter stack capacity");
    Stack ob=new Stack(sc.nextInt());
    while(true){
      System.out.println("1. Push\n2. Pop\n3. Display\n4. Exit");
      switch(sc.nextInt()){
        case 1:System.out.println("Enter element");
               ob.push(sc.nextInt());
               break;
        case 2:int n=ob.pop();
               if(n!=Integer.MIN_VALUE)
                 System.out.println("Popped "+n);
               break;
        case 3:ob.display();
               break;
        case 4:return;
      }
    }
  }
}
