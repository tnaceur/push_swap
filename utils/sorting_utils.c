/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaceur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 13:32:07 by tnaceur           #+#    #+#             */
/*   Updated: 2022/05/23 13:32:10 by tnaceur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_norm(t_stack **a, t_stack **b)
{
	if (ft_smal_num(a) == 4)
	{
		ft_rra(a);
		ft_rra(a);
		ft_pb(a, b);
		sort4(a, b);
		ft_pa(a, b);
	}
	else if (ft_smal_num(a) == 5)
	{
		ft_rra(a);
		ft_pb(a, b);
		sort4(a, b);
		ft_pa(a, b);
	}
}

void	sort5(t_stack **a, t_stack **b)
{
	if (ft_smal_num(a) == 1)
	{
		ft_pb(a, b);
		sort4(a, b);
		ft_pa(a, b);
	}
	else if (ft_smal_num(a) == 2)
	{
		ft_sa(a);
		ft_pb(a, b);
		sort4(a, b);
		ft_pa(a, b);
	}
	else if (ft_smal_num(a) == 3)
	{
		ft_ra(a);
		ft_ra(a);
		ft_pb(a, b);
		sort4(a, b);
		ft_pa(a, b);
	}
	else
		sort_norm(a, b);
}

void	sort3(t_stack **a)
{
	if (is_sorted(a) == 0)
	{
		if (ft_smal_num(a) == 1)
		{
			ft_rra(a);
			ft_sa(a);
		}
		else if (ft_smal_num(a) == 2)
		{
			if ((*a)->data > (*a)->next->next->data)
				ft_ra(a);
			else
				ft_sa(a);
		}
		else if (ft_smal_num(a) == 3)
		{
			if ((*a)->data > (*a)->next->data)
			{
				ft_sa(a);
				ft_rra(a);
			}
			else
				ft_rra(a);
		}
	}
}

void	sort4(t_stack **a, t_stack **b)
{
	if (ft_smal_num(a) == 1)
	{
		ft_pb(a, b);
		sort3(a);
		ft_pa(a, b);
	}
	else if (ft_smal_num(a) == 2)
	{
		ft_sa(a);
		ft_pb(a, b);
		sort3(a);
		ft_pa(a, b);
	}
	else
		sort_norm2(a, b);
}

void	small_sort(t_stack **a, t_stack **b, int size)
{
	if (size == 2 && (*a)->data > (*a)->next->data)
	{
		ft_sa(a);
		return ;
	}
	if (size == 3)
	{
		if (is_sorted(a) == 0)
			sort3(a);
		else
			return ;
	}
	if (size == 4)
	{
		if (is_sorted(a) == 0)
			sort4(a, b);
		else
			return ;
	}
	if (size == 5)
	{
		if (is_sorted(a) == 0)
			sort5(a, b);
	}
}
