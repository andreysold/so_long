/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphis_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galetha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:47:18 by galetha           #+#    #+#             */
/*   Updated: 2021/10/18 16:47:27 by galetha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"
#include "../mlx/mlx.h"
#include "../so_long.h"

void	create_backgr(t_job *lg)
{
	t_it	it;
	t_map	map_in;
	char	**arr;

	path_sprites(&map_in, lg);
	it.i = 0;
	it.h = 0;
	arr = lg->ptr;
	while (it.i < lg->height)
	{
		it.j = 0;
		it.w = 0;
		while (it.j < lg->width)
		{
			condit_sprites(map_in, lg, it, arr);
			it.w += 65;
			it.j++;
		}
		it.i++;
		it.h += 65;
	}
}

void	move_play(int keycode, char **arr, t_job *lg)
{
	lg->tmp_x = lg->x;
	if (keycode == TOP && arr[lg->x_play - 1][lg->y_play] != '1')
	{
		lg->x++;
		lg->x_play--;
	}
	else if (keycode == LEFT && arr[lg->x_play][lg->y_play - 1] != '1')
	{
		lg->x++;
		lg->y_play--;
	}
	else if (keycode == RIGHT && arr[lg->x_play][lg->y_play + 1] != '1')
	{
		lg->x++;
		lg->y_play++;
	}
	else if (keycode == DOWN && arr[lg->x_play + 1][lg->y_play] != '1')
	{
		lg->x++;
		lg->x_play++;
	}
	if (lg->tmp_x != lg->x && arr[lg->x_play][lg->y_play] != 'E')
		printf("step : %d\n", lg->x);
}

int	kh_exit(t_job *lg)
{
	(void)lg;
	exit (0);
}

int	key_hook(int keycode, t_job *lg)
{
	char	**arr;

	arr = lg->ptr;
	if (keycode == ESC)
		exit(0);
	if (lg->end_game == 0)
		move_play(keycode, arr, lg);
	new_value(lg);
	create_backgr(lg);
	return (1);
}

void	win_arr(t_job *lg)
{
	lg->mlx = mlx_init();
	lg->mlx_win = mlx_new_window(lg->mlx, lg->w_width, lg->w_height, "so_long");
	create_backgr(lg);
	mlx_hook(lg->mlx_win, 2, 0, key_hook, lg);
	mlx_hook(lg->mlx_win, 17, 0, kh_exit, lg);
	mlx_loop(lg->mlx);
}
