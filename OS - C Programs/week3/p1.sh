#!bin/sh
echo "Enter number "
read x
if [ `expr $x % 2` -eq 0 ]
then
	echo "Even "
else
	echo "Odd"
fi
