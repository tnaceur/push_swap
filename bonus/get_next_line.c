/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaceur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 09:06:08 by tnaceur           #+#    #+#             */
/*   Updated: 2022/03/20 17:46:44 by tnaceur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_substr(char *s)
{
	int		i;
	int		j;
	char	*str;

	if (!s)
		return (NULL);
	i = ft_strlen(s);
	str = malloc(i + 1);
	i = 0;
	j = 0;
	while (s[i])
		str[j++] = s[i++];
	str[i] = '\0';
	return (str);
}

char	*get_next_line(int fd)
{
	int		i;
	int		j;
	char	buff[100000];
	char	c;

	if (fd < 0)
		return (NULL);
	i = 0;
	j = 1;
	buff[0] = 0;
	while (j == read(fd, &c, 1) && j != 0)
	{
		buff[i++] = c;
		buff[i] = '\0';
		if (c == '\n')
			return (ft_substr(buff));
	}
	if (!buff[0])
		return (NULL);
	return (ft_substr(buff));
}
