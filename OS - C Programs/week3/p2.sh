#!bin/sh
echo "Enter the number of odd numbers you want printed "
read n
k=1
for((i=0;i<$n;i++))
do
echo "$k "
k=`expr $k + 2`
done