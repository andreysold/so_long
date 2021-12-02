/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galetha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:09:41 by galetha           #+#    #+#             */
/*   Updated: 2021/10/18 17:12:48 by galetha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"
#include "../mlx/mlx.h"
#include "../so_long.h"

void	val_ber_bonus(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '.')
		{
			if (!(str[i + 1] == 'b' && str[i + 2] == 'e'
					&& str[i + 3] == 'r' && str[i + 4] == '\0'))
			{
				write(1, "ERROR MAP\n", 6);
				exit (0);
			}
		}
		i++;
	}
}

void	valid_ber_bonus(char *av, int ac)
{
	int	len;

	if (ac <= 1)
	{
		write(1, "ERROR MAP\n", 6);
		exit (0);
	}
	len = ft_strlen(av);
	if (len < 5)
	{
		write(1, "ERROR MAP\n", 10);
		exit(0);
	}
	val_ber_bonus(av);
}

int	main(int ac, char **av)
{
	t_job	*lg;
	char	**arr;

	valid_ber_bonus (av[1], ac);
	lg = malloc(sizeof(t_job));
	if (!lg)
		return (-1);
	init_job_bonus(&lg);
	st_info_bonus(av[1], &lg);
	arr = (char **)malloc(sizeof(int *) * (lg->height + 1));
	while (lg->i <= lg->height)
		arr[lg->i++] = (char *)malloc(sizeof(int) * (lg->width + 1));
	addNxM_bonus(arr, lg, av[1]);
	valid_value_bonus(arr, lg);
	lg->ptr = arr;
	count_coins_bonus(&lg);
	win_arr_bonus(lg);
	ft_no_malloc_bonus(arr, lg);
	free(arr);
	free(lg);
}
