#!/bin/bash

cat -e < gnl.c > original.res

i=1

while [[ $i -le 2000 ]]
do
	echo "Buffer of $i"
	clang -Wall -Werror -Wextra -D BUFFER_SIZE="$i" gnl.c main.c -o gnl
	./gnl < gnl.c > yours_.res
	cat -e yours_.res > yours.res
	diff -y --suppress-common-line original.res yours.res
	i=$(( i + 1 ))
done

rm -rf yours_.res gnl
