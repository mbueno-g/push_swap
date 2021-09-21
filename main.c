/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbueno-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 15:12:08 by mbueno-g          #+#    #+#             */
/*   Updated: 2021/09/21 18:53:20 by mbueno-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "Libft/libft.h"

void	ft_print_error(t_list **a)
{
	ft_lstclear(a, free);
	printf("Error\n");
	exit(0);
}

/* Add the argument to the stack a */
void	ft_add(t_list **a, char	*argv)
{
	t_list		*aux;
	long int	n;

	aux = *a;
	n = ft_atoi(argv);
	if (n >= INT_MAX || n <= INT_MIN)
		ft_print_error(a);
	while (aux)
	{
		if (*(int *)aux->content == n)
			ft_print_error(a);
		aux = aux->next;
	}
	ft_lstadd_back(a, ft_lstnew_struct((void *)&n, sizeof(int)));
}

/* Check if the argument is a number*/
void	ft_check(t_list **a, char *argv)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(argv);
	while (argv[i])
	{
		if (!ft_strchr("0123456789+-", argv[0]))
			ft_print_error(a);
		if (ft_strchr("+-", argv[0]) \
				&& (!ft_strchr("0123456789", argv[1]) || len == 1))
			ft_print_error(a);
		if (i != 0 && !ft_strchr("0123456789", argv[i]))
			ft_print_error(a);
		i++;
	}
	ft_add(a, argv);
}

/* Depending on the size of stack a applies a different
sorting algorithm */
void	ft_push_swap(t_list **a, t_list **b)
{
	int	len;
	int	*s;

	len = ft_lstsize(*a);
	if (!ft_issorted(*a))
	{
		if (len == 2)
		{
			if (*(int *)(*a)->content > *(int *)(*a)->next->content)
				ft_swap(a, 'a');
		}
		else if (len == 3)
			ft_sort_three(a);
		else
		{
			s = ft_quick_sort(*a);
			ft_index(a, s);
			free(s);
			if (len > 3 && len <= 5)
				ft_sort_four_five(a, b);
			else
				ft_big_sort(a, b);
		}
	}
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int		i;
	char	**tab;
	char	**aux;

	b = NULL;
	a = NULL;
	i = 0;
	while (++i <= argc - 1)
	{
		tab = ft_split(argv[i], ' ');
		aux = tab;
		while (*tab)
		{
			ft_check(&a, *tab);
			free(*(tab++));
		}
		free(aux);
	}
	if (argc >= 2)
		ft_push_swap(&a, &b);
	ft_lstclear(&a, free);
	ft_lstclear(&b, free);
	return (0);
}
