import java.util.*;
import java.text.*;
import java.io.*;
class Patient{
	String name;
	int age,hospitalNumber;
	void init(String name,int age,int hospitalNumber){
		this.name=name;
		this.age=age;
		this.hospitalNumber=hospitalNumber;
	}
	void display(){
		System.out.format("Name:%s\nAge:%d\nHospital Number:%d\n",name,age,hospitalNumber);
	}
}
class Inpatient extends Patient{
	String departmentName, roomType;
	Calendar dateOfAddmission;
	void init(String name,int age,int hospitalNumber,String departmentName,String roomType,Calendar dateOfAddmission){
		super.init(name,age,hospitalNumber);
		this.departmentName=departmentName;
		this.roomType=roomType;
		this.dateOfAddmission=dateOfAddmission;
	}
	void display(){
		SimpleDateFormat sdf=new SimpleDateFormat("dd-MM-yyyy");
		super.display();
		System.out.format("Department Name:%s\nType Of Room:%s\nDate of Addmission:%s\n",departmentName,roomType,sdf.format(dateOfAddmission.getTime(),new StringBuffer(),new FieldPosition(0)));
	}
}
class Billing extends Inpatient{
	Calendar dateOfDischarge;
	Billing(String name,int age,int hospitalNumber,String departmentName,String roomType,Calendar dateOfAddmission,Calendar dateOfDischarge) {
		super.init(name,age,hospitalNumber,departmentName,roomType,dateOfAddmission);
		this.dateOfDischarge=dateOfDischarge;
	}
	void display(){
		int dayElapsed =(int) Math.ceil(dateOfDischarge.compareTo(dateOfAddmission)/60.0/60.0/24.0);
		double rate=0.0;
		switch(roomType){
			case "Special":rate=1200*dayElapsed;
			break;
			case "SemiSpecial":rate=600*dayElapsed;
			break;
			case "General":rate=150*dayElapsed;
			break;
			default:System.out.println("Incorrect room type");
			return;
		}
		super.display();
		System.out.println("Bill amount:Rs. "+rate);
	}
}
class PatientTest{
	public static void main(String args[]){
		Scanner sc=new Scanner(System.in);
		PrintStream out=System.out;
		out.print("Enter Name:");
		String name=sc.nextLine();
		out.print("Enter Age:");
		int age=sc.nextInt();
		out.print("Enter Hospital Number:");
		int hospitalNumber=sc.nextInt();
		out.print("Enter Department Name:");
		String departmentName=sc.next();
		out.print("Enter Room Type:");
		String roomType=sc.next();
		out.print("Enter Date of Addmission(dd mm yyyy):");
		int date=sc.nextInt();
		int month=sc.nextInt()-1;
		int year=sc.nextInt();
		Calendar dateOfAddmission=new GregorianCalendar(year,month,date);
		out.print("Enter Date of Discharge(dd mm yyyy):");
		date=sc.nextInt();
		month=sc.nextInt()-1;
		year=sc.nextInt();
		Calendar dateOfDischarge=new GregorianCalendar(year,month,date);
		Billing ob=new Billing(name,age,hospitalNumber,departmentName,roomType,dateOfAddmission,dateOfDischarge);
		ob.display();
	}
}