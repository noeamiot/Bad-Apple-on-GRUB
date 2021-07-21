#!/bin/sh

for i in  *.txt; do
	echo $i
	cat $i
	sleep 0.04
	echo -e "\e[H"
done
