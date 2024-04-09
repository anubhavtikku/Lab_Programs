#!bin/sh
echo "Enter numbers "
read n
declare a[100]
s=0
for((i=0;i<$n;i++))
do
read a[i]
s=$(echo "${a[i]} + $s"|bc -l)
done
echo "The sum is $s"