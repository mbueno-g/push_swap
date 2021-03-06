/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbueno-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 15:57:54 by mbueno-g          #+#    #+#             */
/*   Updated: 2021/09/21 18:51:29 by mbueno-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "Libft/libft.h"

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
	int		i;
	int		len;
	t_list	*aux;

	aux = *a;
	len = ft_lstsize(*a);
	while (aux)
	{
		i = 0;
		while (i < len)
		{
			if (s[i] == *(int *)aux->content)
			{
				ft_memcpy(aux->content, (void *) &i, sizeof(int));
				break ;
			}
			i++;
		}
		aux = aux->next;
	}
}
