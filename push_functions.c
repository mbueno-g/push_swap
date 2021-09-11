
#include "push_swap.h"
#include "Libft/libft.h"

void	ft_del(t_list **src)
{
	t_list	*aux;

	aux = *src;
	*src = aux->next;
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
