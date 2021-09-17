/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbueno-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 15:12:08 by mbueno-g          #+#    #+#             */
/*   Updated: 2021/09/17 19:19:50 by mbueno-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "Libft/libft.h"

//int	st_printstack_ab(t_list *a, t_list *b);

void	ft_print_error(char *m)
{
	//liberar t_stack a
	printf("Error\n");
	printf("%s\n", m);
	exit(0);
}

/* Add the argument to the stack a */
void	ft_add(t_list **a, char	*argv)
{
	t_list	*aux;
	int			n;

	aux = *a;
	/*By changing in t_list int content to void *content there`s no need of using atoi*/
	//Añadir limites de enteros y cuidado si entra en un int
	n = ft_atoi(argv);
	while (aux)
	{
		if (*(int *)aux->content == n)
			ft_print_error("Duplicate");
		aux = aux->next;
	}
	ft_lstadd_back(a, ft_lstnew_struct((void *)&n, sizeof(int)));
	//st_printstack_ab(*a,NULL);
}

/* Check if the argument is a number*/
void	ft_check(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		//printf("argv %c\n", argv[i]);
		if (!ft_strchr("0123456789+-", argv[0]))
			ft_print_error("i = 0");
		if (i != 0 && !ft_strchr("0123456789", argv[i]))
			ft_print_error("i!=0");
		i++;
	}
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
			//printf("ORIGINAL\n");
			//st_printstack_ab(*a, *b, 'd');
			ft_index(a, s);
			printf("INDEX\n");
			st_printstack_ab(*a, *b, 'd');
			if (len > 3 && len <= 5)
				ft_sort_four_five(a, b);
			else
				ft_big_sort(a,b);
		}
	}
	printf("SORTED\n");
	st_printstack_ab(*a, *b, 'd');
	printf("is it sorted? %d\n", ft_issorted(*a));
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int		i;
	char	**tab;

	b = NULL;
	a = NULL;
	i = 1;
	while (i <= argc - 1)
	{
		tab = ft_split(argv[i], ' ');
		while(*tab)
		{
			ft_check(*tab);
			ft_add(&a, *tab);
			tab++;
		}
		i++;
	}
	if (argc >= 2)
		ft_push_swap(&a, &b);
	return (0);
}
