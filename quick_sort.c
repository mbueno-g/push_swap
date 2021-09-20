/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbueno-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 15:29:31 by mbueno-g          #+#    #+#             */
/*   Updated: 2021/09/20 17:34:18 by mbueno-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_create_array(t_list *a)
{
	int	*s;
	int	len;
	int	i;

	i = 0;
	len = ft_lstsize(a);
	s = (int *)malloc(len * sizeof(int));
	if (!s)
		return (NULL);
	while (a)
	{
		s[i] = *(int *)a->content;
		a = a->next;
		i++;
	}
	//NULL??
	return (s);
}

int	*ft_quick_sort(t_list *a)
{
	int	*s;
	int	i;
	int	j;
	int	len;
	int	aux;

	s = ft_create_array(a);
	i = 0;
	len = ft_lstsize(a);
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (s[i] > s[j])
			{
				aux = s[i];
				s[i] = s[j];
				s[j] = aux;
			}
			j++;
		}
		//printf("sort %d\n", s[i]);
		i++;
	}
	return (s);
}
