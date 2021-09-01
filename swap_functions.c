
#include "push_swap.h"
#include "Libft/libft.h"

void	ft_swap(t_list **src, char s)
{
	void	*aux;

	aux = (*src)->content;
	(*src)->content = (*src)->next->content;
	(*src)->next->content = aux;
	if (s == 'a')
		write(1, "sa\n", 3);
	else if (s == 'b')
		write(1, "sb\n", 3);
}

void	ft_ss_swap(t_list **src)
{
	ft_swap(src, 'x');
	ft_swap(src, 'x');
	write(1, "ss\n", 3);
}
