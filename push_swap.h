/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbueno-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 11:04:48 by mbueno-g          #+#    #+#             */
/*   Updated: 2021/09/21 18:50:28 by mbueno-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "Libft/libft.h"

/* POSSIBLE MOVES */
void	ft_push(t_list **src, t_list **dst, char p);
void	ft_del(t_list **src);
void	ft_swap(t_list **src, char s);
void	ft_ss_swap(t_list **src);
void	ft_rotate(t_list **src, char r);
void	ft_rr_rotate(t_list **src);
void	ft_reverse_rotate(t_list **src, char rr);
void	ft_rrr_reverse_rotate(t_list **src);

/* SORT CASES */
void	ft_sort_three(t_list **a);
void	ft_sort_four_five(t_list **a, t_list **b);
void	ft_big_sort(t_list **a, t_list **b);

/* UTILS  */
int		ft_issorted(t_list *a);
int		ft_min(t_list *a);
int		ft_max(t_list *a);
int		*ft_create_array(t_list *a);
int		*ft_quick_sort(t_list *a);
void	ft_index(t_list **a, int *s);

t_list	*ft_lstnew_struct(void *content, size_t size);
int		st_printstack_ab(t_list *a, t_list *b, char m);

#endif
