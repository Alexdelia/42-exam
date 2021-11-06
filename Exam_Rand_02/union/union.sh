#!/bin/bash

clang -Wall -Wextra -Werror union.c -o union
./union "Hello, I like to eat potato" "and I need a hug" | cat -e
./union | cat -e
./union "rien" | cat -e
./union "rien" "cette phrase ne cache rien" | cat -e

echo "--- Expected: ---"
echo "Helo, Iiktapndhug$"
echo "$"
echo "$"
echo "rienct phas$"
