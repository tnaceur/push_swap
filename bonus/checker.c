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

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i] == s2[j] && s1[i] && s2[j])
	{
		i++;
		j++;
		if (s1[i] != s2[j])
			break ;
	}
	if (s1[i] != s2[j])
		return (0);
	return (1);
}

void	ft_check(t_stack **a, t_stack **b, char *s)
{
	if (ft_strcmp(s, "sa\n"))
		ft_sa(a);
	else if (ft_strcmp(s, "sb\n"))
		ft_sb(b);
	else if (ft_strcmp(s, "ra\n"))
		ft_ra(a);
	else if (ft_strcmp(s, "rb\n"))
		ft_rb(b);
	else if (ft_strcmp(s, "pa\n"))
		ft_pa(a, b);
	else if (ft_strcmp(s, "pb\n"))
		ft_pb(a, b);
	else if (ft_strcmp(s, "rr\n"))
		ft_rr(a, b);
	else if (ft_strcmp(s, "rrr\n"))
		ft_rrr(a, b);
	else if (ft_strcmp(s, "rra\n"))
		ft_rra(a);
	else if (ft_strcmp(s, "rrb\n"))
		ft_rrb(b);
	else if (ft_strcmp(s, "ss\n"))
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
	if (ft_isalnum(av) && not_dup(av))
	{
		fill_stack(&a, av);
		while (1)
		{
			s = get_next_line(0);
			ft_check(&a, &b, s);
		}
		if (is_sorted(&a) && !b)
			write(1, "OK\n", 3);
		else
			write(1, "KO\n", 3);
	}
}
