/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbueno-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 17:01:17 by mbueno-g          #+#    #+#             */
/*   Updated: 2021/09/16 17:50:03 by mbueno-g         ###   ########.fr       */
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
		//printf("adios\n");
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
	int	len_b;
	int	max_bits;
	int	j;
	int	i;

	len_a = ft_lstsize(*a);
	max_bits = 0;
	while((len_a >> max_bits) != 0)
		max_bits++;
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while(j < len_a && !ft_issorted(*a))
		{
			if (((*(int *)(*a)->content >> i) & 1) == 0) // && !ft_issorted(*a))
					ft_push(a, b, 'b');
			else
					ft_rotate(a, 'a');
			//st_printstack_ab(*a, *b);
			j++;
		}
		//printf("send to b\n");
		//st_printstack_ab(*a, *b);
		len_b = ft_lstsize(*b);
		if (i != max_bits - 1)
			len_b = ft_in_pos(*b, len_b);
		//printf("LEN %d\n", len_b);
		while(len_b--)
		{
			ft_push(b, a, 'a');
		}
		//printf("all in a\n");
		//st_printstack_ab(*a, *b);
		i++;
	}
}
