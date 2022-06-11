/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rr.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaceur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 09:02:45 by tnaceur           #+#    #+#             */
/*   Updated: 2022/05/21 09:03:13 by tnaceur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rr(t_stack **a)
{
	t_stack	*new_a;
	t_stack	*first;
	t_stack	*last;

	last = *a;
	first = (*a)->next;
	while (last->next)
		last = last->next;
	last->next = *a;
	(*a)->next = NULL;
	new_a = first;
	*a = new_a;
}

void	ft_rr(t_stack **a, t_stack **b)
{
	rr(a);
	rr(b);
}
