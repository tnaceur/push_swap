/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaceur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 08:11:27 by tnaceur           #+#    #+#             */
/*   Updated: 2022/06/09 08:11:29 by tnaceur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_push_a(t_stack **a, t_stack **b)
{
	if ((*a)->index - 1 == (*b)->index)
		ft_pa(a, b);
	else
	{
		if (exist((*a)->index - 1, b))
		{
			if (((*b)->index < (*a)->index
					&& (*b)->index > ft_lstlast((*a))->index))
			{
				ft_pa(a, b);
				ft_ra(a);
			}
			else
				ft_search(b, a);
		}
		else
			ft_rra(a);
	}
}

int	exist(int num, t_stack **b)
{
	t_stack	*tmp;

	tmp = *b;
	while (tmp)
	{
		if (tmp->index == num)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	ft_search(t_stack **b, t_stack **a)
{
	while ((*b)->index != (*a)->index - 1)
	{
		if (lfo9(b, (*a)->index - 1) == 1)
			ft_rb(b);
		else
			ft_rrb(b);
	}
}

int	lfo9(t_stack **b, int num)
{
	int		i;
	int		j;
	t_stack	*tmp;

	i = 0;
	j = 0;
	tmp = *b;
	while (tmp)
	{
		if (tmp->index == num)
		{
			j = i;
			break ;
		}
		tmp = tmp->next;
		i++;
	}
	if (j < (ft_lstsize(*b) / 2))
		return (1);
	return (0);
}

void	ft_index(int *sorted, t_stack **a, int size)
{
	t_stack	*tmp;
	int		i;
	int		j;

	tmp = *a;
	i = 0;
	j = 0;
	while (tmp)
	{
		if (i < size && tmp->data == sorted[i])
		{
			j++;
			tmp->index = j;
			tmp = *a;
			i++;
		}
		else
			tmp = tmp->next;
	}
}
