/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 18:25:00 by mdavid            #+#    #+#             */
/*   Updated: 2020/03/11 21:43:43 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

/*
** FUNCTION: ft_stack_split
** PARAMETERS:	t_pp *orig: data struct containing stack and more info.
**				t_pp *dest: data struct containing stack and more info.
**				int *ft_order: order function, return 0 or 1.
** DESCRIPTION:
** 	Split the orig->stack and put a part into dest->stack according to the
** 	order function
** 	within the stack.
*/

void	ft_stack_split(t_pp *data1, t_pp *data2, t_info info1 , t_info info2,
	int (*ft_order)(int, int))
{
	int		**start1;
	int		**start2;
	int		**end1;
	int		**end2;
	size_t	half;

	if (info1.tot_len < 2 || (info1.len + info2.len > info2.tot_len))
		return ;
	half = info1.tot_len - (info1.len / 2);
	start1 = &(data->stack[data->t_len - data->len]);
	end2 = &(data->stack[data->t_len]);
	if ((data->len % 2) == 0)
	{
		start2 = &(data->stack[half]);
		end1 = &(data->stack[half - 1]);
	}
	else
	{
		start2 = &(data->stack[half + 1]);
		end1 = &(data->stack[half]);
	}
}
