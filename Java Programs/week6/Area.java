import java.io.*;
import java.util.*;	

abstract class Figure
{ int x,y;
  Figure(int x,int y)
  {this.x=x;
   this.y=y;}

   Figure(int x)
   {this.x=x;
   }

 abstract void area();

}

class Rectangle extends Figure
{ Rectangle(int x,int y)
	{
		super(x,y);
	}

  void area()
  { 
  	
   System.out.println("Area of Rectangle is "+x*y);
   
   } 
}


class Triangle extends Figure
{ Triangle(int x,int y)
	{
		super(x,y);
	}

	void area()
	{
	 System.out.println("Area of Triangle is "+x*y*0.5);
	}
}

class Square extends Figure
{  Square(int x)
	{
		super(x);
	}

	void area()
	{ 
	 System.out.println("Area of Square is "+x*x);
	}
}

class Area
{ public static void main(String args[])
	{ Figure f;
	  Rectangle t1=new Rectangle(10,20);
	  Triangle t2=new Triangle(2,3);
	  Square t3=new Square(2);
	  f=t1;
	  f.area();
	  f=t2;
	  f.area();
	  f=t3;
	  f.area();
         }
  }