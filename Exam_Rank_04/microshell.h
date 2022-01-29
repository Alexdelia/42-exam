/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:12:04 by adelille          #+#    #+#             */
/*   Updated: 2022/01/29 15:25:54 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MICROSHELL_H
# define MICROSHELL_H

# include <unistd.h>
//# include <stdlib.h>
# include <string.h>
# include <sys/wait.h>

/*# define TRUE		1
# define FALSE		0*/

# define STDIN		0
# define STDOUT		1
# define STDERR		2

// for Glaglan's test.sh
#ifdef TEST_SH
# define TEST		1
#else
# define TEST		0
#endif

int		exec(char **av, int i, int tmp_fd, char **env);
void	exec_cd(char **av, int i);

int		ft_pser(const char *str);

//int		error(const char *text, const int ret);
//void	fatal(void);

#endif
