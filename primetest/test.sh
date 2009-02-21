#!/bin/bash

if [ ! -d reports ]
then
	echo $0: mkdir reports/ and try again > /dev/stderr
	exit 1;
fi

rm -f reports/* || exit 1

for p in bin/*
do
	echo Testing $p

	#Cut off the "bin/"
	f=${p:4}

	#My copy of time isn't handling its arguments right..
	#time $p --output reports/time-$f > reports/output-$f.txt
	time $p > reports/output-$f.txt

done
