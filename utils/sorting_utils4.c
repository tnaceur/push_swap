/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaceur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/09 08:18:09 by tnaceur           #+#    #+#             */
/*   Updated: 2022/06/09 08:18:11 by tnaceur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	small_index(t_stack **a)
{
	t_stack	*tmp;
	int		small_nb;

	tmp = *a;
	small_nb = tmp->index;
	while (tmp)
	{
		if (tmp->index < small_nb)
			small_nb = tmp->index;
		tmp = tmp->next;
	}
	return (small_nb);
}

int	return_position(t_stack **a, t_info data)
{
	t_stack	*tmp;
	int		i;

	tmp = *a;
	i = 0;
	while (tmp)
	{
		if (tmp->index >= data.min && tmp->index <= data.max)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	ft_push_b(t_stack **a, t_stack **b, t_info *data)
{
	if (data->position < (data->size / 2))
	{
		while (data->position != 0)
		{
			ft_ra(a);
			data->position--;
		}
		ft_pb(a, b);
		if ((*b)->index < data->med)
			ft_rb(b);
	}
	else
	{
		while (data->position < data->size)
		{
			ft_rra(a);
			data->position++;
		}
		ft_pb(a, b);
		if ((*b)->index < data->med)
			ft_rb(b);
	}
}

void	sort_sorted(int *sorted, int size)
{
	int		i;
	int		a;

	i = 0;
	a = 0;
	while (i < size)
	{
		if (i + 1 < size && sorted[i] > sorted[i + 1])
		{
			a = sorted[i];
			sorted[i] = sorted[i + 1];
			sorted[i + 1] = a;
			i = -1;
		}
		i++;
	}
}

void	big_sort(t_stack **a, t_stack **b)
{
	t_info	data;

	data.min = small_index(a);
	data.size = ft_lstsize(*a);
	data.nbr_push = nbr_push_init(data.size);
	data.max = data.min + data.nbr_push - 1;
	data.position = return_position(a, data);
	data.med = (data.min + data.max) / 2;
	while (data.size > 5)
	{
		ft_push_b(a, b, &data);
		data.min = small_index(a);
		data.size = ft_lstsize(*a);
		data.nbr_push = nbr_push_init(data.size);
		data.max = data.min + data.nbr_push - 1;
		data.position = return_position(a, data);
		data.med = (data.min + data.max) / 2;
	}
	sort5(a, b);
	ft_lstlast((*a))->index = -1;
	while ((*b))
		ft_push_a(a, b, &data);
	while (ft_lstlast(*a)->index != -1)
		ft_rra(a);
}
