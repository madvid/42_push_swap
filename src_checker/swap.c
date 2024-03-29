/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md4 <md4@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 15:31:02 by mdavid            #+#    #+#             */
/*   Updated: 2020/05/28 01:20:47 by md4              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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

void	special_swap(t_pp *data, int i, int j)
{
	int		*tmp_addr;

	tmp_addr = data->stack1[i];
	data->stack1[i] = data->stack2[j];
	data->stack1[j] = tmp_addr;
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

int		ft_swap(int **data, t_info info, char a_or_b)
{
	int		*tmp_addr;
	int		top;

	top = (a_or_b == 'a') ? info.start1 : info.start2;
	if (info.len1 <= 1)
		return (0);
	else
	{
		tmp_addr = data[top];
		data[top] = data[top + 1];
		data[top + 1] = tmp_addr;
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

int		ft_s_a(t_pp *data, t_info info)
{
	int		err;

	err = 0;
	err = ft_swap(data->stack1, info, 'a');
	return (err);
}

/*
** FUNCTION: ft_s_b
** ARGUMENTS:	t_pp *data2
** DESCRIPTION:
** 	Swap 1st and 2nd elements of data2.stack (via ft_swap) if possible.
** 	Then it print 'sa'.
** RETURN: None.
*/

int		ft_s_b(t_pp *data, t_info info)
{
	int		err;

	err = 0;
	err = ft_swap(data->stack2, info, 'b');
	return (err);
}

/*
** FUNCTION: ft_swap_s
** ARGUMENTS:	t_pp *data
** DESCRIPTION:
** 	...
** RETURN: None.
*/

int		ft_swap_ss(t_pp *data, t_info info)
{
	int		err;

	err = 0;
	err = ft_swap(data->stack1, info, 'a');
	if (err == 0)
		return (0);
	err = ft_swap(data->stack2, info, 'b');
	if (err == 0)
	{
		ft_swap(data->stack1, info, 'a');
		return (0);
	}
	return (1);
}
