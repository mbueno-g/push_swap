
#include "push_swap.h"
# include "Libft/libft.h"

int	ft_min(t_list *a)
{
	int		i;
	void	*m;
	int		pos;

	i = 0;
	pos = 0;
	m = a->content;
	while (a)
	{
		if (*(int *)a->content < *(int *)m)
		{
			m = a->content;
			i = pos;
		}
		a = a->next;
		pos++;
	}
	return (i);
}

int	ft_max(t_list *a)
{
	int		i;
	void	*m;
	int		pos;

	i = 0;
	pos = 0;
	m = a->content;
	while (a)
	{
		if (*(int *)a->content > *(int *)m)
		{
			m = a->content;
			i = pos;
		}
		a = a->next;
		pos++;
	}
	return (i);
}

int	ft_issorted(t_list *a)
{
	while (a->next)
	{
		if (*(int *)a->content > *(int *)a->next->content)
			return (0);
		a = a->next;
	}
	return (1);
}
