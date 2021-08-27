
#include "push_swap.h"
#include "Libft/libft.h"

void	ft_print_error(char *m)
{
	//liberar t_stack a
	printf("Error\n");
	printf("%s\n", m);
	exit(0);
}

void	ft_add(t_list **a, char	*argv)
{
	t_list	*aux;
	int		n;

	aux = *a;
	n = ft_atoi(argv);
	while (aux)
	{
		if (aux->content == n)
			ft_print_error("Duplicate");
		aux = aux->next;
	}
	ft_lstadd_back(a, ft_lstnew(n));
}

void	ft_check(char *argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (!ft_strchr("0123456789+-", argv[0]))
			ft_print_error("i = 0");
		if (i != 0 && !ft_strchr("0123456789", argv[i]))
			ft_print_error("i!=0");
		i++;
	}
}

void	ft_push_swap(t_list **a, t_list **b)
{
	int	len;

	len = ft_lstsize(*a);
	if (!ft_issorted(*a))
	{
		if (len == 2)
		{
			if ((*a)->content > (*a)->next->content)
				ft_swap(a, 'a');
		}
		else if (len == 3)
			ft_sort_three(a);
		else if (len > 3)
			ft_sort_four_five(a, b);
		//else if (len <= 40)
	}
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	int		i;

	b = NULL;
	a = NULL;
	i = 1;
	while (i <= argc - 1)
	{
		ft_check(argv[i]);
		ft_add(&a, argv[i]);
		i++;
	}
	if (argc >= 3)
		ft_push_swap(&a, &b);
	return (0);
}
