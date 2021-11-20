/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_paint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adelille <adelille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 15:59:48 by adelille          #+#    #+#             */
/*   Updated: 2021/11/20 15:02:47 by adelille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define	CORPT	"Error: Operation file corrupted\n"
#define ARG		"Error: argument\n"
#define MALLOC	"Error: Malloc failed\n"

typedef struct s_zone
{
	int		w;
	int		h;
	char	background;
}			t_zone;

typedef struct s_shape
{
	char			type;
	float			x;
	float			y;
	float			radius;
	char			color;
}					t_shape;

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_ps(char *str)
{
	return (write(1, str, ft_strlen(str)));
}

int	ft_clear(FILE *file, char *draw, char *err, int ret)
{
	fclose(file);
	if (draw)
		free(draw);
	if (err)
		ft_ps(err);
	return (ret);
}

int	ft_check_zone(t_zone *zone)
{
	return (zone->w > 0 && zone->w <= 300
		&& zone->h > 0 && zone->h <= 300);
}

int	ft_check_shape(t_shape *s)
{
	return (s->radius > 0.00000000
		&& (s->type == 'c' || s->type == 'C'));
}

int	ft_get_zone(FILE *file, t_zone *zone)
{
	if (fscanf(file, "%d %d %c\n",
					&zone->w, &zone->h, &zone->background) != 3)
		return (0);
	if (!ft_check_zone(zone))
		return (0);
	return (1);
}

char	*ft_init_draw(t_zone *zone)
{
	char	*draw;
	int		i;

	if (!(draw = (char *)malloc(sizeof(char) * (zone->w * zone->h))))
		return (NULL);
	i = 0;
	while (i < zone->w * zone->h)
	{
		draw[i] = zone->background;
		i++;
	}
	return (draw);
}

int		ft_in_circle(float x, float y, t_shape *s)
{
	float	distance;

	distance = sqrtf(powf(x - s->x, 2.) + powf(y - s->y, 2.));
	if (distance <= s->radius)
	{
		if ((s->radius - distance) < 1.00000000)
			return (2);
		return (1);
	}
	return (0);
}

void	ft_draw_shape(char *draw, t_shape *s, t_zone *zone)
{
	int	x;
	int	y;
	int	ret;

	y = 0;
	while (y < zone->h)
	{
		x = 0;
		while (x < zone->w)
		{
			ret = ft_in_circle((float)x, (float)y, s);
			if ((s->type == 'c' && ret == 2)
					|| (s->type == 'C' && ret))
				draw[(y * zone->w) + x] = s->color;
			x++;
		}
		y++;
	}
}

int	ft_get_shapes(FILE *file, char *draw, t_zone *zone)
{
	t_shape	s;
	int		scanf_ret;

	while ((scanf_ret = fscanf(file, "%c %f %f %f %c\n",
					&s.type, &s.x, &s.y, &s.radius, &s.color)) == 5)
	{
		if (!ft_check_shape(&s))
			return (0);
		ft_draw_shape(draw, &s, zone);
	}
	if (scanf_ret == -1)
		return (1);
	return (0);
}

void	ft_draw(char *draw, t_zone *zone)
{
	int	i;

	i = 0;
	while (i < zone->h)
	{
		write(1, draw + (i * zone->w), zone->w);
		write(1, "\n", 1);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_zone	zone;
	char	*draw;
	FILE	*file;

	if (ac != 2)
		return (ft_ps(ARG) * 0 + 1);
	if (!(file = fopen(av[1], "r")))
		return (ft_ps(CORPT) * 0 + 1);
	if (!ft_get_zone(file, &zone))
		return (ft_clear(file, NULL, CORPT, 1));
	if (!(draw = ft_init_draw(&zone)))
		return (ft_clear(file, NULL, MALLOC, 1));
	if (!ft_get_shapes(file, draw, &zone))
		return (ft_clear(file, draw, CORPT, 1));
	ft_draw(draw, &zone);
	return (ft_clear(file, draw, NULL, 0));
}
