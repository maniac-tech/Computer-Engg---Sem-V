#!/bin/bash
#read user input
echo Enter Number
read n
sum=0
sd=0 

while [ $n -gt 0 ]
do
	sd=`expr $n % 10`
	sum=`expr $sum + $sd`
	n=`expr $n / 10`
done
echo "Sum of digits for number is $sum"
