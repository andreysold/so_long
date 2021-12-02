/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: galetha <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 16:52:46 by galetha           #+#    #+#             */
/*   Updated: 2021/10/18 16:52:50 by galetha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	char			*p;
	unsigned long	i;

	p = (char *)s;
	i = 0;
	while (p[i] != (char)c)
	{
		if (p[i] == '\0')
			return (NULL);
		i++;
	}
	return (&p[i]);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*p;
	size_t			i;
	size_t			j;
	size_t			len;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	p = (char *)malloc(sizeof(char) * (len + 1));
	if (!p)
		return (NULL);
	while (s1[i] != '\0')
	{
		p[i] = s1[i];
		i++;
	}
	while (s2[j] != '\0')
	{
		p[i++] = s2[j++];
	}
	p[i] = '\0';
	return (p);
}

void	*ft_call(size_t count, size_t size)
{
	char	*p;
	size_t	i;
	size_t	len;

	i = 0;
	len = size * count;
	p = (char *)malloc(sizeof(char) * (len));
	if (!p)
		return (NULL);
	while (i < len)
	{
		p[i] = (unsigned char)0;
		i++;
	}
	return (&p[0]);
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*p;
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s1);
	p = (char *)malloc(sizeof(char) * (len + 1));
	if (!p)
		return (NULL);
	while (s1[i] != '\0')
	{
		p[i] = s1[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}
