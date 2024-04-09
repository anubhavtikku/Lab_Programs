#!bin/sh
echo "Enter string "
read x
l=`expr length $x`
k=1
for((i=1;i<=l;i++))
do
a=$(echo `expr substr $x $k 1`)
b=$(echo `expr substr $x $l 1`)
if [ "$a" != "$b" ]
then
	echo "Not Palindrome"
	exit
fi
l=`expr $l - 1`
k=`expr $k + 1`
done
echo "Palindrome"