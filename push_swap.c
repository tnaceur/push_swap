/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaceur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 11:53:32 by tnaceur           #+#    #+#             */
/*   Updated: 2022/05/18 11:53:51 by tnaceur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack **a)
{
	t_stack	*tmp;

	tmp = *a;
	while (tmp)
	{
		if (tmp->next)
		{
			if (tmp->data > tmp->next->data)
				return (0);
		}
		tmp = tmp->next;
	}
	return (1);
}

int	ft_smal_num(t_stack **a)
{
	t_stack	*tmp;
	int		first_num;
	int		i;
	int		j;

	tmp = *a;
	first_num = tmp->data;
	i = 1;
	j = 1;
	while (tmp)
	{
		if (tmp->data < first_num)
		{
			first_num = tmp->data;
			j = i;
		}
		i++;
		tmp = tmp->next;
	}
	return (j);
}

void	error_message(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
	exit(1);
}

void	fill_stack(t_stack **a, char **av)
{
	int		i;
	t_stack	*tmp;

	i = 1;
	*a = NULL;
	while (av[i])
	{
		tmp = ft_lstnew(ft_atoi(av[i]));
		if (!tmp)
			error_message("ALLOCATION FAILD 👎🏻\n");
		ft_lstadd_back(a, tmp);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	int		*sorted;

	if (ft_isalnum(av) && not_dup(av))
	{
		b = NULL;
		fill_stack(&a, av);
		sorted = fill_sorted(a, ac - 1);
		sort_sorted(sorted, ac - 1);
		ft_index(sorted, &a, ac - 1);
		if (ac <= 6)
			small_sort(&a, &b, ac - 1);
		else
			big_sort(&a, &b);
	}
	else
		error_message("WRONG ARGUMENTS\n");
}
