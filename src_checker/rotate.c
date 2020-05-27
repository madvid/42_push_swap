/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md4 <md4@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 17:45:42 by mdavid            #+#    #+#             */
/*   Updated: 2020/05/27 00:33:12 by md4              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

/*
** FUNCTION: ft_bottom_up_rotate
** PARAMETERS:	t_pp *data:
**				t_info info:
** DESCRIPTION:
**	Rotate until ...........
*/

void	ft_bottom_up_rotate(t_pp *data, t_info info, char a_or_b)
{
	size_t		i;

	i = (a_or_b == 'a') ? info.len1 / 2 : info.len2 / 2;
	while (i > 0)
	{
		(a_or_b == 'a') ? ft_r_a(data, info) : ft_r_b(data, info);
		i--;
	}
}

/*
** FUNCTION: ft_rotate
** ARGUMENTS:	t_pp *data
** DESCRIPTION:
** 	Rotate all the elements up of the stack in data.
*/

void	ft_rotate(int **stack, t_info info, char a_or_b)
{
	int			*tmp;
	size_t		i;

	i = (a_or_b == 'a') ? info.start1 : info.start2;
	tmp = stack[i];
	while (i + 1 < info.tot_len)
	{
		stack[i] = stack[i + 1];
		i++;
	}
	stack[i] = tmp;
}

/*
** FUNCTION: ft_r_a
** ARGUMENTS:	t_pp *data1
** DESCRIPTION:
** 	Rotate all the elements up into the stack in data1 (via ft_rotate).
** 	Then it print 'ra'.
*/

int		ft_r_a(t_pp *data, t_info info)
{
	if (info.len1 <= 1)
		return (0);
	ft_rotate(data->stack1, info, 'a');
	return (1);
}

/*
** FUNCTION: ft_r_b
** ARGUMENTS:	t_pp *data2
** DESCRIPTION:
** 	Rotate all the elements up into the stack in data2 up (via ft_rotate).
** 	Then it print 'rb'.
*/

int		ft_r_b(t_pp *data, t_info info)
{
	if (info.len2 <= 1)
		return (0);
	ft_rotate(data->stack2, info, 'b');
	return (1);
}

/*
** FUNCTION: ft_rr
** ARGUMENTS:	t_pp *data1
** 				t_pp *data2
** DESCRIPTION:
** 	Rotate all the elements up into the stack in data1 and stack in data2
** 	(via ft_rotate).
** 	Then it print 'rr'.
*/

int		ft_rr(t_pp *data, t_info info)
{
	if (info.len1 > 1 && info.len2 > 1)
	{
		ft_rotate(data->stack2, info, 'b');
		ft_rotate(data->stack1, info, 'a');
		return (1);
	}
	return (0);
}
