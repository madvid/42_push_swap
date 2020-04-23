/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md4 <md4@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 18:25:00 by mdavid            #+#    #+#             */
/*   Updated: 2020/04/22 21:31:16 by md4              ###   ########.fr       */
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

void	ft_head_back_to_top(t_pp *data, t_info *info, size_t rot_rev,
		char a_or_b)
{
	void	(*ft_rr)(t_pp*, t_info);
	void	(*ft_r)(t_pp*, t_info);
	size_t	len;

	ft_r = (a_or_b == 'a') ? &ft_r_a : &ft_r_b;
	ft_rr = (a_or_b == 'a') ? &ft_rr_a : &ft_rr_b;
	len = (a_or_b == 'a') ? info->len1 : info->len2;
	if ((len / 2) > rot_rev)
		while (rot_rev < len)
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
		if (*data->stack1[info->start1] < order)
			ft_p_b(data, info);
		else
		{
			(count + 1 != info->len1 + info->len2) ? ft_r_a(data, *info) : 0;
			(count + 1 != info->len1 + info->len2) ? count_ra++ : 0;
		}
		count++;
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

void	ft_stck_splt2a(t_pp *data, t_info *info,
	int (*ft_order)(int*, int**, size_t))
{
	int			order;
	size_t		count;
	size_t		count_rb;

	count_rb = 0;
	count = 0;
	info->len1 = 0;
	ft_order(&order, data->stack2, info->len2);
	printf("valeur de order = %d\n", order);
	while (count < info->len1 + info->len2)
	{
		if (*data->stack2[info->start2] >= order)
			ft_p_a(data, info);
		else
		{
			(count + 1 < info->len1 + info->len2) ? ft_r_b(data, *info) : 0;
			(count + 1 < info->len1 + info->len2) ? count_rb++ : 0;
		}
		count++;
	}
}
