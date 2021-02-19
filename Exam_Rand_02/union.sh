# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    union.sh                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <adelille@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/19 06:47:56 by user42            #+#    #+#              #
#    Updated: 2021/02/19 06:52:00 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

clang -Wall -Wextra -Werror union.c -o union
./union "Hello, I like to eat potato" "and I need a hug" | cat -e
./union | cat -e
./union "rien" | cat -e
./union "rien" "cette phrase ne cache rien" | cat -e
# expected output:
echo 'rienct phas\n'
