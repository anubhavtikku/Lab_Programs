import java.io.*;
import java.util.*;
class Employee{
	String name;
	int age;
	double grossSalary;
	float takeHomeSalary;
	char grade;
	void input(BufferedReader br){
		PrintStream out=System.out;
		try{
			out.println("Name:");
			name=br.readLine();
			out.println("Age:");
			age=Integer.parseInt(br.readLine());
			out.println("Gross Salary:");
			grossSalary=Double.parseDouble(br.readLine());
			out.println("Take Home Salary:");
			takeHomeSalary=Float.parseFloat(br.readLine());
			out.println("Grade:");
			grade=(char)System.in.read();
		}catch(IOException e){
			System.out.println("Error:" + e);
		}
	}
	void display(){
		System.out.format("Name:%s\nAge:%d\nGross Salary:%f\nTake Home Salary:%f\nGrade:%c\n",name,age,grossSalary,takeHomeSalary,grade);

	}
	public static void main(String[] args)throws IOException{
		BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
		Scanner sc=new Scanner(System.in);
		Employee emp=new Employee();
		while(true){
			System.out.println("1. Input 2. Display 3. Exit");
			switch(sc.nextInt()){
				case 1: emp.input(br);
				break;
				case 2: emp.display();
				break;
				case 3: return;
			}
		}
	}
}