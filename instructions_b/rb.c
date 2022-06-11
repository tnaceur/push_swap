/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaceur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 15:02:38 by tnaceur           #+#    #+#             */
/*   Updated: 2022/05/18 15:02:41 by tnaceur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_rb(t_stack **b)
{
	t_stack	*new_b;
	t_stack	*first;
	t_stack	*last;

	if ((*b)->next)
	{
		last = *b;
		first = (*b)->next;
		while (last->next)
			last = last->next;
		last->next = *b;
		(*b)->next = NULL;
		new_b = first;
		*b = new_b;
	}
}
