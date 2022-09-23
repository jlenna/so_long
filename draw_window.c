/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlenna <jlenna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 19:04:20 by jlenna            #+#    #+#             */
/*   Updated: 2022/06/28 13:57:09 by jlenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	draw_window(t_map *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->win, \
				game->wall, j * 64, i * 64);
			else if (game->map[i][j] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, \
				game->exit, j * 64, i * 64);
			else if (game->map[i][j] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, \
				game->collect, j * 64, i * 64);
			else
				draw_window_2(game, i, j);
		}
	}
	return (0);
}

void	floor_img(t_map *game)
{
	int	pos[2];

	game->floor = mlx_xpm_file_to_image(game->mlx, \
	"sprites/floor.xpm", &pos[0], &pos[1]);
}

void	draw_window_2(t_map *game, int i, int j)
{
	if (game->map[i][j] == 'P')
		mlx_put_image_to_window(game->mlx, game->win, \
		game->player, j * 64, i * 64);
	else if (game->map[i][j] == '0')
		mlx_put_image_to_window(game->mlx, game->win, \
		game->floor, j * 64, i * 64);
}
