/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlenna <jlenna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 15:17:51 by jlenna            #+#    #+#             */
/*   Updated: 2022/06/28 14:01:44 by jlenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_img(t_map *game)
{
	mlx_destroy_image(game->mlx, game->wall);
	mlx_destroy_image(game->mlx, game->player);
	mlx_destroy_image(game->mlx, game->collect);
	mlx_destroy_image(game->mlx, game->floor);
	mlx_destroy_image(game->mlx, game->exit);
}

int	exit_hook(t_map *game)
{
	int	i;

	i = -1;
	destroy_img(game);
	mlx_destroy_window(game->mlx, game->win);
	while (game->map[++i])
		free(game->map[i]);
	free(game->map);
	free(game);
	exit(0);
	return (0);
}
