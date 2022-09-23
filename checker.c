/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlenna <jlenna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 17:30:23 by jlenna            #+#    #+#             */
/*   Updated: 2022/06/28 13:57:53 by jlenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	name_checker(char *str)
{
	int	i;

	i = ft_strlen(str);
	i--;
	if (str[i] != 'r')
		return (0);
	i--;
	if (str[i] != 'e')
		return (0);
	i--;
	if (str[i] != 'b')
		return (0);
	i--;
	if (str[i] != '.')
		return (0);
	return (1);
}

int	map_checker(char *file, t_map *game)
{
	int		i;
	int		j;
	int		fd;
	char	**buff;

	i = ft_count(file);
	j = 0;
	fd = open(file, O_RDONLY);
	if (!fd)
	{
		ft_error("Cannot open the map", 0);
		return (1);
	}
	buff = (char **)malloc((i + 1) * sizeof(char *));
	while (j <= i)
	{
		buff[j] = get_next_line(fd);
		j++;
	}
	game->map = buff;
	if (!(check_chr(game) == 0 && check_rct(game, i) == 0 && \
	map_checker_2(game, i) == 0))
		return (1);
	close(fd);
	return (0);
}

int	check_rct(t_map *game, int i)
{
	int	x;
	int	y;
	int	j;

	x = 0;
	y = 0;
	j = 0;
	while (game->map[y + 1])
	{
		x = ft_strlen(game->map[y]) - 1;
		j = ft_strlen(game->map[y + 1]) - 1;
		if ((x == j) && (y < i - 2))
			y++;
		else if ((x == (j + 1)) && (y == (i - 2)))
			y++;
		else
		{
			ft_error("Not rectangle", 0);
			return (1);
		}
	}
	game->height = i;
	game->width = x;
	return (0);
}

int	check_chr(t_map *game)
{
	int	x;
	int	y;
	int	j;

	x = 0;
	y = 0;
	j = 0;
	while (game->map[y])
	{
		while (game->map[y][x])
		{
			if ((game->map[y][x] != '1') && (game->map[y][x] != '0') && \
			(game->map[y][x] != 'C') && (game->map[y][x] != 'E') && \
			(game->map[y][x] != 'P') && (game->map[y][x] != '\n'))
			{
				ft_error("Forbidden symbols", 0);
				return (1);
			}
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

int	map_checker_2(t_map *game, int i)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (game->map[y])
	{
		if (y == 0 || y == i - 1)
		{
			while (game->map[y][x])
			{
				if ((game->map[y][x] != '1') && (game->map[y][x] != '\n'))
				{
					ft_error("No wall", 0);
					return (1);
				}
				x++;
			}
			x = 0;
		}
		if (map_checker_3(game, x, y) == 0)
			y++;
		else
			return (1);
	}
}
