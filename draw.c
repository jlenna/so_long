/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlenna <jlenna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/25 18:09:26 by jlenna            #+#    #+#             */
/*   Updated: 2022/06/27 15:37:02 by jlenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	wall_img(t_map *game)
{
	int	pos[2];

	game->wall = mlx_xpm_file_to_image(game->mlx, \
	"sprites/wall.xpm", &pos[0], &pos[1]);
}

void	exit_img(t_map *game)
{
	int	pos[2];

	game->exit = mlx_xpm_file_to_image(game->mlx, \
	"sprites/exit1.xpm", &pos[0], &pos[1]);
}

void	player_img(t_map *game)
{
	int	pos[2];

	game->player = mlx_xpm_file_to_image(game->mlx, \
	"sprites/player.xpm", &pos[0], &pos[1]);
}

void	collect_img(t_map *game)
{
	int	pos[2];

	game->collect = mlx_xpm_file_to_image(game->mlx, \
	"sprites/collect.xpm", &pos[0], &pos[1]);
}

void	draw(t_map *game)
{
	wall_img(game);
	exit_img(game);
	collect_img(game);
	player_img(game);
	floor_img(game);
}
