#include "push_swap.h"

t_list	*ft_lstnew_struct(void *newcontent, size_t size)
{
		t_list *new;
		void	*content;

		new = malloc(sizeof(t_list));
		if (!new)
				return (NULL);
		content = malloc(size);
		if (!content)
		{
				free(new);
				return (NULL);
		}
		ft_memcpy(content, newcontent, size);
		new->content = content;
		new->next = NULL;
		return (new);
}
