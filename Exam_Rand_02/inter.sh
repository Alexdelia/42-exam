# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    inter.sh                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user42 <adelille@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/21 22:58:11 by user42            #+#    #+#              #
#    Updated: 2021/02/21 23:18:35 by user42           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

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
