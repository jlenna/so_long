/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlenna <jlenna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/28 14:24:50 by jlenna            #+#    #+#             */
/*   Updated: 2022/06/28 17:56:35 by jlenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_map *game)
{
	draw_window(game);
	if (keycode == 13)
		mv_up(game);
	if (keycode == 1)
		mv_down(game);
	if (keycode == 0)
		mv_left(game);
	if (keycode == 2)
		mv_right(game);
	if (keycode == 53)
		exit_hook(game);
	return (0);
}

void	mv_up(t_map *game)
{
	if (game->map[game->player_y - 1][game->player_x] == '0')
	{
		game->map[game->player_y - 1][game->player_x] = 'P';
		game->map[game->player_y][game->player_x] = '0';
		game->player_y--;
		game->steps++;
		ft_printf("Steps made: %d\n", game->steps);
	}
	else if (game->map[game->player_y - 1][game->player_x] == 'C')
	{
		game->map[game->player_y - 1][game->player_x] = 'P';
		game->map[game->player_y][game->player_x] = '0';
		game->player_y--;
		game->steps++;
		ft_printf("Steps made: %d\n", game->steps);
		game->score--;
	}
	else if (game->map[game->player_y - 1][game->player_x] == 'E' \
	&& game->score == 0)
	{
		ft_printf("You win!\n");
		exit_hook(game);
	}
}

void	mv_down(t_map *game)
{
	if (game->map[game->player_y + 1][game->player_x] == '0')
	{
		game->map[game->player_y + 1][game->player_x] = 'P';
		game->map[game->player_y][game->player_x] = '0';
		game->player_y++;
		game->steps++;
		ft_printf("Steps made: %d\n", game->steps);
	}
	else if (game->map[game->player_y + 1][game->player_x] == 'C')
	{
		game->map[game->player_y + 1][game->player_x] = 'P';
		game->map[game->player_y][game->player_x] = '0';
		game->player_y++;
		game->steps++;
		ft_printf("Steps made: %d\n", game->steps);
		game->score--;
	}
	else if (game->map[game->player_y + 1][game->player_x] == 'E' \
	&& game->score == 0)
	{
		ft_printf("You win!\n");
		exit_hook(game);
	}
}

void	mv_left(t_map *game)
{
	if (game->map[game->player_y][game->player_x - 1] == '0')
	{
		game->map[game->player_y][game->player_x - 1] = 'P';
		game->map[game->player_y][game->player_x] = '0';
		game->player_x--;
		game->steps++;
		ft_printf("Steps made: %d\n", game->steps);
	}
	else if (game->map[game->player_y][game->player_x - 1] == 'C')
	{
		game->map[game->player_y][game->player_x - 1] = 'P';
		game->map[game->player_y][game->player_x] = '0';
		game->player_x--;
		game->steps++;
		ft_printf("Steps made: %d\n", game->steps);
		game->score--;
	}
	else if (game->map[game->player_y][game->player_x - 1] == 'E' \
	&& game->score == 0)
	{
		ft_printf("You win!\n");
		exit_hook(game);
	}
}

void	mv_right(t_map *game)
{
	if (game->map[game->player_y][game->player_x + 1] == '0')
	{
		game->map[game->player_y][game->player_x + 1] = 'P';
		game->map[game->player_y][game->player_x] = '0';
		game->player_x++;
		game->steps++;
		ft_printf("Steps made: %d\n", game->steps);
	}
	else if (game->map[game->player_y][game->player_x + 1] == 'C')
	{
		game->map[game->player_y][game->player_x + 1] = 'P';
		game->map[game->player_y][game->player_x] = '0';
		game->player_x++;
		game->steps++;
		ft_printf("Steps made: %d\n", game->steps);
		game->score--;
	}
	else if (game->map[game->player_y][game->player_x + 1] == 'E' \
	&& game->score == 0)
	{
		ft_printf("You win!\n");
		exit_hook(game);
	}
}
