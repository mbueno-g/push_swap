/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbueno-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 17:01:17 by mbueno-g          #+#    #+#             */
/*   Updated: 2021/09/13 18:22:57 by mbueno-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_block_size(t_list *a)
{
	//int	min;
	//int max;
	int	len;

	len = ft_lstsize(a);
	if (len > 5 && len < 100)
		return (len / 5);
	else if (len >= 100 && len < 500)
		return (len / 10);
	else
		return (len / 20);
}

/*int	ft_in_pos(t_list *b, int len)
{
	if (!b)
		return (len);
	else if (len == *(int *)b->content)
		ft_in_pos(b->next, len--);
	else
		return (len);
}*/


void	ft_big_sort(t_list **a, t_list **b)
{
	//int size;
	//size = ft_block_size(*a);
	
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
		while(j < len_a)
		{
			if (((*(int *)(*a)->content >> i) & 1) == 0)
					ft_push(a, b, 'b');
			else
					ft_rotate(a, 'a');
			j++;
		}
		len_b = ft_lstsize(*b);
		//len_b = ft_in_pos(*b, len_b);
		while(len_b--)
		{
			ft_push(b, a, 'a');
		}
		st_printstack_ab(*a, *b);
		i++;
	}
}
