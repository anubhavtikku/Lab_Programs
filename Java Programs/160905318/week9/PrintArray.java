class PrintArray{
	static <T extends Object> void print(T[] arr){
		for(int i=0;i<arr.length;i++)
			System.out.println(arr[i].toString());
	}
}
class PrintArrDemo{
	public static void main(String args[]){
		Integer[] iarr={5,6,7,9,10};
		Double[] darr={2.0,6.7,7.7,8.0,9.7};
		System.out.println("Printing Integer Array:-");
		PrintArray.print(iarr);
		System.out.println("Printing Double Array:-");
		PrintArray.print(darr);
	}
}