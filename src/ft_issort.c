/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_issort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md4 <md4@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 18:04:07 by md4               #+#    #+#             */
/*   Updated: 2020/04/19 17:17:18 by md4              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	int			***ptr_stack;

	i = 0;
	start = (a_or_b == 'a') ? info.start1 : info.start2;
	len = (a_or_b == 'a') ? info.len1 : info.len2;
	ptr_stack = (a_or_b == 'a') ? &(data->stack1) : &(data->stack2);
	if (len == 0)
		return (0);
	while (i + 1 < len)
	{
		if (croissant == 0)
			if (*ptr_stack[i + start] < *ptr_stack[i + start + 1])
				return (0);
		if (croissant == 1)
			if (*ptr_stack[i + start] > *ptr_stack[i + start + 1])
				return (0);
		i++;
	}
	return (1);
}

/*
** Function: ft_stack_issort
** Arguments:   t_pp *data: stack with the integers(pointers on them)
**              t_info info: information of the stack
** Description
**	Check if the stack is sorted, given the option of sorting.
** Return:
**	0: stack is not sorted
**	1: stack is sorted
*/

int		ft_stack_issort(int **stack, t_info info, char a_or_b)
{
	size_t		start;
	size_t		len;
	size_t		min;
	size_t		i;

	i = 0;
	min = (a_or_b == 'a') ? ft_get_pos_min(stack, info, 'a')
		: ft_get_pos_min(stack, info, 'b');
	len = (a_or_b == 'a') ? info.len1 : info.len2;
	i = min;
	start = (a_or_b == 'a') ? info.start1 : info.start2;
	while (i < start + len)
	{
		if (*stack[start + i] > *stack[start + i + 1])
			return (0);
		i++;
	}
	if (i == len)
		return (1);
	i = (a_or_b == 'a') ? info.start1 : info.start2;
	if (*stack[i] > *stack[i + len])
		return (0);
	while (i < min)
	{
		if (*stack[i] > *stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}