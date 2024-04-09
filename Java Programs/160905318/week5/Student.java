import java.util.*;
import java.io.*;
class Student{
	int reg;
	String name;
	GregorianCalendar joining;
	short sem;
	float gpa,cgpa;
	static int student_number=0;
	Student(){
		reg=0;
		name="";
		joining=null;
		sem=0;
		gpa=cgpa=0.0f;
		student_number++;
	}
	Student(String name,GregorianCalendar joining,short sem,float gpa,float cgpa){
		this.name=name;
		this.joining=joining;
		this.sem=sem;
		this.gpa=gpa;
		this.cgpa=cgpa;
		reg=Integer.parseInt(joining.get(Calendar.YEAR)%100+""+student_number);
		student_number++;
	}
	void display(){
		System.out.println("Name:"+name);
		System.out.println("Registration Number:"+reg);
		int date = joining.get(Calendar.DATE);
		int month = joining.get(Calendar.MONTH)+1;
		int year = joining.get(Calendar.YEAR);
		System.out.format("%02d-%02d-%04d\n",date,month,year);
		System.out.println("Semester:"+sem);
		System.out.println("GPA:"+gpa+"\nCGPA:"+cgpa);
	}
	Student[] create(){
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter number of students(min 5)");
		int n=sc.nextInt();
		if(n<5){
			System.out.println("Entered number is less than 5");
			System.exit(0);
		}
		Student arr[]=new Student[n];
		for(int i=0;i<n;i++){
			System.out.println("Enter details for student "+(i+1));
			System.out.print("Name:");
			String name=sc.nextLine();
			name=sc.nextLine();
			System.out.println("Enter date of joining(dd mm yyyy)");
			int d=sc.nextInt();
			int m=sc.nextInt()-1;
			int y=sc.nextInt();
			GregorianCalendar doj=new GregorianCalendar(y,m,d);
			System.out.print("Enter Semester:");
			short sem=sc.nextShort();
			System.out.print("Enter GPA:");
			float gpa=sc.nextFloat();
			System.out.print("Enter CGPA:");
			float cgpa=sc.nextFloat();
			arr[i]=new Student(name,doj,sem,gpa,cgpa);
		}
		return arr;
	}
	static void sortSemCgpa(Student a[]){
		for(int i=0;i<a.length;i++){
			for(int j=0;j<a.length-i-1;j++){
				if((a[j].sem<a[j+1].sem) || (a[j].sem==a[j+1].sem && a[j].cgpa<a[j+1].cgpa)){
					Student temp=a[j];
					a[j]=a[j+1];
					a[j+1]=temp;
				}
			}
		}
	}
	static void sortName(Student a[]){
		for(int i=0;i<a.length;i++){
			for(int j=0;j<a.length-i-1;j++){
				if(a[j].name.compareTo(a[j+1].name)>0){
					Student temp=a[j];
					a[j]=a[j+1];
					a[j+1]=a[j];
				}
			}
		}
	}
	static void listStarts(Student a[],char start){
		for(Student i:a){
			if(i.name.charAt(0)==start)
				i.display();
		}
	}
	static void listContains(Student a[],String key){
		for(Student i:a){
			if(i.name.contains(key))
				i.display();
		}
	}
	void toInitials(){
		String a[]=name.split(" ");
		name="";
		for(int i=0;i<a.length-1;i++){
			name+=a[i].charAt(0)+". ";
		}
		name+=a[a.length-1];
		display();
	}
	public static void main(String args[])throws IOException{
		Scanner sc=new Scanner(System.in);
		Student ob=new Student();
		Student a[]=ob.create();
		System.out.println("Students sorted accprding to sem and cgpa are:-");
		sortSemCgpa(a);
		for(Student i:a)
			i.display();
		System.out.println("Students sorted according to name are:-");
		sortName(a);
		for(Student i:a)
			i.display();
		System.out.print("Enter character:");
		char ch=(char)System.in.read();
		System.out.print("Students whose name starts with "+ch+" are:-");
		listStarts(a,ch);
		System.out.print("Enter searching string:");
		String s=sc.next();
		System.out.print("Students whose name contains "+s+" are:-");
		listContains(a,s);
		System.out.print("Students after their names have been modified:-");
		for(Student i:a)
			i.toInitials();
	}
}