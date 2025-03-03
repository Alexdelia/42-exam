#!/usr/bin/env bash

clang -Wall -Wextra -Werror inter.c -o inter

./inter "Bonjour" "The brown fox is sitting" | cat -e
./inter "padinton" "paqefwtdjetyiytjneytjoeyjnejeyj" | cat -e
./inter "rien" "cette phrase ne cache rien" | cat -e
./inter | cat -e
./inter "ooooooooooo" "non" | cat -e

echo "--- Expected: ---"
echo "onr$"
echo "padinto$"
echo "rien$"
echo "$"
echo "o$"
