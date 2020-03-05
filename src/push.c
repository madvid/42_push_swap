/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 16:05:07 by mdavid            #+#    #+#             */
/*   Updated: 2020/03/05 18:02:18 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** FUNCTION: ft_push
** ARGUMENTS:	t_pp *d_orig
** 				t_pp *d_dest
** DESCRIPTION:
** 	Push the 1st elem of d_orig.stack to the beginning of the d_dest.stack
** 	The function modified the start, len of d_orig/dest consequently.
** RETURN: None.
*/

int	ft_push(t_pp *d_orig, t_pp *d_dest)
{
	int	ori;
	int	dst;

	if (d_orig->len == 0)
		return 0;
	else
	{
		
		ori = d_orig->t_len - d_orig->len;
		dst = d_dest->t_len - d_dest->len - 1;
		d_dest->stack[dst] = d_orig->stack[ori];
		d_orig->stack[ori] = NULL;
		d_orig->len -= 1;
		d_dest->len += 1;
		return 1;
	}
}

/*
** FUNCTION: ft_p_a
** ARGUMENTS:	t_pp *data1
** 				t_pp *data2
** DESCRIPTION:
** 	Push the 1st element of data2.stack to the top of data1.stack (via ft_push).
** 	Then it print 'pa'.
*/

void	ft_p_a(t_pp *data1, t_pp *data2)
{
	ft_push(data2, data1) ? write(1,"pa\n", 3) : 0;
}

/*
** FUNCTION: ft_p_a
** ARGUMENTS:	t_pp *data1
** 				t_pp *data2
** DESCRIPTION:
** 	Push the 1st element of data1.stack to the top of data2.stack (via ft_push).
** 	Then it print 'pb'.
*/

void	ft_p_b(t_pp *data1, t_pp *data2)
{
	ft_push(data1, data2) ? write(1,"pb\n", 3) : 0;
}