/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbueno-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 15:57:54 by mbueno-g          #+#    #+#             */
/*   Updated: 2021/09/16 18:11:00 by mbueno-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
# include "Libft/libft.h"

int	ft_min(t_list *a)
{
	int		i;
	void	*m;
	int		pos;

	i = 0;
	pos = 0;
	m = a->content;
	while (a)
	{
		if (*(int *)a->content < *(int *)m)
		{
			m = a->content;
			i = pos;
		}
		a = a->next;
		pos++;
	}
	return (i);
}

int	ft_max(t_list *a)
{
	int		i;
	void	*m;
	int		pos;

	i = 0;
	pos = 0;
	m = a->content;
	while (a)
	{
		if (*(int *)a->content > *(int *)m)
		{
			m = a->content;
			i = pos;
		}
		a = a->next;
		pos++;
	}
	return (i);
}

int	ft_issorted(t_list *a)
{
	while (a->next)
	{
		if (*(int *)a->content > *(int *)a->next->content)
			return (0);
		a = a->next;
	}
	return (1);
}

void	ft_index(t_list	**a, int *s)
{
	int	i;
	int	len;
	t_list	*aux;
	
	aux = *a;
	len = ft_lstsize(*a);
	while (aux)
	{
		i = 0;
		while (i < len)
		{
			//printf("content %d, copia %d, index %d\n", *(int *)(*a)->content, s[i], i);
			if (s[i] == *(int *)aux->content)
			{
				//printf("content %d, copia %d, index %d\n", *(int *)(*a)->content, s[i], i);
				*(int *)aux->content = i;
				break ; //por alguna razon entra con 1 4 -4 -1
			}
			i++;
		}
		//printf("index %d\n", *(int *)aux->content);
		aux = aux->next;
	}
}
