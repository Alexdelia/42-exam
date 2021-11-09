#!/bin/bash

cat -e < get_next_line.c > original.res

i=-2

while [[ $i -le 200 ]]
do
	echo "Buffer of $i"
	clang -Wall -Werror -Wextra -D BUFFER_SIZE="$i" get_next_line.c main.c -o gnl
	if [[ $? -ne 0 ]]; then printf "\nError: Compilation failed.\n" && exit 1; fi
	./gnl < get_next_line.c > yours_.res
	cat -e yours_.res > yours.res
	diff -y --suppress-common-line original.res yours.res
	i=$(( i + 1 ))
done

echo "Buffer of 2000"
clang -Wall -Werror -Wextra -D BUFFER_SIZE="2000" get_next_line.c main.c -o gnl
if [[ $? -ne 0 ]]; then printf "\nError: Compilation failed.\n" && exit 1; fi
./gnl < get_next_line.c > yours_.res
cat -e yours_.res > yours.res
diff -y --suppress-common-line original.res yours.res

echo "Buffer of 10000000"
clang -Wall -Werror -Wextra -D BUFFER_SIZE="10000000" get_next_line.c main.c -o gnl
if [[ $? -ne 0 ]]; then printf "\nError: Compilation failed.\n" && exit 1; fi
./gnl < get_next_line.c > yours_.res
cat -e yours_.res > yours.res
diff -y --suppress-common-line original.res yours.res

rm -rf yours_.res gnl
