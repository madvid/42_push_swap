/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_split.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 18:25:00 by mdavid            #+#    #+#             */
/*   Updated: 2020/03/05 19:06:09 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

/*
** FUNCTION: ft_stack_split
** ARGUMENTS: t_pp *data: a stack with it informations
** DESCRIPTION:
** 	Split virtually the stack in half using pointers on specific address
** 	within the stack.
*/

void	ft_stack_split(t_pp *data)
{
	int		**start1;
	int		**start2;
	int		**end1;
	int		**end2;
	size_t	half;

	if (data->t_len <= 1 || data->len <= 1)
		return ;
	half = data->t_len - (data->len / 2);
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
	// printf("start1 = %p\nend1 =   %p\n", start1, end1);
	// printf("start2 = %p\nend2 =   %p\n", start2, end2);
}
