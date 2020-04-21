/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md4 <md4@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 21:22:15 by md4               #+#    #+#             */
/*   Updated: 2020/04/19 17:27:27 by md4              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Function: ft_sort_small_stack_b (type int)
** Parameters:	*t_pp *data1 : stack with 'number' (pointers on its)
**				*t_info *info1 : informations on current stack (start & len)
** Description:
**	Sort the stack A(/1) (given in parameter) in descending order if the number
**	of elements in the relative stack A is equal to 3.
*/

int		ft_sort_small_stack_b(int **stack, t_info info)
{
	size_t  s;

	s = info.start2;
	if (*stack[s] > *stack[s + 1]
		&& *stack[s + 1] > *stack[s + 2])
		return (0);
	else if (*stack[s] > *stack[s + 1]
		&& *stack[s + 1] < *stack[s + 2]
		&& *stack[s] > *stack[s + 2])
		{
			ft_r_b(stack, info);
			ft_s_b(stack, info);
			ft_rr_b(stack, info);
		}
	else if (*stack[s] > *stack[s + 1]
		&& *stack[s + 1] < *stack[s + 2]
		&& *stack[s] < *stack[s + 2])
		{
			ft_r_b(stack, info);
			ft_s_b(stack, info);
			ft_rr_b(stack, info);
			ft_s_b(stack, info);
		}
	else
		ft_sort_small_stack_b_next(stack,info);
	return (1);
}

/*
** Function: ft_sort_small_stack_b_next (type void)
** Parameters:	*t_pp *data1 : stack with 'number' (pointers on its)
**				*t_info *info1 : informations on current stack (start & len)
** Description:
**	Second par of the function ft_sort_small_b.
**	Sort the stack A(/1) (given in parameter) in descending order if the number
**	of elements in the relative stack A is equal to 3.
*/

void	ft_sort_small_stack_b_next(int **stack,t_info info)
{
	size_t  s;

	s = info.start2;
	if (*stack[s] < *stack[s + 1]
		&& *stack[s + 1] > *stack[s + 2]
		&& *stack[s] > *stack[s + 2])
	{
		ft_s_b(stack, info);
	}
	else if (*stack[s] < *stack[s + 1]
		&& *stack[s + 1] > *stack[s + 2]
		&& *stack[s] < *stack[s + 2])
	{
		ft_s_b(stack, info);
		ft_r_b(stack, info);
		ft_s_b(stack, info);
		ft_rr_b(stack, info);
	}
	else
	{
		ft_s_b(stack, info);
		ft_r_b(stack, info);
		ft_s_b(stack, info);
		ft_rr_b(stack, info);
		ft_s_b(stack, info);
	}
}

/*
** Function: ft_sort_small_stack_a (type int)
** Parameters:	*t_pp *data2 : stack with 'number' (pointers on its)
**				*t_info *info2 : informations on current stack (start & len)
** Description:
**	Sort the stack B(/2) (given in parameter) in ascending order if the number of
**	elements in the relative stack B is equal to 3.
*/

int		ft_sort_small_stack_a(int **stack, t_info info)
{
	size_t  s;

	s = info.start1;
	if (*stack[s] < *stack[s + 1]
		&& *stack[s + 1] < *stack[s + 2])
		return (0);
	else if (*stack[s] > *stack[s + 1]
		&& *stack[s + 1] < *stack[s + 2]
		&& *stack[s] < *stack[s + 2])
		ft_s_a(stack, info);
	else if (*stack[s] < *stack[s + 1]
		&& *stack[s + 1] > *stack[s + 2]
		&& *stack[s] > *stack[s + 2])
	{
		ft_r_a(stack,info);
		ft_s_a(stack,info);
		ft_rr_a(stack,info);
		ft_s_a(stack,info);
	}
	else
		ft_sort_small_stack_a_next(stack,info);
	return (1);
}

/*
** Function: ft_sort_small_stack_a_next (type void)
** Parameters:	*t_pp *stack : stack with 'number' (pointers on its)
**				*t_info *info : informations on current stack (start & len)
** Description:
**	Second par of the function ft_sort_small_a.
**	Sort the stack B(/2) (given in parameter) in ascending order if the number of
**	elements in the relative stack B is equal to 3.
*/

void	ft_sort_small_stack_a_next(int **stack,t_info info)
{
	size_t  s;

	s = info.start1;
	if (*stack[s] > *stack[s + 1]
		&& *stack[s + 1] > *stack[s + 2]
		&& *stack[s] > *stack[s + 2])
	{
		ft_s_a(stack, info);
		ft_r_a(stack, info);
		ft_s_a(stack, info);
		ft_rr_a(stack, info);
		ft_s_a(stack, info);
	}
	else if (*stack[s] > *stack[s + 1]
		&& *stack[s + 1] < *stack[s + 2]
		&& *stack[s] > *stack[s + 2])
	{
		ft_s_a(stack, info);
		ft_r_a(stack, info);
		ft_s_a(stack, info);
		ft_rr_a(stack, info);
	}
	else
	{
		ft_r_a(stack,info);
		ft_s_a(stack,info);
		ft_rr_a(stack,info);
	}
}

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

int		ft_sort_2_elem(int **stack, t_info info, char a_or_b)
{
	size_t  s;

	s = (a_or_b =='a') ? info.start1 : info.start2;
	if (a_or_b == 'a' && *(stack[s]) > *(stack[s + 1]))
	{
		ft_s_a(stack, info);
		return (1);
	}
	if (a_or_b == 'b' && (*stack[s]) < (*stack[s + 1]))
	{
		ft_s_b(stack, info);
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
		sorted += (len == 3) ? ft_sort_small_stack_a(data->stack1, info) : 0;
		sorted += (len == 2) ? ft_sort_2_elem(data->stack1, info, a_or_b) : 0;
	}
	if (a_or_b == 'b')
	{
		sorted += (len == 3) ? ft_sort_small_stack_b(data->stack2, info) : 0;
		sorted += (len == 2) ? ft_sort_2_elem(data->stack2, info, a_or_b) : 0;
	}
	return(sorted);
}