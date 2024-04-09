import java.io.*;
import java.util.*;

 
  class Student 
  { String Name;
  
    Student(String n)
    { Name="Student "+n;
    }	

  @Override
  public String toString () {
    return Name;
     }
  }
  
  class Employee 
  { String Name;
    
    Employee(String n)
    { Name="Employee "+n;
    }
    
       @Override
  public String toString () {
    return Name;
     }
              
   }

class Stack<T>
{ private ArrayList<T> stack =new ArrayList<T> ();
  int top;
  
  Stack()
  { 
    top=0;
   }
    

  void push(T ob)
  {  stack.add(top++,ob);
   }
   
   void pop()
   { if(top==0)
    { System.out.println("Stack is empty ");
      return;
    }
     stack.remove(--top);
    }
    

  void disp()
  {  for (T nu : stack) 
     System.out.println(nu); 
  }

  }

  class e
  { public static void main(String args[])
    { Student stu;
      Employee emp;
      Scanner s=new Scanner(System.in);
      Stack<Employee> st=new Stack<Employee>();
      Stack<Student> st2=new Stack<Student>();
      
      int x,y;
      do
       { System.out.println("Enter 1.Employee 2.Student ");
           y=s.nextInt(); 

         System.out.println("Enter 1.Push 2.Pop 3.Display 4.Exit ");
         x=s.nextInt();
       
         if(x==1)
         { 
           System.out.println("Enter name ");
           String n=s.nextLine();
           n=s.nextLine();
           if(y==1)
           { emp=new Employee(n);
             st.push(emp);
             }
           
           if(y==2)
           { stu=new Student(n);
             st2.push(stu);
             }      
         }
         
         if(x==2)
         { if(y==1)
           st.pop();

           if(y==2)
            st2.pop();
         }
         
         if(x==3)
         { 
          if(y==1)
          st.disp();

          if(y==2)
          st2.disp();  
          }
         
         } while(x==1 || x==2 || x==3);      
    }
    }
