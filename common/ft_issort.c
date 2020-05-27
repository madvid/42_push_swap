/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_issort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md4 <md4@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/26 01:58:51 by md4               #+#    #+#             */
/*   Updated: 2020/05/27 15:21:58 by md4              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"

/*
** Function: ft_issort
** Arguments:   t_pp *data: stack with the integers(pointers on them)
**              t_info info: information of the stack
**              int croissant: option of sorting: ascending(1) or descending(0)
** Description
**	Check if the stack is sorted, given the option of sorting.
** Return:
**	0: stack is not sorted
**	1: stack is sorted
*/

int		ft_issort(t_pp *data, t_info info, int croissant, char a_or_b)
{
	size_t		i;
	size_t		start;
	size_t		len;
	int			**ptr_stack;

	i = 0;
	start = (a_or_b == 'a') ? info.start1 : info.start2;
	len = (a_or_b == 'a') ? info.len1 : info.len2;
	ptr_stack = (a_or_b == 'a') ? data->stack1 : data->stack2;
	if (len < info.tot_len)
		return (0);
	while (i + 1 < len)
	{
		if (croissant == 0)
			if (*(ptr_stack[i + start]) < *(ptr_stack[i + start + 1]))
				return (0);
		if (croissant == 1)
			if (*(ptr_stack[i + start]) > *(ptr_stack[i + start + 1]))
				return (0);
		i++;
	}
	return (1);
}