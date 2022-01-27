/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:12:04 by adelille          #+#    #+#             */
/*   Updated: 2022/01/27 15:46:35 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MICROSHELL_H
# define MICROSHELL_H

# include <unistd.h>
//# include <stdlib.h>
# include <string.h>

/*# define TRUE		1
# define FALSE		0*/

# define STDIN		0
# define STDOUT		1
# define STDERR		2

int		exec(char **av, int i, int tmp_fd, char **env);
void	exec_cd(char **av);

int		ft_pser(const char *str);

//int		error(const char *text, const int ret);
//void	fatal(void);

#endif
