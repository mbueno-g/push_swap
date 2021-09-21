/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbueno-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 10:46:49 by mbueno-g          #+#    #+#             */
/*   Updated: 2021/09/21 18:49:21 by mbueno-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_in_pos(t_list *b, int len)
{
	int	aux;
	int	i;

	i = 0;
	aux = len;
	while (b)
	{
		if (*(int *)b->content == len - 1 - i)
			aux--;
		else
			aux = len;
		i++;
		b = b->next;
	}
	return (aux);
}

void	ft_big_sort(t_list **a, t_list **b)
{
	int	len_a;
	int	max_bits;
	int	j;
	int	i;

	len_a = ft_lstsize(*a);
	max_bits = 0;
	while ((len_a >> max_bits) != 0)
		max_bits++;
	i = -1;
	while (++i <= max_bits - 1)
	{
		j = -1;
		while (++j <= len_a - 1 && !ft_issorted(*a))
		{
			if (((*(int *)(*a)->content >> i) & 1) == 0 && j != len_a - 1)
				ft_push(a, b, 'b');
			else if (((*(int *)(*a)->content >> i) & 1) != 0)
				ft_rotate(a, 'a');
		}
		while (ft_lstsize(*b))
			ft_push(b, a, 'a');
		len_a = ft_lstsize(*a);
	}
}
