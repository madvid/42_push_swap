/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md4 <md4@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 18:25:00 by mdavid            #+#    #+#             */
/*   Updated: 2020/05/10 12:23:01 by md4              ###   ########.fr       */
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

void	ft_stck_splt2b_v1(t_pp *data, t_info *info,
	int (*ft_order)(int*, int**, size_t))
{
	int			order;
	size_t		count;
	size_t		count_ra;

	count_ra = 0;
	count = 0;
	info->len2 = 0;
	ft_order(&order, data->stack1, info->len1);
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
	while (count_ra-- > 0)
		ft_rr_a(data, *info);
}

void	ft_stck_splt2b(t_pp *data, t_info *info,
	int (*ft_order)(int*, int**, size_t))
{
	int			order;
	size_t		count;
	size_t		count_p;
	size_t		count_ra;

	count_ra = 0;
	count = 0;
	count_p = 0;
	info->len2 = 0;
	ft_order(&order, data->stack1, info->len1);
	while (count < info->len1 + info->len2 && count_p < (info->len1 + info->len2 + 1) / 2)
	{
		if (*data->stack1[info->start1] < order)
		{
			ft_p_b(data, info);
			count_p++;
		}
		else
		{
			(count + 1 != info->len1 + info->len2) ? ft_r_a(data, *info) : 0;
			(count + 1 != info->len1 + info->len2) ? count_ra++ : 0;
		}
		count++;
	}
	while (count_ra-- > 0)
		ft_rr_a(data, *info);
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

void	ft_stck_splt2a_v1(t_pp *data, t_info *info,
	int (*ft_order)(int*, int**, size_t))
{
	int			order;
	size_t		count;
	size_t		count_rb;

	count_rb = 0;
	count = 0;
	info->len1 = 0;
	ft_order(&order, data->stack2, info->len2);
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
	while (count_rb-- > 0)
		ft_rr_b(data, *info);
}

void	ft_stck_splt2a(t_pp *data, t_info *info,
	int (*ft_order)(int*, int**, size_t))
{
	int			order;
	size_t		count;
	size_t		count_p;
	size_t		count_rb;

	count_rb = 0;
	count = 0;
	count_p = 0;
	info->len1 = 0;
	ft_order(&order, data->stack2, info->len2);
	while (count < info->len1 + info->len2 && count_p < (info->len1 + info->len2 + 1) / 2)
	{
		if (*data->stack2[info->start2] >= order)
		{
			ft_p_a(data, info);
			count_p++;
		}
		else
		{
			(count + 1 < info->len1 + info->len2) ? ft_r_b(data, *info) : 0;
			(count + 1 < info->len1 + info->len2) ? count_rb++ : 0;
		}
		count++;
	}
	while (count_rb-- > 0)
		ft_rr_b(data, *info);
}