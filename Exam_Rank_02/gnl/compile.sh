#!/usr/bin/env bash

if [[ $# == 1 ]]
then
	clang -Wall -Werror -Wextra -D BUFFER_SIZE="$1" -g get_next_line.c main.c -o gnl
else
	clang -Wall -Werror -Wextra -g get_next_line.c main.c -o gnl
fi
