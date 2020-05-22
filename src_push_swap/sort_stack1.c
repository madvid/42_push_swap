/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md4 <md4@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 12:33:11 by md4               #+#    #+#             */
/*   Updated: 2020/05/16 12:33:14 by md4              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Function: ft_sort_2_elem (type int)
** Parameters:	*t_pp *data : stack with 'number' (pointers on its)
**				*t_info *info : informations on current stack (start & len)
**				char a_or_b : tag to specify the stack under treatement.
** Description:
**	Sort the stack given in parameter. Depending if the stack is A(/left) or B
**	(/right) it will be sorted in ascending or descending order.
** Return:
**		0 : stack was already sorted.
**		1 : stack has been sorted.
*/

int		ft_sort_2_elem(t_pp *data, t_info info, char a_or_b)
{
	size_t	s;

	s = (a_or_b == 'a') ? info.start1 : info.start2;
	if (a_or_b == 'a' && *(data->stack1[s]) > *(data->stack1[s + 1]))
	{
		ft_s_a(data, info);
		return (1);
	}
	if (a_or_b == 'b' && *(data->stack2[s]) < *(data->stack2[s + 1]))
	{
		ft_s_b(data, info);
		return (1);
	}
	return (0);
}

/*
** Function: ft_sort_short_stack (type int)
** Parameters:	*t_pp *data : stack with 'number' (pointers on its)
**				*t_info *info : informations on current stack (start & len)
** Description:
**	Sort the stack given in parameter. Depending if the stack is A(/left) or B
**	(/right) it will be sorted in ascending or descending order.
** Return:
**		-1 : lenght of stack is too long for short stack sorting functions.
**		0 : stack was already sorted.
**		1 : stack has been sorted.
*/

int		ft_sort_short_stack(t_pp *data, t_info info, char a_or_b)
{
	int		sorted;
	size_t	len;

	sorted = 0;
	len = (a_or_b == 'a') ? info.len1 : info.len2;
	if (len > 3)
		return (-1);
	if (a_or_b == 'a')
	{
		sorted += (len == 3) ? ft_sort_small_stack_a(data, info) : 0;
		sorted += (len == 2) ? ft_sort_2_elem(data, info, a_or_b) : 0;
	}
	if (a_or_b == 'b')
	{
		sorted += (len == 3) ? ft_sort_small_stack_b(data, info) : 0;
		sorted += (len == 2) ? ft_sort_2_elem(data, info, a_or_b) : 0;
	}
	return (sorted);
}
