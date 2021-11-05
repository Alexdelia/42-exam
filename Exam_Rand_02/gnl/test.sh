#!/bin/bash

clang -Wall -Werror -Wextra get_next_line.c main.c -o gnl
./gnl < get_next_line.c > yours_.res
cat -e yours_.res > yours.res
cat -e < get_next_line.c > original.res
diff -y --suppress-common-line original.res yours.res
rm -rf yours_.res gnl
