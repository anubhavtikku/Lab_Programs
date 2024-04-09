import java.util.*;
import java.io.*;
class Search{
	public static void main(String args[]){
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter file path");
		String path=sc.nextLine();
		try{
			Scanner f=new Scanner(new File(path));
			System.out.println("Enter searching word");
			String word=sc.next().toLowerCase();
			int linecount=0;
			while(f.hasNextLine()){
				String s=f.nextLine();
				linecount++;
				if(s.toLowerCase().indexOf(word)>=0)
					System.out.println(linecount+": "+s);
			}
		}catch(Exception e){
			System.out.println("File not found");
		}
	}
}