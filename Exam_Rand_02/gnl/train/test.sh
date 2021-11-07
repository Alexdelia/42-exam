#!/bin/bash

if [[ $# == 1 ]]
then
	clang -Wall -Werror -Wextra -D BUFFER_SIZE="$1" gnl.c main.c -o gnl
else
	clang -Wall -Werror -Wextra gnl.c main.c -o gnl
fi

./gnl < gnl.c > yours_.res
cat -e yours_.res > yours.res
cat -e < gnl.c > original.res
diff -y --suppress-common-line original.res yours.res

rm -rf yours_.res gnl
