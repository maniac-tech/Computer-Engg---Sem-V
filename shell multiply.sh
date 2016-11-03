#!/bin/sh
##Script to test for loop
if [$# -eq0]
	then
	echo "Error - NUmber is missing from the command line argument"
	echo "Syntax:$0 number"
	echo "USe to print multiplication table for the given number"
	exit 1
	fi
	n=$1
	for i in 1 2 3 4 5 6 7 8 9 10
	do
	echo "$n * $i =`expr $i \* $n`"
	done
