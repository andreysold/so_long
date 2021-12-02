/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_arr_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galetha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:04:52 by galetha           #+#    #+#             */
/*   Updated: 2021/10/18 17:06:38 by galetha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"
#include "./../mlx/mlx.h"
#include "../so_long.h"

void	count_coins_bonus(t_job **lg)
{
	char	**arr;

	arr = (*lg)->ptr;
	(*lg)->i = 0;
	while ((*lg)->i < (*lg)->height)
	{
		(*lg)->j = 0;
		while ((*lg)->j < (*lg)->width)
		{
			if (arr[(*lg)->i][(*lg)->j] == 'C')
			{
				(*lg)->count_coin++;
			}
			(*lg)->j++;
		}
		(*lg)->i++;
	}
}

void	eval_ft_ls_str_bonus(int i, char **arr, t_job *lg)
{
	int	j;

	j = 0;
	while (j < lg->width)
	{
		if (arr[i][j] != '1' && (i == 0 || i == lg->height - 1))
		{
			write(1, "ERROR\n", 6);
			exit(0);
		}
		if (arr[i][lg->width - 1] != '1')
		{
			write(1, "ERROR\n", 6);
			exit(0);
		}
		j++;
	}
}

void	eval_string_bonus(int i, char **arr, t_job *lg)
{
	int			j;
	static int	fl;

	j = 0;
	fl = 0;
	lg->count_coin = 0;
	while (j < lg->width)
	{
		if (arr[i][j] == 'E' || arr[i][j] == '1'
			||arr[i][j] == '0' || arr[i][j] == 'C'
			|| arr[i][j] == 'L' || arr[i][j] == '2')
			j++;
		else if (arr[i][j] == 'P')
		{
			lg->x_play = i * 65;
			lg->y_play = j * 65;
			j++;
		}
		else
		{
			write(1, "ERROR\n", 6);
			exit (0);
		}
	}
	eval_ft_ls_str_bonus(i, arr, lg);
}

void	valid_value_bonus(char **arr, t_job *lg)
{
	static int	i;
	int			j;

	i = 0;
	j = 0;
	while (i < lg->height)
	{
		eval_string_bonus(i, arr, lg);
		i++;
	}
}

void	addNxM_bonus(char **arr, t_job *lg, char *av)
{
	int		i;
	int		fd;
	char	*line;

	i = 0;
	fd = open(av, O_RDWR, 0);
	while (get_next_line(fd, &line))
	{
		fill_mat_bonus(line, arr[i], lg->width);
		free(line);
		i++;
	}
	fill_mat_bonus(line, arr[i], lg->width);
	close (fd);
	free (line);
}
