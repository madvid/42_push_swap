/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md4 <md4@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 18:25:00 by mdavid            #+#    #+#             */
/*   Updated: 2020/04/19 19:42:00 by md4              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Function: ft_head_back_to_top
** PARAMETERS:	t_pp *data: data struct containing stack of number.
**				t_info *info: data struct containing stack info.
**				int rot_rev: number of rotations performed during split.
**				a_or_b: tag to know which stack is treating.
** DESCRIPTION:
** 	Performs reverse rotation or rotatio n to bring back number initially on
**	top of the stack.
*/

void	ft_head_back_to_top(t_pp *data, t_info *info, size_t rot_rev, char a_or_b)
{
	void	(*ft_rr)(t_pp*,t_info);
	void	(*ft_r)(t_pp*,t_info);

	ft_r = (a_or_b == 'a') ? &ft_r_a : &ft_r_b;
	ft_rr = (a_or_b == 'a') ? &ft_rr_a : &ft_rr_b;
	if ((info->len / 2) > rot_rev)
		while (rot_rev < info->len)
		{
			ft_r(data, *info);
			rot_rev++;
		}
	else
		while (rot_rev > 0)
		{
			ft_rr(data, *info);
			rot_rev--;
		}
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

void	ft_stck_splt2b(t_pp *data, t_info *info,
	int (*ft_order)(int*, int**, size_t))
{
	int			order;
	size_t		count;
	size_t		count_ra;

	count_ra = 0;
	count = 0;
	info->len2 = 0;
	ft_order(&order, data->stack1, info->len1);
	printf("valeur de order = %d\n", order);
	while (count < info->len1 + info->len2)
	{
		if (*d_a->stack[info_a->start] < order)
			ft_p_b(d_a, d_b, info_a, info_b);
		else
		{
			(count + 1 != info_a->len + info_b->len) ?  ft_r_a(d_a, *info_a) : 0;
			(count + 1 != info_a->len + info_b->len) ? count_ra++ : 0;
		}
		count++;
	}
	//ft_head_back_to_top(d_a, info_a, count_ra, 'a');
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
	size_t		count;
	size_t		count_rb;

	count_rb = 0;
	count = 0;
	info_a->len = 0;
	ft_order(&order, d_b->stack, info_b->len);
	printf("valeur de order = %d\n", order);
	while (count < info_a->len + info_b->len)
	{
		if (*d_b->stack[info_b->start] >= order)
			ft_p_a(d_a, d_b, info_a, info_b);
		else
		{
			(count + 1 < info_a->len + info_b->len) ? ft_r_b(d_b, *info_b) : 0;
			(count + 1 < info_a->len + info_b->len) ? count_rb++ : 0;
		}
		count++;
	}
	//ft_head_back_to_top(d_b, info_b, count_rb, 'b');
}