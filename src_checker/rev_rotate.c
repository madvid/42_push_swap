/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md4 <md4@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 19:56:14 by mdavid            #+#    #+#             */
/*   Updated: 2020/05/27 00:58:23 by md4              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*
** FUNCTION: ft_rev_rotate
** ARGUMENTS:	t_pp *data
** DESCRIPTION:
** 	Rotate all the elements down of the stack in data.
*/

void	ft_rev_rotate(int **stack, t_info info, char a_or_b)
{
	int			*tmp;
	size_t		i;
	size_t		start;

	i = info.tot_len - 1;
	start = (a_or_b == 'a') ? info.start1 : info.start2;
	tmp = stack[info.tot_len - 1];
	while (i > start)
	{
		stack[i] = stack[i - 1];
		i--;
	}
	stack[i] = tmp;
}

/*
** FUNCTION: ft_rr_a
** ARGUMENTS:	t_pp *data1
** DESCRIPTION:
** 		Rotate all the elements down into the stack1 (via ft_rev_rotate).
** 	Return:
**		1: if reverse rotation has been performed
**		0: if reverse rotation has not been performed
*/

int		ft_rr_a(t_pp *data, t_info info)
{
	if (info.len1 <= 1)
		return (0);
	ft_rev_rotate(data->stack1, info, 'a');
	return (1);
}

/*
** FUNCTION: ft_rr_b
** ARGUMENTS:	t_pp *data2
** DESCRIPTION:
** 		Rotate all the elements down into the stack2 (via ft_rev_rotate).
** 	Return:
**		1: if reverse rotation has been performed
**		0: if reverse rotation has not been performed
*/

int		ft_rr_b(t_pp *data, t_info info)
{
	if (info.len2 <= 1)
		return (0);
	ft_rev_rotate(data->stack2, info, 'b');
	return (1);
}

/*
** FUNCTION: ft_rrr
** ARGUMENTS:	t_pp *data1
** 				t_pp *data2
** DESCRIPTION:
** 	Rotate all the elements down into the stack in data1 and stack in data2
** 	(via ft_rev_rotate).
** 	Then it print 'rrr'.
*/

int		ft_rrr(t_pp *data, t_info info)
{
	if (info.len1 > 1 && info.len2 > 1)
	{
		ft_rev_rotate(data->stack2, info, 'b');
		ft_rev_rotate(data->stack1, info, 'a');
		return (1);
	}
	return (0);
}
