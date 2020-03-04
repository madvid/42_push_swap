/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 15:31:02 by mdavid            #+#    #+#             */
/*   Updated: 2020/03/04 17:03:51 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** FUNCTION:	pp_swap
** ARGUMENTS:	t_pp data1
** 				t_pp data2
** 				int i: index for data1.stack
** 				int j: index for data2.stack
** DESCRIPTION:
** 		Swap the ith element of data1.stack with th jth of data2.stack.
** RETURN:
** 	None.
*/

void	special_swap(t_pp *data1, t_pp *data2, int i, int j)
{
	int		*tmp_addr;

	tmp_addr = data1->stack[i];
	data1->stack[i] = data2->stack[j];
	data2->stack[j] = tmp_addr;
}

/*
** FUNCTION: ft_swap
** ARGUMENTS:	t_pp *data
** DESCRIPTION:
** 	...
** RETURN: None.
*/

void	ft_swap(t_pp *data)
{
	int		*tmp_addr;
	int		top;

	top = data->t_len - data->len;
	if (data->len <= 1)
		return;
	else
	{
		tmp_addr = data->stack[top];
		data->stack[top] = data->stack[top + 1];
		data->stack[top + 1] = tmp_addr;
	}
}

/*
** FUNCTION: ft_swap_s
** ARGUMENTS:	t_pp *data
** DESCRIPTION:
** 	...
** RETURN: None.
*/

void	ft_swap_ss(t_pp *data1, t_pp *data2)
{
	ft_swap(data1);
	ft_swap(data2);
}