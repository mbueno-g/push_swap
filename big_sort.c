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

void	ft_big_sort(t_list **a, t_list **b)
{
	int size;
	
	size = ft_block_size(*a);




}
