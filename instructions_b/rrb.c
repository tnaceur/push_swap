/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrb.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaceur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 11:26:30 by tnaceur           #+#    #+#             */
/*   Updated: 2022/05/21 11:26:44 by tnaceur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_rrb(t_stack **b)
{
	t_stack	*before_last;
	t_stack	*last;

	last = *b;
	if ((*b) && (*b)->next)
	{
		while (last->next)
		{
			before_last = last;
			last = last->next;
		}
		before_last->next = NULL;
		last->next = *b;
		*b = last;
	}
}
