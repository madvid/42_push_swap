/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 18:25:00 by mdavid            #+#    #+#             */
/*   Updated: 2020/03/12 17:10:26 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** FUNCTION: ft_stack_split2b
** PARAMETERS:	t_pp *orig: data struct containing stack and more info.
**				t_pp *dest: data struct containing stack and more info.
**				int *ft_order: order function, return 0 or 1.
** DESCRIPTION:
** 	Split the orig->stack and put a part into dest->stack according to the
** 	order function
** 	within the stack.
*/

void	ft_stck_splt2b(t_pp *d_a, t_pp *d_b, t_info *info_a, t_info *info_b,
	int (*ft_order)(int*, int**, size_t))
{
	int			order;
	size_t		nb_elem;
	size_t		count;
	size_t		count_pb;

	count_pb = 0;
	count = 0;
	nb_elem = info_a->len;
	ft_order(&order, d_a->stack, info_a->len);
	while (count < nb_elem + 1)
	{
		if (*d_a->stack[info_a->start] < order)
		{
			ft_p_b(d_a, d_b, info_a, info_b);
			count_pb++;
		}
		else
		{
			ft_r_a(d_a, *info_a);
		}
		count++;
	}
	info_b->len = count_pb;
}

/*
** FUNCTION: ft_stack_split2b
** PARAMETERS:	t_pp *orig: data struct containing stack and more info.
**				t_pp *dest: data struct containing stack and more info.
**				int *ft_order: order function, return 0 or 1.
** DESCRIPTION:
** 	Split the orig->stack and put a part into dest->stack according to the
** 	order function
** 	within the stack.
*/

void	ft_stck_splt2a(t_pp *d_a, t_pp *d_b, t_info *info_a, t_info *info_b,
	int (*ft_order)(int*, int**, size_t))
{
	int			order;
	size_t		nb_elem;
	size_t		count;
	size_t		count_pa;

	count_pa = 0;
	count = 0;
	nb_elem = info_b->len;
	ft_order(&order, d_b->stack, info_b->len);
	while (count < info_b->len + 1)
	{
		if (*d_b->stack[info_b->start] > order)
		{
			ft_p_a(d_a, d_b, info_a, info_b);
			count_pa++;
		}
		else
			ft_r_b(d_b, *info_b);
		count++;
	}
	info_a->len = count_pa;
}