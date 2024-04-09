import java.util.*;
import java.io.*;
class NerdTree{
	public static void main(String[] args){
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter path to directory");
		String path=sc.nextLine();
		NerdTree ob=new NerdTree();
		try{
			File f=new File(path);
			System.out.println("The list of files are:-");
			ob.display(f,0);
		}catch(Exception ex){
			System.out.println(ex);
		}
	}
	void display(File f,int level)throws Exception{
		for(int i=0;i<level;i++)
			System.out.print("    ");
		if(f.isDirectory()){
			System.out.println(f.getName()+"/");
			File files[]=f.listFiles();
			for(int i=0;files!=null && i<files.length;i++){
				display(files[i],level+1);
			}
		}
		else
			System.out.println(f.getName());
	}
}