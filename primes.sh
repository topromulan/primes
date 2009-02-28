#!/bin/bash

#A handy shell script to find factors / test for primes

#7 February 2009 by Dale Anderson
# dra@redevised.net

SYNTAX="Syntax: primes.sh [number]"


######################################
# Validate the input

if ( 
	[ ! -n "$1" ] ||		#user must provide one arg
	[ -n "$2" ] || 			#should only be one arg
	[ "$1" == "--help" ] 		#user may ask for help
	)
then
	echo $SYNTAX			#explain the syntax

	if [ -n "$2" ]
	then
		exit 1
	fi

	exit 0
fi

if echo $1 | grep -qv '^[0-9]*$'	 #Not a Number
then
	echo Error: Not a Number > /dev/stderr
	echo $SYNTAX
	exit 1
fi

######################################
# OK, proceed..

NUMBER=$1				#The number the user provided

TOP=`echo "sqrt($NUMBER)+1" |
	bc -l |
	sed 's/\..*//'`			#The square root of it plus one

FACTORS=0				#Factors we located

n=2

while [ $n -le $TOP ]
do
	REMAINDER=$((NUMBER % n))

	if [ $REMAINDER == 0 ] 
	then
		echo Bingo! $NUMBER is divisible by $n.

		FACTORS=$((FACTORS + 1))
	fi

	n=$((n+1))
done

echo $NUMBER has $FACTORS factor\(s\).

if [ $FACTORS -gt 1 ]
then
	echo Note: Factors are not guarunteed to be unique.
fi

if [ $FACTORS == 0 ]
then
	echo $NUMBER is prime!
fi

