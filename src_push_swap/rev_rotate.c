/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md4 <md4@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 19:56:14 by mdavid            #+#    #+#             */
/*   Updated: 2020/05/20 13:32:50 by md4              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
** 	Rotate all the elements down into the stack in data1 (via ft_rev_rotate).
** 	Then it print 'rra'.
*/

void	ft_rr_a(t_pp *data, t_info info)
{
	if (info.len1 == 0)
		return ;
	ft_rev_rotate(data->stack1, info, 'a');
	ft_add_actions(data, "rra\n");
	data->nb_actions += 1;
}

/*
** FUNCTION: ft_rr_b
** ARGUMENTS:	t_pp *data2
** DESCRIPTION:
** 	Rotate all the elements down into the stack in data2 (via ft_rev_rotate).
** 	Then it print 'rrb'.
*/

void	ft_rr_b(t_pp *data, t_info info)
{
	if (info.len2 == 0)
		return ;
	ft_rev_rotate(data->stack2, info, 'b');
	ft_add_actions(data, "rrb\n");
	data->nb_actions += 1;
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

void	ft_rrr(t_pp *data, t_info info)
{
	ft_rev_rotate(data->stack2, info, 'b');
	ft_rev_rotate(data->stack1, info, 'a');
	ft_add_actions(data, "rrr\n");
	data->nb_actions += 1;
}
