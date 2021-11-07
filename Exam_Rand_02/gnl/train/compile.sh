#!/bin/bash

if [[ $# == 1 ]]
then
	clang -Wall -Werror -Wextra -D BUFFER_SIZE="$1" -g gnl.c main.c -o gnl
else
	clang -Wall -Werror -Wextra -g gnl.c main.c -o gnl
fi
