/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaceur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 08:00:20 by tnaceur           #+#    #+#             */
/*   Updated: 2021/11/24 16:06:11 by tnaceur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../push_swap.h"

static int	ft_isppace(char *str, int i)
{
	while (str[i] == ' ' || str[i] == '\t'
		|| str[i] == '\r' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f')
		i++ ;
	return (i);
}

static int	ft_num(char *str, int i, int signe)
{
	int		cmp;
	long	nb;

	cmp = 0;
	nb = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb *= 10;
		nb += str[i] - '0';
		if ((nb > 2147483647 && signe == 1)
			|| (nb > 2147483648 && signe == -1))
			error_message("Error\n");
		i++ ;
		cmp++ ;
	}
	if (cmp > 19 && signe == -1)
		return (0);
	else if (cmp > 19 && signe == 1)
		return (-1);
	return (nb * signe);
}

int	ft_atoi(char *str)
{
	int	signe;
	int	i;
	int	num;

	i = 0;
	i = ft_isppace(str, i);
	signe = 1;
	if (!str[i])
		error_message("Error\n");
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			signe *= -1;
		i++ ;
	}
	if (str[i] == '+' || str[i] == '-')
		return (0);
	num = ft_num(str, i, signe);
	return (num);
}
