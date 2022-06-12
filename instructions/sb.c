/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sb.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaceur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 15:06:57 by tnaceur           #+#    #+#             */
/*   Updated: 2022/05/18 15:07:16 by tnaceur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sb(t_stack **b)
{
	t_stack	*sec;

	if (*b)
	{
		sec = *b;
		if (sec->next)
			sec = sec->next;
		else
			return ;
		sec->next = *b;
		(*b)->next = sec->next;
		*b = sec;
		write(1, "sb\n", 3);
	}
}
