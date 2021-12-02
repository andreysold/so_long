/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galetha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:06:46 by galetha           #+#    #+#             */
/*   Updated: 2021/10/18 17:07:48 by galetha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"
#include "./../mlx/mlx.h"
#include "../so_long.h"

void	fill_mat_bonus(char *line, char *arr, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		arr[i] = line[i];
		i++;
	}
	arr[len] = '\0';
}

void	print_mass_bonus(t_job *lg, char **arr)
{
	int	i;
	int	j;

	i = 0;
	while (i < lg->height)
	{
		j = 0;
		while (j < lg->width)
		{
			printf("%c", arr[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void	init_job_bonus(t_job **lg)
{
	(*lg)->height = 0;
	(*lg)->width = 0;
	(*lg)->x_play = 0;
	(*lg)->y_play = 0;
	(*lg)->w_width = 0;
	(*lg)->w_height = 0;
	(*lg)->iw = 0;
	(*lg)->ih = 0;
	(*lg)->x_last = 0;
	(*lg)->y_last = 0;
	(*lg)->ptr = 0;
	(*lg)->mlx = 0;
	(*lg)->end_game = 0;
	(*lg)->mlx_win = 0;
	(*lg)->count_coin = 0;
	(*lg)->ex_coin = 0;
	(*lg)->i = 0;
	(*lg)->j = 0;
	(*lg)->h = 0;
	(*lg)->w = 0;
	(*lg)->x = 0;
}

void	ft_no_malloc_bonus(char **arr, t_job *lg)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < lg->height)
	{
		free(arr[i]);
		i++;
	}
	free(arr[i]);
}
