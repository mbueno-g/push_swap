/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbueno-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 10:52:11 by mbueno-g          #+#    #+#             */
/*   Updated: 2021/09/17 13:54:35 by mbueno-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_putnchar_fd(char c, int fd, int n)
{
	int	count;

	count = 0;
	while (n-- > 0)
		count += (int)write(fd, &c, 1);
	return (count);
}

t_list	*st_printstack(t_list *stack, char m)
{
	int b;

	b = 0;
	if (stack)
	{
		if (m == 'b')
		{
			if ((*(int *)stack->content >> b) == 0)
				ft_putnbr_fd(0,1);
			else
			{
				while ((*(int *)stack->content >> b) != 0)
				{
					if (((*(int *)stack->content >> b) & 1) == 0)
						ft_putnbr_fd(0, 1);
					else
						ft_putnbr_fd(1, 1);
					b++;
				}
			}
		}
		else
			ft_putnbr_fd(*(int *)stack->content,1);
		ft_putnchar_fd('\t', 1, 2);
		stack = stack->next;
	}
	else
	{
		ft_putchar_fd('.', 1);
		ft_putnchar_fd('\t', 1, 2);
	}
	return (stack);
}

int	st_printstack_ab(t_list *a, t_list *b, char m)
{
	/*if (!a && !b)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}*/
	write(1, "\n", 1);
	while (a || b)
	{
		a = st_printstack(a, m);
		b = st_printstack(b, m);
		ft_putchar_fd('\n', 1);
	}
	ft_putnchar_fd('-', 1, 10);
	ft_putstr_fd("\t", 1);
	ft_putnchar_fd('-', 1, 10);
	ft_putstr_fd("\na\t\tb\n\n", 1);
	return (0);
}
