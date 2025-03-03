#!/usr/bin/env bash

clang++ -Wall -Werror -Wextra *.cpp
diff -y --suppress-common-line <(./a.out | cat -e) diff.txt
if [[ $? -eq 0 ]]; then
	echo "no diff";
fi
rm a.out
