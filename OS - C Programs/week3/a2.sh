#!/bin/sh
echo "Enter number "
read x
n=1
while [ $x -gt 0 ]
do
echo "$n"
n=`expr $n + 2`
x=`expr $x - 1`
done
