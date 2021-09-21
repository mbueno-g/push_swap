/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbueno-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/21 15:48:00 by mbueno-g          #+#    #+#             */
/*   Updated: 2021/09/21 18:49:51 by mbueno-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "Libft/libft.h"

void	ft_del(t_list **src)
{
	t_list	*aux;

	aux = *src;
	*src = aux->next;
	free(aux->content);
	free(aux);
}

void	ft_push(t_list **src, t_list **dst, char p)
{
	if (*dst)
		ft_lstadd_front(dst, ft_lstnew_struct((*src)->content, sizeof(int)));
	else
		*dst = ft_lstnew_struct((*src)->content, sizeof(int));
	ft_del(src);
	if (p == 'a')
		write(1, "pa\n", 3);
	else if (p == 'b')
		write(1, "pb\n", 3);
}
