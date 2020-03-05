/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 19:56:14 by mdavid            #+#    #+#             */
/*   Updated: 2020/03/05 14:51:08 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** FUNCTION: ft_rev_rotate
** ARGUMENTS:	t_pp *data
** DESCRIPTION:
** 	Rotate all the elements down of the stack in data.
*/

void	ft_rev_rotate(t_pp *data)
{
	int			*tmp;
	size_t		i;

	i = data->t_len;
	tmp = data->stack[data->t_len - 1];
	while (i > data->t_len - data->len)
	{
		data->stack[i] = data->stack[i - 1];
		i--;
	}
	data->stack[i] = tmp;
}

/*
** FUNCTION: ft_rr_a
** ARGUMENTS:	t_pp *data1
** DESCRIPTION:
** 	Rotate all the elements down into the stack in data1 (via ft_rev_rotate).
** 	Then it print 'rra'.
*/

void	ft_rr_a(t_pp *data1)
{
	ft_rev_rotate(data1);
	write(1,"rra\n", 4);
}

/*
** FUNCTION: ft_rr_b
** ARGUMENTS:	t_pp *data2
** DESCRIPTION:
** 	Rotate all the elements down into the stack in data2 (via ft_rev_rotate).
** 	Then it print 'rrb'.
*/

void	ft_rr_b(t_pp *data2)
{
	ft_rev_rotate(data2);
	write(1,"rrb\n", 4);
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


void	ft_rrr(t_pp *data1, t_pp *data2)
{
	ft_rev_rotate(data2);
	ft_rev_rotate(data1);
	write(1,"rrr\n", 4);
}