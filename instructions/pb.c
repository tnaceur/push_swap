/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaceur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 09:09:15 by tnaceur           #+#    #+#             */
/*   Updated: 2022/05/21 09:09:28 by tnaceur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_pb(t_stack **b, t_stack **a)
{
	t_stack	*new_b;
	t_stack	*new_a;

	if (!*b)
		return ;
	new_b = *b;
	if ((*b)->next)
		new_b = (*b)->next;
	(*b)->next = *a;
	new_a = *b;
	*a = new_a;
	*b = new_b;
	write(1, "pb\n", 3);
}
