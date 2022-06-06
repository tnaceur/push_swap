#include "../push_swap.h"

int	ft_lstsize(t_stack *a)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = a;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}