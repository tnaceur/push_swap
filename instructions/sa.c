/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaceur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 15:06:17 by tnaceur           #+#    #+#             */
/*   Updated: 2022/05/18 15:06:35 by tnaceur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sa(t_stack **a)
{
	t_stack	*sec;

	if (*a)
	{
		sec = *a;
		if (sec->next)
			sec = sec->next;
		else
			return ;
		(*a)->next = sec->next;
		sec->next = *a;
		*a = sec;
		write(1, "sa\n", 3);
	}
}
