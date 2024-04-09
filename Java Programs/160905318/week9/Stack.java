import java.util.*;
import java.io.*;
class Stack<T>{
	Node<T> front;
	Stack(){
		front=null;
	}
	void push(T el){
		Node<T> ob=new Node<T>(el,front);
		front=ob;
	}
	T pop(){
		if(isEmpty())
			return null;
		T val=front.val;
		front=front.next;
		return val;
	}
	T peek(){
		if(isEmpty())
			return null;
		return front.val;
	}
	boolean isEmpty(){
		return front==null;
	}
	class Node<T>{
		T val;
		Node<T> next;
		Node(T val,Node<T> next){
			this.val=val;
			this.next=next;
		}
	}
}
class Student{
	String name;
	int std;
	double marks;
	Student(Scanner sc){
		System.out.print("Name:");
		name=sc.next();
		System.out.print("Standard:");
		std=sc.nextInt();
		System.out.print("Marks:");
		marks=sc.nextDouble();
	}

	@Override
	public String toString(){
		return "Student:\nName:"+name+"\nStandard:"+std+"\nMarks:"+marks;
	}
}
class Employee{
	String name;
	double salary;
	Employee(Scanner sc){
		System.out.print("Name:");
		name=sc.next();
		System.out.print("Salary:Rs.");
		salary=sc.nextDouble();
	}

	@Override
	public String toString(){
		return "Employee:\nName:"+name+"\nSalary:Rs."+salary;
	}
}
class StackTest{
	public static void main(String args[]){
		Scanner sc=new Scanner(System.in);
		Stack<Student> sstack=new Stack<Student>();
		Stack<Employee> estack=new Stack<Employee>();
		while(true){
			System.out.println("1. Student 2. Employee 3. Exit");
			int which=sc.nextInt();
			if(which==3)
				return;
			System.out.println("1. Push 2. Pop");
			int choice=sc.nextInt();
			if(which==1){
				if(choice==1)
					sstack.push(new Student(sc));
				else if(choice==2){
					Student ob=sstack.pop();
					if(ob!=null)
						System.out.println(ob);
				}
			}
			else if(which==2){
				if(choice==1)
					estack.push(new Employee(sc));
				else if(choice==2){
					Employee em=estack.pop();
					if(em!=null)
						System.out.println(em);
				}
			}
		}
	}
}