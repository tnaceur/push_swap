/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaceur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 11:26:30 by tnaceur           #+#    #+#             */
/*   Updated: 2022/05/21 11:26:44 by tnaceur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rrr(t_stack **a)
{
	t_stack	*before_last;
	t_stack	*last;

	last = *a;
	while (last->next)
	{
		before_last = last;
		last = last->next;
	}
	before_last->next = NULL;
	last->next = *a;
	*a = last;
}

void	ft_rrr(t_stack **a, t_stack **b)
{
	rrr(a);
	rrr(b);
}
