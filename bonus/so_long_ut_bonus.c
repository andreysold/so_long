/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_ut_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galetha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:08:10 by galetha           #+#    #+#             */
/*   Updated: 2021/10/18 17:09:31 by galetha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"
#include "../mlx/mlx.h"
#include "../so_long.h"

int	get_het_bonus(char *file_name)
{
	int		fd;
	char	*line;
	int		l;

	l = 0;
	fd = open (file_name, O_RDONLY, 0);
	while (get_next_line(fd, &line))
	{
		l++;
		free (line);
	}
	l++;
	close (fd);
	if (l <= 2)
	{
		write (1, "ERROR\n", 6);
		exit (0);
	}
	free (line);
	return (l);
}

int	eval_count_bonus(char *file_name)
{
	int		fd;
	char	ch;
	int		k;

	k = 0;
	fd = open (file_name, O_RDONLY, 0);
	while (read (fd, &ch, 1) > 0)
	{
		if (ch != '\n')
			k++;
	}
	close (fd);
	return (k);
}

int	get_wid_bonus(char *file_name)
{
	int		fd;
	char	ch;
	int		k;

	k = 0;
	fd = open (file_name, O_RDONLY, 0);
	while (read (fd, &ch, 1) > 0 && ch != '\n')
		k++;
	close (fd);
	return (k);
}

void	st_info_bonus(char *file_name, t_job **sl)
{
	int	count;
	int	mult;

	mult = 0;
	count = 0;
	(*sl)->height = get_het_bonus(file_name);
	(*sl)->width = get_wid_bonus(file_name);
	count = eval_count_bonus(file_name);
	mult = (*sl)->height * (*sl)->width;
	(*sl)->w_width = (*sl)->width * 65;
	(*sl)->w_height = (*sl)->height * 65;
	if (count != mult)
	{
		write(1, "ERROR\n", 6);
		exit(0);
	}
}
