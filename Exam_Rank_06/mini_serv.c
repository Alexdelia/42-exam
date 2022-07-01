//	code from https://github.com/luta-wolf/42-examrank/blob/master/ExamRank_06/mini_serv.c

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
//#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

const int	BUF_SIZE = 42 * 4096;

typedef struct s_client
{
	int	id;
	char	msg[110000];
}			t_client;

t_client	g_c[1024];

int		max, next_id = 0;
fd_set	sock, ready_read, ready_write;
char	buf_read[BUF_SIZE], buf_write[BUF_SIZE];

ssize_t	ft_psfd(const int fd, const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (write(fd, str, i));
}

void	error(void)
{
	ft_psfd(2, "Fatal error\n");
	exit(1);
}

void	send_all(const int src)
{
	for (int i = 0; i <= max; i++)
		if (FD_ISSET(i, &ready_write) && i != src)
			send(i, buf_write, strlen(buf_write), 0);
}

int	main(int ac, char **av)
{
	if (ac != 2)
		return (!!ft_psfd(2, "Wrong number of arguments\n"));

	bzero(&g_c, sizeof(g_c));
	FD_ZERO(&sock);

	int	s_fd = socket(AF_INET, SOCK_STREAM, 0);
	if (s_fd < 0)
		error();

	max = s_fd;
	FD_SET(s_fd, &sock);

	struct sockaddr_in	addr;
	socklen_t			addr_len = sizeof(addr);

	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = htonl(2130706433);	// 127.0.0.1
	addr.sin_port = htons(atoi(av[1]));

	if ((bind(s_fd, (const struct sockaddr *)&addr, sizeof(addr))) < 0)
		error();
	if (listen(s_fd, 128) < 0)
		error();

	while (1)
	{
		ready_read = ready_write = sock;
		if (select(max + 1, &ready_read, &ready_write, NULL, NULL) < 0)
			continue ;

		for (int s = 0; s <= max; s++)
		{
			if (FD_ISSET(s, &ready_read) && s == s_fd)
			{
				int	c_fd = accept(s_fd, (struct sockaddr *)&addr, &addr_len);
				if (c_fd < 0)
					continue ;
				max = (c_fd > max ? c_fd : max);
				g_c[c_fd].id = next_id++;
				FD_SET(c_fd, &sock);
				sprintf(buf_write, "server: client %d just arrived\n", g_c[c_fd].id);
				send_all(c_fd);
				break ;
			}

			if (FD_ISSET(s, &ready_read) && s != s_fd)
			{
				int	res = recv(s, buf_read, BUF_SIZE, 0);
				if (res <= 0)
				{
					sprintf(buf_write, "server: client %d just left\n", g_c[s].id);
					send_all(s);
					FD_CLR(s, &sock);
					close(s);
					break ;
				}
				else
				{
					for (int i = 0, x = strlen(g_c[s].msg); i < res; i++, x++)
					{
						g_c[s].msg[x] = buf_read[i];
						if (g_c[s].msg[x] == '\n')
						{
							g_c[s].msg[x] = '\0';
							sprintf(buf_write, "client %d: %s\n", g_c[s].id, g_c[s].msg);
							send_all(s);
							bzero(&g_c[s].msg, strlen(g_c[s].msg));
							x = -1;
						}
					}
					break ;
				}
			}
		}
	}

	return (0);
}
