/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaceur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 15:02:38 by tnaceur           #+#    #+#             */
/*   Updated: 2022/05/18 15:02:41 by tnaceur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_ra(t_stack **a)
{
	t_stack	*new_a;
	t_stack	*first;
	t_stack	*last;

	if ((*a)->next)
	{
		last = *a;
		first = (*a)->next;
		while (last->next)
			last = last->next;
		last->next = *a;
		(*a)->next = NULL;
		new_a = first;
		*a = new_a;
	}
}
