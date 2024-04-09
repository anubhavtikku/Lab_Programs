#!/bin/sh
echo "Enter number "
read x
n=1
while [ $x -gt 1 ]
do
n=`expr $n \* $x`
x=`expr $x - 1`
done
echo "The factorial is $n"
