
#include "push_swap.h"

int	ft_putnchar_fd(char c, int fd, int n)
{
	int	count;

	count = 0;
	while (n-- > 0)
		count += (int)write(fd, &c, 1);
	return (count);
}

t_list	*st_printstack(t_list *stack)
{
	if (stack)
	{
		ft_putnbr_fd(*(int *)stack->content, 1);
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

int	st_printstack_ab(t_list *a, t_list *b)
{
	/*if (!a && !b)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}*/
	write(1, "\n", 1);
	while (a || b)
	{
		a = st_printstack(a);
		b = st_printstack(b);
		ft_putchar_fd('\n', 1);
	}
	ft_putnchar_fd('-', 1, 10);
	ft_putstr_fd("\t", 1);
	ft_putnchar_fd('-', 1, 10);
	ft_putstr_fd("\na\t\tb\n\n", 1);
	return (0);
}
