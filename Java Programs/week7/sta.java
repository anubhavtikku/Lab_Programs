import java.io.*;
import java.util.*;

interface Stack
{ 
  void push(int x);
  void pop();

 }



class FixedStack implements Stack
{ 
   int a[]=new int[10];
   int top=-1;
   
              
   public void push(int item)
   { if(top==9)
     {System.out.println("Stack is full ");
      return;
      }
     a[++top]=item;
     }

   public void pop()  
    { if(top==-1)
      {System.out.println("Stack is empty ");
      return;
      }  
      
      top=top-1;
      }

   public void disp()
   {  int i;
      for(i=0;i<=top;i++)
      System.out.println(a[i]+"\t");
       }
  };

class DynamicStack implements Stack
{ LinkedList<Integer> st;
  
  DynamicStack()
  { st=new LinkedList<Integer>();
   }

  public void push(int item)
   { st.add(item);
    }
   
   public void pop()  
    {  if(st.size()==0)
       { System.out.println("Stack is empty ");
        return;
       }   
       st.remove();
     }
    
 };

class sta
 { public static void main(String args[])
     { Scanner s=new Scanner(System.in);
       FixedStack t1=new FixedStack();
       DynamicStack t2=new DynamicStack();
       int x,ele,y;
       do
       {System.out.println("Enter 1.Fixed Stack  2.Dynamic Stack ");
        x=s.nextInt();

        System.out.println("Enter 1.Push  2.Pop 3.Exit ");
        y=s.nextInt();

        if(x==1)
        { if(y==1) 
          { System.out.println("Enter element ");
            ele=s.nextInt();
            t1.push(ele);
          }

          if(y==2)
          { t1.pop();
          }
        }

      if(x==2)
        { if(y==1) 
          { System.out.println("Enter element ");
            ele=s.nextInt();
            t2.push(ele);
          }

          if(y==2)
          { t2.pop();
          }
        }



       }while(y==1 || y==2);
              }
  }

