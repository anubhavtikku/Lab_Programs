import java.io.*;
import java.util.*;

class st
{int a[]=new int[20] ;
 int x;

 st()
 { x=-1;}

 void push(int s)
{ if(x==20)
  System.out.println("Stack Overflow ");
   else
   { a[++x]=s; }
      
   }

void pop()
{ 
  if(x==-1)
  System.out.println("Stack Underflow");
  else
  { 
    System.out.println("Pop "+a[x]);
    a[x]='\0';
    x--;
   }
}

void display()
{ int i;
  System.out.println("Stack is ");
  for(i=0;i<=x;i++)
  System.out.print(a[i]+"\t");
}

};

class stack
{ public static void main(String args[])
 { st b=new st();
   Scanner s=new Scanner(System.in);
   int x,y;
 
   do
  { System.out.println("\nEnter option for 1.Push 2.Pop 3.Display 4.Exit ");
    x=s.nextInt();

   if(x==1)
   { System.out.println("Enter number to push ");
     y=s.nextInt();
     b.push(y);
    }

   if(x==2)
   b.pop();

   if(x==3)
   b.display();
   }while(x==1 || x==2 || x==3);
           }
        }

