/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaceur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 15:24:12 by tnaceur           #+#    #+#             */
/*   Updated: 2022/05/25 15:24:30 by tnaceur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_norm2(t_stack **a, t_stack **b)
{
	if (ft_smal_num(a) == 3)
	{
		ft_ra(a);
		ft_sa(a);
		ft_pb(a, b);
		sort3(a);
		ft_pa(a, b);
	}
	else if (ft_smal_num(a) == 4)
	{
		ft_rra(a);
		ft_pb(a, b);
		sort3(a);
		ft_pa(a, b);
	}
}

int	ft_isalnum(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		if (av[i][j] == '-' || av[i][j] == '+')
		{
			j++;
			if (!av[i][j])
				return (0);
		}
		while (av[i][j])
		{
			if (av[i][j] < '0' || av[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	not_dup(char **av)
{
	int	i;
	int	j;

	i = 2;
	while (av[i])
	{
		j = 1;
		while (av[j] && ft_atoi(av[j]) != ft_atoi(av[i]))
		{
			j++;
			if (j == i)
				j++;
		}
		if (av[j] && ft_atoi(av[i]) == ft_atoi(av[j]))
			return (0);
		i++;
	}
	return (1);
}

int	*fill_sorted(t_stack *a, int size)
{
	t_stack	*tmp;
	int		i;
	int		j;
	int		*sorted;

	i = 0;
	j = 0;
	tmp = a;
	sorted = malloc(size * sizeof(int));
	while (tmp && size > i)
	{
		sorted[j] = tmp->data;
		i++;
		j++;
		tmp = tmp->next;
	}
	return (sorted);
}

int	nbr_push_init(int size)
{
	if (size <= 100)
		return ((size - 5) / 3 + 1);
	else
		return ((size - 5) / 5 + 1);
}
