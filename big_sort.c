/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbueno-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 10:46:49 by mbueno-g          #+#    #+#             */
/*   Updated: 2021/09/20 18:59:30 by mbueno-g         ###   ########.fr       */
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
	len = 0;
    //aux = len_b - 1;
    aux = len;
	j = 0;
    while (aux)
    {
      	//printf("aux %d, j %d, i %d, content %d\n", aux, j, i, *(int *)b->content);
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
	int		on;
	int		len;
	int		ok;
	t_list	*aux;

	on = 0;
	ok = 1;
    len_a = ft_lstsize(*a);
    max_bits = 0;
    while((len_a >> max_bits) != 0)
        max_bits++;
    i = 0;
	len = 0;
	len_b = ft_lstsize(*b);
    while (i <=  max_bits - 1)
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
			{
				if (ok)
					len = ft_lstsize(*b);
				ok = 0;
                len_b = ft_lstsize(*b);
				//printf("content %d, len %d, len_b %d\n", *(int *)(*a)->content, len, len_b);
                aux = ft_lstlast(*a);
				while (len_b == len && (*(int *)(*a)->content == len || *(int *)aux->content == len) && !ft_issorted(*a))
				{
					if (*(int *)(*a)->content == len)
						ft_push(a, b, 'b');
					else if (*(int *)aux->content == len)
					{
						ft_reverse_rotate(a, 'a');
						ft_push(a, b, 'b');
					}
					//st_printstack_ab(*a, *b, 'b');
					aux = ft_lstlast(*a);
					len++;
					len_b++;
				}
            	if (!ft_issorted(*a))
					ft_rotate(a, 'a');
			}
           	//printf("xxxxxx %d\n", j);
			//st_printstack_ab(*a, *b, 'b');
			len = len_b - ft_in_pos(*b, len_b);
			//printf("len %d, len_b %d\n", len, len_b);
			j++;
        }
		if (on)
		{
        	printf("send to b %d\n", i);
        	st_printstack_ab(*a, *b, 'b');
		}
		len_b = ft_lstsize(*b);
		//printf("max_bits %d, i %d\n", max_bits, i);
        if (i < (max_bits - 1))
		{
			len_b = ft_in_pos(*b, len_b);
			len = len_b;
		}
		if (i <  max_bits - 2)
		{
		  // printf("len_b %d\n", len_b);
		   len_b -= ft_next_in_a(*b, len_b, i + 1);
		}
		if (on)
			printf("LEN %d\n", len_b);
        while(len_b--)
        {
            ft_push(b, a, 'a');
        }
		if (on)
		{
			printf("all in a\n");
        	st_printstack_ab(*a, *b,'b');
		}
		i++;
		len_a = ft_lstsize(*a);
    }
}
