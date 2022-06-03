/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnaceur <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 11:53:57 by tnaceur           #+#    #+#             */
/*   Updated: 2022/05/18 11:55:43 by tnaceur          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define RED "\x1B[31m"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_stack{
	int				index;
	int				data;
	struct s_stack	*next;
}	t_stack;

typedef struct s_info {
	int	min_num;
	int	max_num;
	int	nbr_push;
}	t_info;

t_stack		*ft_lstnew(int content);
t_stack		*ft_lstlast(t_stack *lst);
void		ft_lstadd_back(t_stack **alst, t_stack *new);
int			ft_atoi(char *str);
void		ft_ra(t_stack **a);
void		ft_rra(t_stack **a);
void		ft_sa(t_stack **a);
void		ft_ss(t_stack **a, t_stack **b);
void		ft_rr(t_stack **a, t_stack **b);
void		ft_pa(t_stack **a, t_stack **b);
void		ft_pb(t_stack **b, t_stack **a);
void		sort_norm2(t_stack **a, t_stack **b);
void		ft_sb(t_stack **b);
int			is_sorted(t_stack **a);
void		small_sort(t_stack **a, t_stack **b, int size);
void		sort3(t_stack **a);
void		sort4(t_stack **a, t_stack **b);
int			ft_smal_num(t_stack **a);
int			ft_isalnum(char **av);
int			not_dup(char **av);
int			*fill_sorted(t_stack *a, int size);
void		sort_sorted(int *sorted, int size);
void		ft_index(int *sorted, t_stack **a, int size);
void	big_sort(t_stack **a, t_stack **b, int *sorted, int size);

#endif