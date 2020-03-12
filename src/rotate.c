/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 17:45:42 by mdavid            #+#    #+#             */
/*   Updated: 2020/03/12 14:08:08 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"


/*
** FUNCTION: ft_rotate
** ARGUMENTS:	t_pp *data
** DESCRIPTION:
** 	Rotate all the elements up of the stack in data.
*/

void	ft_rotate(t_pp *data, t_info info)
{
	int			*tmp;
	size_t		i;

	i = info.start;
	tmp = data->stack[i];
	while (i + 1 < info.tot_len)
	{
		data->stack[i] = data->stack[i + 1];
		i++;
	}
	data->stack[i] = tmp;
}

/*
** FUNCTION: ft_r_a
** ARGUMENTS:	t_pp *data1
** DESCRIPTION:
** 	Rotate all the elements up into the stack in data1 (via ft_rotate).
** 	Then it print 'ra'.
*/

void	ft_r_a(t_pp *data1, t_info info1)
{
	ft_rotate(data1, info1);
	write(1,"ra\n", 3);
}

/*
** FUNCTION: ft_r_b
** ARGUMENTS:	t_pp *data2
** DESCRIPTION:
** 	Rotate all the elements up into the stack in data2 up (via ft_rotate).
** 	Then it print 'rb'.
*/

void	ft_r_b(t_pp *data2, t_info info2)
{
	ft_rotate(data2, info2);
	write(1,"rb\n", 3);
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

void	ft_rr(t_pp *data1, t_pp *data2, t_info info1, t_info info2)
{
	ft_rotate(data2, info2);
	ft_rotate(data1, info1);
	write(1,"rr\n", 3);
}
