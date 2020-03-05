/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 15:31:02 by mdavid            #+#    #+#             */
/*   Updated: 2020/03/04 20:12:42 by mdavid           ###   ########.fr       */
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
** 	Swap 1st and 2nd elements (in regard to the top) of data.stack if possible.
** RETURN:
** 	0 if the swap is not performed.
** 	1 if the swap is performed.
*/

int		ft_swap(t_pp *data)
{
	int		*tmp_addr;
	int		top;

	top = data->t_len - data->len;
	if (data->len <= 1)
		return (0);
	else
	{
		tmp_addr = data->stack[top];
		data->stack[top] = data->stack[top + 1];
		data->stack[top + 1] = tmp_addr;
		return (1);
	}
	return (0);
}

/*
** FUNCTION: ft_s_a
** ARGUMENTS:	t_pp *data1
** DESCRIPTION:
** 	Swap 1st and 2nd elements of data1.stack (via ft_swap) if possible.
** 	Then it print 'sa'.
** RETURN: None.
*/

void	ft_s_a(t_pp *data1)
{
	ft_swap(data1) ? write(1,"sa\n", 3) : 0;
}

/*
** FUNCTION: ft_s_b
** ARGUMENTS:	t_pp *data2
** DESCRIPTION:
** 	Swap 1st and 2nd elements of data2.stack (via ft_swap) if possible.
** 	Then it print 'sa'.
** RETURN: None.
*/

void	ft_s_b(t_pp *data2)
{
	ft_swap(data2) ? write(1,"sb\n", 3) : 0;
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