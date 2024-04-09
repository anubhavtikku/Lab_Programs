#!bin/sh
echo "Enter coefficients of quadratic eq "
read a
read b
read c
d=`expr $b \* $b - 4 \* $a \* $c`
case 1 in
     `expr $d \> 0`)
    r1=$(echo "( -1* $b +sqrt($d) )/(2* $a)"|bc -l)
    r2=$(echo "( -1* $b -sqrt($d) )/(2* $a)"|bc -l)
    echo "Roots are $r1 and $r2"
    ;;
    `expr $d = 0`)
    r1=$(echo "( -1* $b) /(2* $a)"|bc -l)
    echo "Roots are $r1 and $r1"
    ;;
    `expr $d \< 0`)
    r1=$(echo "scale=5;( -1 * $b )/(2* $a)"|bc -l)
    r2=$(echo "scale=5;sqrt( -1 * $d) /(2* $a)"|bc -l)
    echo "Roots are imaginary $r1 + i$r2 and $r1 - i$r2 "
    ;;
esac
