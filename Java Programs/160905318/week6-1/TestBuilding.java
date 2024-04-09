import com.course.buildings.*;
import java.util.Scanner;
class TestBuilding{
	public static void main(String args[]){
		Building building=new Building();
		House house=new House();
		School school=new School();
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter 1 for house and 2 for school");
		int ch=sc.nextInt();
		System.out.println("Enter square footage:");
		double square=sc.nextDouble();
		System.out.println("Enter number of stories:");
		int stories=sc.nextInt();
		if(ch==1){
			System.out.println("Enter number of bedrooms and bathrooms:");
			house.setSquareFoot(square);
			house.setStories(stories);
			house.setBed(sc.nextInt());
			house.setBath(sc.nextInt());
			building=(Building) house;
		}
		else if(ch==2){
			System.out.println("Enter number of classrooms and grade");
			school.setSquareFoot(square);
			school.setStories(stories);
			school.setRooms(sc.nextInt());
			school.setGrade(sc.next());
			building=(Building) school;
		}
		System.out.println("Square Footage:"+building.getSquareFoot()+"\nNumber of Stories:"+building.getStories());
		if(ch==1)
			System.out.println("Number of Bedrooms:"+house.getBed()+"\nNumber of Bathrooms:"+house.getBath());
		else if(ch==2)
			System.out.println("Number of classrooms:"+school.getClass()+"\nGrade:"+school.getGrade());

	}
}