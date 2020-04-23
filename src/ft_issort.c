/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_issort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md4 <md4@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 18:04:07 by md4               #+#    #+#             */
/*   Updated: 2020/04/22 22:03:03 by md4              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Function: ft_both_issort
** Arguments:   t_pp *data: stack with the integers(pointers on them)
**              t_info info: information of the stack
** Description
**	Check if the 2 stacks are sorted.
** Return:
**	0: stacks are not sorted
**	1: stacks are sorted
*/

int		ft_both_issort(t_pp *data, t_info info)
{
	size_t		i;
	size_t		start1;
	size_t		start2;

	if (info.len1 == 0 && info.len2 == 0)
		return (1);
	i = 0;
	start1 = info.start1;
	start2 = info.start2;
	while (i + 1 < info.len1)
	{
		if (*(data->stack1[i + start1]) > *(data->stack1[i + start1 + 1]))
			return (0);
		i++;
	}
	i = 0;
	while (i + 1 < info.len2)
	{
		if (*(data->stack2[i + start2]) > *(data->stack2[i + start2 + 1]))
			return (0);
		i++;
	}
	return (1);
}

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
	if (len == 0)
		return (1);
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
	i = (a_or_b == 'a') ? info.start1 - 1 : info.start2 - 1;
	if (*stack[i + 1] > *stack[i + 1 + len])
		return (0);
	while (++i < min)
		if (*stack[i] > *stack[i + 1])
			return (0);
	return (1);
}
