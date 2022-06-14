/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ss.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaceur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 15:07:58 by tnaceur           #+#    #+#             */
/*   Updated: 2022/05/18 15:08:14 by tnaceur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ss(t_stack **a)
{
	t_stack	*sec;

	sec = *a;
	if (*a)
	{
		if (sec->next)
			sec = sec->next;
		else
			return ;
		(*a)->next = sec->next;
		sec->next = *a;
		*a = sec;
	}
}

void	ft_ss(t_stack **a, t_stack **b)
{
	ss(a);
	ss(b);
}
