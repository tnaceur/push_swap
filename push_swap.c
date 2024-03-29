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
