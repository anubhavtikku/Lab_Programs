#!bin/sh
echo "Enter number "
read x
k=1
for((i=1;i<=$x;i++))
do
k=$(echo "$i * $k"|bc)
done
echo "The factorial is $k"