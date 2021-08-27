
#include "push_swap.h"

void	ft_sort_three(t_list **a)
{
	int	min;
	int	max;

	min = 0;
	max = 0;
	while (!ft_issorted(*a))
	{
		min = ft_min(*a);
		max = ft_max(*a);
		if (min == 2 && max == 1)
			ft_rotate(a, 'a');
		else if (min == 3 && max == 2)
			ft_reverse_rotate(a, 'a');
		else
			ft_swap(a, 'a');
	}
}

void	ft_place_in_top(t_list **a, int min)
{
	int	distancia;
	int	len;
	int	r;

	len = ft_lstsize(*a);
	r = 1;
	distancia = min - 1;
	if (min > 3)
	{
		r = 2;
		distancia = len - (min - 1);
	}
	while (distancia)
	{
		if (r == 1)
			ft_rotate(a, 'a');
		else
			ft_reverse_rotate(a, 'a');
		distancia--;
	}
}

//Selection sort algorithm: find the minimum value and
//place it in the top, then pust it to b;
void	ft_sort_four_five(t_list **a, t_list **b)
{
	int	min;
	int	len;

	min = 0;
	len = ft_lstsize(*a);
	while (len != 3)
	{
		min = ft_min(*a);
		ft_place_in_top(a, min);
		if (!ft_issorted((*a)->next))
		{
			ft_push(a, b, 'b');
			len = ft_lstsize(*a);
		}
		else
			len = 3;
	}
	ft_sort_three(a);
	while (*b)
		ft_push(b, a, 'a');
	while (*a)
	{
		printf("%d", (*a)->content);
		*a = (*a)->next;
	}

}
