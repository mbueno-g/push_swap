/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbueno-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 10:46:49 by mbueno-g          #+#    #+#             */
/*   Updated: 2021/09/17 12:59:47 by mbueno-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int    ft_in_pos(t_list *b, int len)
{
    int    aux;
    int    i;

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

int	ft_next_in_a(t_list *b, int len, int i)
{
	int    len_b;
    int aux;
    int    j;

    len_b = ft_lstsize(b);
    aux = len_b - len;
    j = 0;
    while (aux)
    {
        if (((*(int *)b->content >> i) & 1) == 0)
            j++;
        else
            j = 0;
        b = b->next;
        aux--;
    }
    return (j);
}

void    ft_big_sort(t_list **a, t_list **b)
{
    int    len_a;
    int    len_b;
    int    max_bits;
    int    j;
    int    i;

    len_a = ft_lstsize(*a);
    max_bits = 0;
    while((len_a >> max_bits) != 0)
        max_bits++;
    i = 0;
    while (i < max_bits)
    {
        j = 0;
        while(j <= len_a - 1 && !ft_issorted(*a))
        {
            if (((*(int *)(*a)->content >> i) & 1) == 0) // && !ft_issorted(*a))
            {
               if (j != len_a - 1)
                    ft_push(a, b, 'b');
                /*if (*(int *)(*a)->content == 0)
                {
                    ft_push(a, b, 'b');
                    ft_rotate(b, 'b');
                }*/

            }
            else
                ft_rotate(a, 'a');
           	//printf("xxxxxx %d\n", j);
			//st_printstack_ab(*a, *b, 'b');
            j++;
        }
        printf("send to b %d\n", i);
        st_printstack_ab(*a, *b, 'b');
		len_b = ft_lstsize(*b);
        if (i != max_bits - 1)
		{
           len_b = ft_in_pos(*b, len_b);
		   //len_b -= ft_next_in_a(*b, len_b, i + 1);
		}
		printf("LEN %d\n", len_b);
        while(len_b--)
        {
            ft_push(b, a, 'a');
        }
		printf("all in a\n");
        st_printstack_ab(*a, *b,'b');
		i++;
		len_a = ft_lstsize(*a);
    }
}
