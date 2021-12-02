/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graph_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galetha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 17:03:32 by galetha           #+#    #+#             */
/*   Updated: 2021/10/18 17:03:34 by galetha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"
#include "../mlx/mlx.h"
#include "../so_long.h"

char	ft_rep(int len, int n)
{
	if (n == 0)
	{
		len++;
		return (len);
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_mal(int i, int len, int num, int min)
{
	char	*p;

	p = (char *) malloc(sizeof(char) * (len) + 1 + min);
	if (!p)
		return (NULL);
	p[i + 1] = '\0';
	while (i >= 0)
	{
		p[i] = num % 10 + '0';
		num = num / 10;
		i--;
	}
	if (min == 1)
		p[0] = '-';
	return (p);
}

char	*ft_itoa(int n)
{
	int		len;
	int		i;
	int		num;
	int		min;
	char	*ptr;

	min = 0;
	i = 0;
	len = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0)
	{
		min++;
		n *= -1;
	}
	num = n;
	if (n >= 0)
	{
		len = ft_rep(len, n);
		i = len - 1 + min;
	}
	ptr = ft_mal(i, len, num, min);
	return (ptr);
}

void	end_fon_bonus(t_job *lg, char c)
{
	char	**arr;

	arr = lg->ptr;
	lg->i = 0;
	lg->j = 0;
	while (lg->i < lg->height)
	{
		lg->j = 0;
		while (lg->j < lg->width)
		{
			if (c == 'W')
				arr[lg->i][lg->j] = '2';
			else if (c == 'D')
				arr[lg->i][lg->j] = '3';
			lg->j++;
		}
		lg->i++;
	}
}
