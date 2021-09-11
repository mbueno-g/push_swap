
#include "push_swap.h"
# include "Libft/libft.h"

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
		if (min == 1 && max == 0)
			ft_rotate(a, 'a');
		else if (min == 2 && max == 1)
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
	distancia = min;
	if (min > len/2)
	{
		r = 2;
		distancia = len - min;
	}
	//printf("distancia %d\n", distancia);
	while (distancia)
	{
		if (r == 1)
		//¿Cuando hacer swap? EJ: 2 1 3 4 5
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
	int	sort;

	min = 0;
	len = ft_lstsize(*a);
	sort = 0;
	while (len != 3)
	{
		min = ft_min(*a);
		ft_place_in_top(a, min);
		st_printstack_ab(*a,*b);
		sort = ft_issorted((*a)->next);
		if (sort)
				break;
		ft_push(a, b, 'b');
		len = ft_lstsize(*a);
	}
	if (len == 3)
		ft_sort_three(a);
	while (*b)
		ft_push(b, a, 'a');
	//st_printstack_ab(*a,*b);
}
