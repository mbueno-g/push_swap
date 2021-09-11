
#include "push_swap.h"
#include "Libft/libft.h"

void	ft_rotate(t_list **src, char r)
{
	ft_lstadd_back(src, ft_lstnew_struct((*src)->content, sizeof(int)));
	ft_del(src);
	if (r == 'a')
		write(1, "ra\n", 3);
	else if (r == 'b')
		write(1, "rb\n", 3);
}

void	ft_rr_rotate(t_list **src)
{
	ft_rotate(src, 'x');
	ft_rotate(src, 'x');
	write(1, "rr\n", 3);
}

void	ft_reverse_rotate(t_list **src, char rr)
{
	t_list	*aux;
	int		i;

	aux = *src;
	i = 1;
	//para que en la ultima iteración tenga el último en vez de uno que no existe
	while (aux->next->next)
	{
		aux = aux->next;
		i++;
	}
	ft_lstadd_front(src, ft_lstnew_struct(aux->next->content, sizeof(int)));
	free(aux->next);
	aux->next = NULL; //¿Por que no me deja acerlo con aux = NULL;?
	if (rr == 'a')
		write(1, "rra\n", 4);
	else if (rr == 'b')
		write(1, "rrb\n", 4);
}

void	ft_rrr_reverse_rotate(t_list **src)
{
	ft_reverse_rotate(src, 'x');
	ft_reverse_rotate(src, 'x');
	write(1, "rrr\n", 4);
}
