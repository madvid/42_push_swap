/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 16:05:07 by mdavid            #+#    #+#             */
/*   Updated: 2020/03/04 17:53:24 by mdavid           ###   ########.fr       */
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


void	ft_p_a(t_pp *dataA, t_pp *dataB)
{
	ft_push(dataB, dataA) ? write(1,"pa\n", 3) : 0;
}

void	ft_p_b(t_pp *dataA, t_pp *dataB)
{
	ft_push(dataA, dataB) ? write(1,"pb\n", 3) : 0;
}