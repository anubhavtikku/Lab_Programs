import java.util.*;
import java.text.*;
class test{
	public static void main(String args[]){
		GregorianCalendar gc=new GregorianCalendar();
		System.out.format("%02d:%02d:%04d",gc.get(Calendar.DATE),gc.get(Calendar.MONTH),gc.get(Calendar.YEAR));
	}
}