/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlenna <jlenna@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/12 17:17:16 by jlenna            #+#    #+#             */
/*   Updated: 2022/06/28 17:57:25 by jlenna           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h> //!!!!!!!

# include <unistd.h>
# include <stdlib.h>
# include <mlx.h>
# include "libft/libft.h"
# include <fcntl.h>
# include "gnl/get_next_line.h"

# define INT_MAX 2147483647
# define INT_MIN -2147483648

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 256
# endif

typedef struct s_map
{
	int		height;
	int		width;
	int		player_x;
	int		player_y;
	int		score;
	char	**map;
	int		steps;

	void	*exit;
	void	*wall;
	void	*player;
	void	*floor;
	void	*collect;

	int		flag;
	int		flag2;
	int		flag3;

	void	*mlx;
	void	*win;
}	t_map;

int		main(int argc, char **argv);
t_map	*game_init(char *file);
void	ft_error(char *str, t_map *game);
int		name_checker(char *str);
int		map_checker(char *file, t_map *game);
int		map_checker_2(t_map *game, int i);
int		check_chr(t_map *game);
int		map_checker_3(t_map *game, int x, int y);
int		ft_count(char *file);
int		check_rct(t_map *game, int i);
int		map_checker_4(t_map *game, int x, int y);
void	draw(t_map *game);
void	floor_img(t_map *game);
void	collect_img(t_map *game);
void	player_img(t_map *game);
void	exit_img(t_map *game);
void	wall_img(t_map *game);
int		exit_hook(t_map *game);
void	destroy_img(t_map *game);
void	draw_window_2(t_map *game, int i, int j);
int		draw_window(t_map *game);
void	consts(t_map *game);
int		key_hook(int keycode, t_map *game);
void	mv_up(t_map *game);
void	mv_down(t_map *game);
void	mv_left(t_map *game);
void	mv_right(t_map *game);
void	do_game(t_map *game);

#endif