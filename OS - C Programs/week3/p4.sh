#!bin/sh
echo "Enter the three coefficients "
read a
read b
read c
d=$(echo "$b*$b-4*$a*$c"|bc -l)
case 1 in
	$(echo "$d>0"|bc -l))
	r1=$(echo "(-1 *$b - sqrt($d))/(2 * $a) "|bc -l)
	r2=$(echo "(-1 *$b + sqrt($d))/(2 * $a) "|bc -l)
	echo $r1
	echo $r2
	;;
	$(echo "$d==0"|bc -l))
	r1=$(echo "(-1 *$b )/(2 * $a) "|bc -l)
	echo $r1
	;;
	$(echo "$d<0"|bc -l))
	echo "Imaginary"
	;;
esac