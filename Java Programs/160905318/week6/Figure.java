import java.util.*;
abstract class Figure{
	int l,b;
	abstract double area();
}
class Rectangle extends Figure{
	Rectangle(int l,int b){
		super.l=l;
		super.b=b;
	}
	double area(){
		return l*b;
	}
}
class Triangle extends Figure{
	Triangle(int l,int b){
		super.l=l;
		super.b=b;
	}
	double area(){
		return 0.5*l*b;
	}
}
class Square extends Figure{
	Square(int s){
		l=b=s;
	}
	double area(){
		return l*b;
	}
}
class TestFigure{
	public static void main(String args[]){
		Figure ob;
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter dimensions of Rectangle:");
		ob=new Rectangle(sc.nextInt(),sc.nextInt());
		System.out.println("Area of Rectangle:"+ob.area());
		System.out.println("Enter dimensions of Triangle:");
		ob=new Triangle(sc.nextInt(),sc.nextInt());
		System.out.println("Area of Triangle:"+ob.area());
		System.out.println("Enter dimension of Square:");
		ob=new Square(sc.nextInt());
		System.out.println("Area of Square:"+ob.area());
	}
}