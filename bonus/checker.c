/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaceur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 12:44:06 by tnaceur           #+#    #+#             */
/*   Updated: 2022/06/11 12:44:08 by tnaceur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_check(t_stack **a, t_stack **b, char *s)
{
	if (strcmp(s, "sa"))
		ft_sa(a);
	else if (strcmp(s, "sb"))
		ft_sb(b);
	else if (strcmp(s, "ra"))
		ft_ra(a);
	else if (strcmp(s, "rb"))
		ft_rb(b);
	else if (strcmp(s, "pa"))
		ft_pa(a, b);
	else if (strcmp(s, "pb"))
		ft_pb(b, a);
	else if (strcmp(s, "rr"))
		ft_rr(a, b);
	else if (strcmp(s, "rrr"))
		ft_rrr(a, b);
	else if (strcmp(s, "rra"))
		ft_rra(a);
	else if (strcmp(s, "rrb"))
		ft_rrb(b);
	else if (strcmp(s, "ss"))
		ft_ss(a, b);
	else
		error_message("Error\n");
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;
	char	*s;

	b = NULL;
	(void)ac;
	fill_stack(&a, av);
	while (1)
	{
		s = get_next_line(0);
		ft_check(&a, &b, s);
	}
}