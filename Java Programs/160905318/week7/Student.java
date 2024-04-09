import java.util.Scanner;
class Student{
	int regno;
	String name;
	Student(String name,int regno)throws SeatsFilledException{
		this.name=name;
		this.regno=regno;
		if((regno%100) > 25)
			throw new SeatsFilledException();
	}
	public static void main(String args[])throws SeatsFilledException{
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter Name:");
		String name=sc.nextLine();
		System.out.println("Enter Registration Number:");
		int regno=sc.nextInt();
		Student st=new Student(name,regno);
		System.out.println("Record Created Successfully");
	}
}

class SeatsFilledException extends Exception{
	public String toString(){
		return "Seats Full for the year";
	}
}