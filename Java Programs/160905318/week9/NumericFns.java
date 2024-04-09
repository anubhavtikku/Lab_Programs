import java.util.*;
class NumericFns<T extends Number>{
	T num;
	NumericFns(T num){
		this.num=num;
	}
	double reciprocal(){
		return 1.0/num.doubleValue();
	}
	double fraction(){
		return num.doubleValue()-num.intValue();
	}
	boolean absEqual(NumericFns<?> num1){
		return Math.abs(num.doubleValue())==Math.abs(num1.num.doubleValue());
	}
}
class BoundsDemo{
	public static void main(String args[]){
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter Number 1");
		Double n=sc.nextDouble();
		NumericFns<Double> num=new NumericFns<Double>(n);
		System.out.println("Reciprocal:-"+num.reciprocal()+"\nFractional part:-"+num.fraction());
		System.out.println("Enter Number 2");
		n=sc.nextDouble();
		NumericFns<Double> num2=new NumericFns<Double>(n);
		System.out.println("Absolute value of both numbers are "+(num.absEqual(num2)?"same":"different"));
	}
}