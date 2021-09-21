/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_to_five.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbueno-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 16:14:09 by mbueno-g          #+#    #+#             */
/*   Updated: 2021/09/21 18:52:33 by mbueno-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "Libft/libft.h"

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
	if (min > len / 2)
	{
		r = 2;
		distancia = len - min;
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
	int	sort;

	min = 0;
	len = ft_lstsize(*a);
	sort = 0;
	while (len != 3)
	{
		min = ft_min(*a);
		ft_place_in_top(a, min);
		sort = ft_issorted((*a)->next);
		if (sort)
			break ;
		ft_push(a, b, 'b');
		len = ft_lstsize(*a);
	}
	if (len == 3)
		ft_sort_three(a);
	while (*b)
		ft_push(b, a, 'a');
}
