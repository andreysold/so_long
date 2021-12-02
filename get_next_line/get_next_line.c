/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galetha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:52:36 by galetha           #+#    #+#             */
/*   Updated: 2021/10/18 16:52:39 by galetha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"
void	ft_func_for_all(char **remainder, char **line)
{
	if (*remainder)
	{
		*line = ft_strdup(*remainder);
		free (*remainder);
		*remainder = NULL;
	}
}

void	ft_func_for_remainder(char **remainder, char **line)
{
	char	*p_n;
	char	*tmp;

	if (*remainder)
	{
		p_n = ft_strchr(*remainder, '\n');
		if (p_n)
		{
			*p_n = '\0';
			*line = ft_strdup(*remainder);
			tmp = *remainder;
			*remainder = ft_strdup(++p_n);
			free (tmp);
		}
	}
}

void	ft_ll(char *buf, char **remainder)
{
	char	*during_time;

	if (*remainder)
	{
		during_time = *remainder;
		*remainder = ft_strjoin(*remainder, buf);
		free (during_time);
	}
	else
		*remainder = ft_strdup(buf);
}

int	raspredel(ssize_t rread, char **line, char **buf, char **remainder)
{
	ft_ll(*buf, remainder);
	free (*buf);
	if (ft_strchr(*remainder, '\n'))
	{
		ft_func_for_remainder(remainder, line);
		return (1);
	}
	else if (!(ft_strchr(*remainder, '\n')) && rread == 0)
	{
		ft_func_for_all(remainder, line);
		return (0);
	}
	return (-1);
}

int	get_next_line(int fd, char **line)
{
	char		*buf;
	ssize_t		rread;
	static char	*remainder;
	int			nt;

	if (read(fd, 0, 0) < 0 || BUFFER_SIZE < 1 || line == NULL)
		return (-1);
	rread = 1;
	while (rread > 0)
	{
		buf = ft_call(BUFFER_SIZE + 1, sizeof(char));
		if (!buf)
			return (-1);
		rread = read(fd, buf, BUFFER_SIZE);
		nt = raspredel(rread, line, &buf, &remainder);
		if (nt > -1)
			return (nt);
	}
	return (0);
}
