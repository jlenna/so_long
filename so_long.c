/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlenna <jlenna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 16:26:31 by jlenna            #+#    #+#             */
/*   Updated: 2022/06/28 17:56:14 by jlenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_map	*game;

	game = game_init(argv[1]);
	if (argc != 2)
		ft_error("Incorrect data input", 0);
	if (name_checker(argv[1]) != 1)
	{
		ft_error("Incorrect map extension", 0);
		return (0);
	}
	if (map_checker(argv[1], game) != 0)
	{
		ft_error("Map error", 0);
		return (0);
	}
	consts(game);
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->width * 64, \
	game->height * 64, "So_long");
	draw(game);
	do_game(game);
	exit_hook(game);
	return (0);
}

void	do_game(t_map *game)
{
	mlx_hook(game->win, 2, 0, key_hook, game);
	mlx_hook(game->win, 17, 0, exit_hook, game);
	mlx_loop_hook(game->mlx, draw_window, game);
	mlx_loop(game->mlx);
}

void	ft_error(char *str, t_map *game)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(1, str, i);
	write(1, "\n", 1);
	if (game)
		exit_hook(game);
}

t_map	*game_init(char *file)
{
	t_map	*game;

	game = (t_map **)malloc(sizeof(t_map));
	if (!game)
		return (NULL);
	game->height = 0;
	game->width = 0;
	game->player_x = 0;
	game->player_y = 0;
	game->score = 0;
	game->map = NULL;
	game->steps = 0;
	game->exit = NULL;
	game->wall = NULL;
	game->player = NULL;
	game->collect = NULL;
	game->floor = NULL;
	game->flag = 0;
	game->flag2 = 0;
	return (game);
}

void	consts(t_map *game)
{
	int	i;
	int	j;

	i = -1;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == 'P')
			{
				game->player_x = j;
				game->player_y = i;
			}
			else if (game->map[i][j] == 'C')
				game->score++;
		}
	}
}
