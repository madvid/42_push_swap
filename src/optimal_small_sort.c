/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimal_small_sort.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md4 <md4@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 19:05:43 by md4               #+#    #+#             */
/*   Updated: 2020/04/29 21:19:22 by md4              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Function: ft_sort_2_length
** Arguments:	t_pp *data: struct containing stacks integer.
**				t_info info: struct containing stacks info
** Description:
**	Function to sort stack of lentgh 2 only.
*/

void	ft_sort_2_length(t_pp *d, t_info *info)
{
	if (*(d->stack1[0]) > *(d->stack1[1]))
		ft_s_a(d, *info);
}

/*
** Function: ft_sort_3_length
** Arguments:	t_pp *d:
**				t_info info: struct containing stack1, int ptr table
** Description:
**	Function to sort stack of lentgh 3 only.
*/

void	ft_sort_3_length(t_pp *d, t_info *info)
{
	size_t		s;

	s = info->start1;
	if (*(d->stack1[s]) > *(d->stack1[s + 1])
		&& *(d->stack1[s + 1]) > *(d->stack1[s + 2]))
	{
		ft_s_a(d, *info);
		ft_rr_a(d, *info);
	}
	else if (*(d->stack1[s]) > *(d->stack1[s + 2])
		&& *(d->stack1[s + 1]) < *(d->stack1[s + 2]))
		ft_r_a(d, *info);
	else if (*(d->stack1[s]) > *(d->stack1[s + 1])
		&& *(d->stack1[s]) < *(d->stack1[s + 2]))
		ft_s_a(d, *info);
	else if (*(d->stack1[s]) < *(d->stack1[s + 1])
		&& *(d->stack1[s]) > *(d->stack1[s + 2]))
		ft_rr_a(d, *info);
	else if (*(d->stack1[s + 2]) > *(d->stack1[s])
		&& *(d->stack1[s + 2]) < *(d->stack1[s + 1]))
	{
		ft_rr_a(d, *info);
		ft_s_a(d, *info);
	}
}

/*
** Function: ft_sort_4_length
** Arguments:	t_pp *d:
**				t_info info: struct containing stack1, int ptr table
** Description:
**	Function to sort stack of lentgh 4 only.
*/

void	ft_sort_4_length(t_pp *d, t_info *info)
{
	size_t	s;

	s = info->start1;
	if (*(d->stack1[s]) < *(d->stack1[s + 1])
		&& *(d->stack1[s]) < *(d->stack1[s + info->len1 - 1]))
		ft_p_b(d, info);
	else if (*(d->stack1[s]) < *(d->stack1[s + 1])
		&& *(d->stack1[s]) > *(d->stack1[s + info->len1 - 1]))
	{
		ft_rr_a(d, *info);
		ft_p_b(d, info);
	}
	else
	{
		ft_r_a(d, *info);
		ft_p_b(d, info);
	}
	ft_sort_3_length(d, info);
	ft_p_a(d, info);
	ft_issort(d, *info, 1, 'a') == 0 ? ft_s_a(d, *info) : 0;
}

/*
** Function: ft_sort_5_length
** Arguments:	t_pp *d:
**				t_info info: struct containing stack1, int ptr table
** Description:
**	Function to sort stack of lentgh 5 only.
*/

void	ft_sort_5_length(t_pp *d, t_info *info)
{
	size_t	s;

	s = info->start1;
	if (*(d->stack1[s]) < *(d->stack1[s + 1])
		&& *(d->stack1[s]) < *(d->stack1[s + info->len1 - 1]))
		ft_p_b(d, info);
	else if (*(d->stack1[s]) < *(d->stack1[s + 1])
		&& *(d->stack1[s]) > *(d->stack1[s + info->len1 - 1]))
	{
		ft_rr_a(d, *info);
		ft_p_b(d, info);
	}
	else
	{
		ft_r_a(d, *info);
		ft_p_b(d, info);
	}
	ft_sort_4_length(d, info);
	ft_p_a(d, info);
	ft_issort(d, *info, 1, 'a') == 0 ? ft_s_a(d, *info) : 0;
}

/*
** Function: ft_optimal_small_sort
** Arguments:	t_pp *data:
**				t_info info: info related stack structure.
** Description:
**	Optimize sorting for stack length smaller or equal to 5.
*/

void	ft_optimal_small_sort(t_pp *data, t_info *info)
{
	if (info->tot_len == 2)
	{
		write(1, "longueur de 2\n", 14);
		ft_sort_2_length(data, info);
	}
	else if (info->tot_len == 3)
	{
		write(1, "longueur de 3\n", 14);
		ft_sort_3_length(data, info);
	}
	else if (info->tot_len == 4)
	{
		write(1, "longueur de 4\n", 14);
		ft_sort_4_length(data, info);
	}
	else
		ft_sort_5_length(data, info);
}
