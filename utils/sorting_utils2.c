/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaceur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 15:24:12 by tnaceur           #+#    #+#             */
/*   Updated: 2022/05/25 15:24:30 by tnaceur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_norm2(t_stack **a, t_stack **b)
{
	if (ft_smal_num(a) == 3)
	{
		ft_ra(a);
		ft_sa(a);
		ft_pb(a, b);
		sort3(a);
		ft_pa(a, b);
	}
	else if (ft_smal_num(a) == 4)
	{
		ft_rra(a);
		ft_pb(a, b);
		sort3(a);
		ft_pa(a, b);
	}
}

int	ft_isalnum(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		if (av[i][j] == '-' || av[i][j] == '+')
		{
			j++;
			if (!av[i][j])
				return (0);
		}
		while (av[i][j])
		{
			if (av[i][j] < '0' || av[i][j] > '9')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	not_dup(char **av)
{
	int	i;
	int	j;

	i = 2;
	while (av[i])
	{
		j = 1;
		while (av[j] && ft_atoi(av[j]) != ft_atoi(av[i]))
		{
			j++;
			if (j == i)
				j++;
		}
		if (av[j] && ft_atoi(av[i]) == ft_atoi(av[j]))
			return (0);
		i++;
	}
	return (1);
}

int	*fill_sorted(t_stack *a, int size)
{
	t_stack	*tmp;
	int		i;
	int		j;
	int		*sorted;

	i = 0;
	j = 0;
	tmp = a;
	sorted = malloc(size * sizeof(int));
	while (tmp && size > i)
	{
		sorted[j] = tmp->data;
		i++;
		j++;
		tmp = tmp->next;
	}
	return (sorted);
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

int	nbr_push_init(int size)
{
	if (size <= 100)
		return ((size - 5) / 3 + 1);
	else
		return ((size - 5) / 5 + 1);
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
	{
		printf("a : %d  b : %d\n", (*a)->index, (*b)->index);
		ft_push_a(a, b, &data);
	}
	while (ft_lstlast(*a)->index != -1)
	{
		ft_rra(a);
	}
}

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
		if ((*b)->data < data->med)
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
		if ((*b)->data < data->med)
			ft_rb(b);
	}
}

void	ft_push_a(t_stack **a, t_stack **b, t_info *data)
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
