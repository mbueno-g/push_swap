
#include "push_swap.h"
# include "Libft/libft.h"

int	ft_min(t_list *a)
{
	int		i;
	void	*m;
	int		pos;

	i = 1;
	pos = 0;
	m = a->content;
	while (a)
	{
		if (a->content < m)
		{
			m = a->content;
			i = pos + 1;
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

	i = 1;
	pos = 0;
	m = a->content;
	while (a)
	{
		if (a->content > m)
		{
			m = a->content;
			i = pos + 1;
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
		if (a->content > a->next->content)
			return (0);
		a = a->next;
	}
	return (1);
}
