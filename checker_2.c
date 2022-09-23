/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlenna <jlenna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 20:52:22 by jlenna            #+#    #+#             */
/*   Updated: 2022/06/28 14:49:38 by jlenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_checker_3(t_map *game, int x, int y)
{
	x = 0;
	game->flag = 0;
	game->flag2 = 0;
	game->flag3 = 0;
	if (game->map[y][x] != '1')
	{
		ft_error("No left wall", 0);
		return (1);
	}
	x = ft_strlen(game->map[y]) - 2;
	if (game->map[y][x] != '1')
	{
		ft_error("No right wall", 0);
		return (1);
	}
	y = 0;
	if (map_checker_4(game, x, y) == 0)
		return (0);
	else
		return (1);
}

int	map_checker_4(t_map *game, int x, int y)
{
	while (game->map[y])
	{
		if (ft_strchr(game->map[y], 'E') != NULL)
			game->flag++;
		if (ft_strchr(game->map[y], 'C') != NULL)
			game->flag2++;
		if (ft_strchr(game->map[y], 'P') != NULL)
			game->flag3++;
		y++;
	}
	if ((game->flag > 0) && (game->flag2 > 0) && (game->flag3 == 1))
		return (0);
	else
	{
		ft_error("Wrong number of exits, collects or players", 0);
		return (1);
	}
}

int	ft_count(char *file)
{
	int		fd;
	int		count;
	char	a;

	count = 1;
	fd = open(file, O_RDONLY);
	if (!fd)
	{
		ft_error("Cannot open the map", 0);
		return (1);
	}
	while (read(fd, &a, 1))
	{
		if (a == 0)
			break ;
		if (a == -1)
			return (-1);
		if (a == '\n')
			count++;
	}
	close(fd);
	return (count);
}
