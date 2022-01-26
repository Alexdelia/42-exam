/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   microshell.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 15:12:04 by adelille          #+#    #+#             */
/*   Updated: 2022/01/26 22:28:04 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MICROSHELL_H
# define MICROSHELL_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>

# define TRUE		1
# define FALSE		0

# define STDIN		0
# define STDOUT		1
# define STDERR		2

# define T_END		0
# define T_PIPE		1
# define T_BREAK	2

typedef struct s_cmd
{
	char			**av;
	int				len;
	int				type;
	int				pipes[2];
	struct s_cmd	*next;
	struct s_cmd	*prev;
}					t_cmd;

int		exec_list(t_cmd **list, char **env);

int		cmd_add_av(t_cmd *cmd, char *av);

int		error(const char *text, const int ret);
void	fatal(void);

#endif
