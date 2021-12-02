/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_one_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galetha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:02:38 by galetha           #+#    #+#             */
/*   Updated: 2021/10/18 17:02:42 by galetha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"
#include "../mlx/mlx.h"
#include "../so_long.h"

void	path_sprt_bonus(t_map *map_in, t_job *lg)
{
	map_in->sp = "./path_sps/stone4.xpm";
	map_in->wp = "./path_sps/warrior.xpm";
	map_in->fp = "./path_sps/fonch4.xpm";
	map_in->dp = "./path_sps/door.xpm";
	map_in->cp = "./path_sps/coin.xpm";
	map_in->ep = "./path_sps/dead.xpm";
	map_in->pw = "./path_sps/kybok.xpm";
	map_in->lp = "./path_sps/liar.xpm";
	map_in->stn = mlx_xpm_file_to_image (lg->mlx, map_in->sp, &lg->iw, &lg->ih);
	map_in->liar = mlx_xpm_file_to_image(lg->mlx, map_in->lp, &lg->iw, &lg->ih);
	map_in->war = mlx_xpm_file_to_image (lg->mlx, map_in->wp, &lg->iw, &lg->ih);
	map_in->fon = mlx_xpm_file_to_image (lg->mlx, map_in->fp, &lg->iw, &lg->ih);
	map_in->dor = mlx_xpm_file_to_image (lg->mlx, map_in->dp, &lg->iw, &lg->ih);
	map_in->cn = mlx_xpm_file_to_image (lg->mlx, map_in->cp, &lg->iw, &lg->ih);
	map_in->end = mlx_xpm_file_to_image (lg->mlx, map_in->ep, &lg->iw, &lg->ih);
	map_in->win = mlx_xpm_file_to_image (lg->mlx, map_in->pw, &lg->iw, &lg->ih);
}

void	condit_sprt_bonus(t_map map_in, t_job *lg, t_it it, char **arr)
{
	if (arr[it.i][it.j] == '1')
		mlx_put_image_to_window(lg->mlx, lg->mlx_win, map_in.stn, it.w, it.h);
	else if (arr[it.i][it.j] == 'P')
	{
		mlx_put_image_to_window(lg->mlx, lg->mlx_win, map_in.war, it.w, it.h);
		lg->x_play = it.i;
		lg->y_play = it.j;
	}
	else if (arr[it.i][it.j] == 'E')
		mlx_put_image_to_window(lg->mlx, lg->mlx_win, map_in.dor, it.w, it.h);
	else if (arr[it.i][it.j] == 'L')
		mlx_put_image_to_window(lg->mlx, lg->mlx_win, map_in.liar, it.w, it.h);
	else if (arr[it.i][it.j] == 'C')
		mlx_put_image_to_window(lg->mlx, lg->mlx_win, map_in.cn, it.w, it.h);
	else if (arr[it.i][it.j] == '0')
		mlx_put_image_to_window(lg->mlx, lg->mlx_win, map_in.fon, it.w, it.h);
	else if (arr[it.i][it.j] == '2')
		mlx_put_image_to_window(lg->mlx, lg->mlx_win, map_in.win, it.w, it.h);
	else if (arr[it.i][it.j] == '3')
		mlx_put_image_to_window(lg->mlx, lg->mlx_win, map_in.end, it.w, it.h);
}

void	condit_new_v1_bonus(t_job *lg, char **arr)
{
	if (arr[lg->x_play][lg->y_play] == 'C')
	{
		arr[lg->x_play][lg->y_play] = 'P';
		lg->count_coin--;
	}
	else if (arr[lg->i][lg->j] == 'P')
	{
		arr[lg->i][lg->j] = '0';
		arr[lg->x_play][lg->y_play] = 'P';
	}
	else if (arr[lg->x_play][lg->y_play] == 'L')
	{
		end_fon_bonus(lg, 'D');
		lg->end_game = 1;
	}
	else if (arr[lg->x_play][lg->y_play] == 'E' && lg->count_coin == 0)
	{
		end_fon_bonus(lg, 'D');
		lg->end_game = 1;
	}
}

void	condit_new_v_bonus(t_job *lg, char **arr, int *fl)
{
	if (arr[lg->x_play][lg->y_play] == 'E' && (*fl) == 0)
	{
		arr[lg->x_play][lg->y_play] = 'P';
		if (lg->count_coin == 0)
			(*fl) = 1;
	}
	else if ((*fl) == 1)
	{
		end_fon_bonus(lg, 'W');
		lg->end_game = 1;
	}
}

void	new_value_bonus(t_job *lg)
{
	char	**arr;
	int		fl;

	fl = 0;
	lg->i = 0;
	arr = lg->ptr;
	while (lg->i < lg->height)
	{
		lg->j = 0;
		while (lg->j < lg->width)
		{
			if (arr[lg->x_play][lg->y_play] != '1'
				&& arr[lg->x_play][lg->y_play] != 'E')
				condit_new_v1_bonus(lg, arr);
			if (lg->count_coin == 0)
				condit_new_v_bonus(lg, arr, &fl);
			lg->j++;
		}
		lg->i++;
	}
}
