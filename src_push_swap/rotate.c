/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md4 <md4@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 17:45:42 by mdavid            #+#    #+#             */
/*   Updated: 2020/05/13 16:52:02 by md4              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

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

void	ft_r_a(t_pp *data, t_info info)
{
	if (info.len1 == 0)
		return ;
	ft_rotate(data->stack1, info, 'a');
	ft_add_actions(data, "ra\n");
	data->nb_actions += 1;
}

/*
** FUNCTION: ft_r_b
** ARGUMENTS:	t_pp *data2
** DESCRIPTION:
** 	Rotate all the elements up into the stack in data2 up (via ft_rotate).
** 	Then it print 'rb'.
*/

void	ft_r_b(t_pp *data, t_info info)
{
	if (info.len2 == 0)
		return ;
	ft_rotate(data->stack2, info, 'b');
	ft_add_actions(data, "rb\n");
	data->nb_actions += 1;
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

void	ft_rr(t_pp *data, t_info info)
{
	ft_rotate(data->stack2, info, 'b');
	ft_rotate(data->stack1, info, 'a');
	ft_add_actions(data, "rr\n");
	data->nb_actions += 1;
}
