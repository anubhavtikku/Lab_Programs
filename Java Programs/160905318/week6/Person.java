import java.util.*;
import java.text.*;
class Person{
	private String name;
	private Calendar birthDate;
	Person(String name,Calendar birthDate){
		this.name=name;
		this.birthDate=birthDate;
	}
	String getName(){return name;}
	Calendar getBirthDate(){return birthDate;}
}
class CollegeGraduate extends Person{
	private float gpa;
	private int year;
	CollegeGraduate(String name,Calendar birthDate,float gpa,int year){
		super(name,birthDate);
		this.gpa=gpa;
		this.year=year;
	}
	float getGpa(){return gpa;}
	int getYear(){return year;}	
}
class GraduateTest{
	public static void main(String args[]){
		SimpleDateFormat sdf=new SimpleDateFormat("dd-MM-yyyy");
		Scanner sc=new Scanner(System.in);
		System.out.print("Enter Name:");
		String name=sc.nextLine();
		System.out.print("Enter DOB(dd mm yyyy):");
		int d=sc.nextInt();
		int m=sc.nextInt()-1;
		int y=sc.nextInt();
		Calendar dob=new GregorianCalendar(y,m,d);
		System.out.print("Enter GPA:");
		float gpa = sc.nextFloat();
		System.out.print("Enter year of graduation:");
		int year=sc.nextInt();
		CollegeGraduate ob=new CollegeGraduate(name,dob,gpa,year);
		System.out.println("The details enetered are:-");
		System.out.format("Name:%s\nDate of Birth:%s\nGPA:%.2f\nYear of Graduation:%d\n",ob.getName(),sdf.format(ob.getBirthDate().getTime(),new StringBuffer(),new FieldPosition(0)),ob.getGpa(),ob.getYear());
	}
}