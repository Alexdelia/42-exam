#!/bin/bash

clang++ -Wall -Werror -Wextra main.cpp Warlock.cpp
diff -y --suppress-common-line <(./a.out | cat -e) diff.txt
if [[ $? -eq 0 ]]; then
	echo "no diff";
fi
rm a.out
