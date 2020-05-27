/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md4 <md4@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 12:31:52 by md4               #+#    #+#             */
/*   Updated: 2020/05/25 23:41:17 by md4              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "common.h"

/*
** Function: ft_sort_small_stack_b (type int)
** Parameters:	*t_pp *data1 : stack with 'number' (pointers on its)
**				*t_info *info1 : informations on current stack (start & len)
** Description:
**	Sort the stack A(/1) (given in parameter) in descending order if the number
**	of elements in the relative stack A is equal to 3.
*/

int		ft_sort_small_stack_b(t_pp *d, t_info info)
{
	size_t		s;

	s = info.start2;
	if (*(d->stack2[s]) > *(d->stack2[s + 1])
		&& *(d->stack2[s + 1]) > *(d->stack2[s + 2]))
		return (0);
	else if (*(d->stack2[s]) > *(d->stack2[s + 1]) && *(d->stack2[s])
		> *(d->stack2[s + 2]) && *(d->stack2[s + 1]) < *(d->stack2[s + 2]))
	{
		ft_r_b(d, info);
		ft_s_b(d, info);
		ft_rr_b(d, info);
	}
	else if (*(d->stack2[s]) > *(d->stack2[s + 1])
		&& *(d->stack2[s + 1]) < *(d->stack2[s + 2])
		&& *(d->stack2[s]) < *(d->stack2[s + 2]))
	{
		ft_r_b(d, info);
		ft_s_b(d, info);
		ft_rr_b(d, info);
		ft_s_b(d, info);
	}
	else
		ft_sort_small_stack_b_next(d, info);
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

void	ft_sort_small_stack_b_next(t_pp *d, t_info info)
{
	size_t	s;

	s = info.start2;
	if (*(d->stack2[s]) < *(d->stack2[s + 1]) && *(d->stack2[s + 1])
		> *(d->stack2[s + 2]) && *(d->stack2[s]) > *(d->stack2[s + 2]))
		ft_s_b(d, info);
	else if (*(d->stack2[s]) < *(d->stack2[s + 1]) && *(d->stack2[s + 1])
		> *(d->stack2[s + 2]) && *(d->stack2[s]) < *(d->stack2[s + 2]))
	{
		ft_s_b(d, info);
		ft_r_b(d, info);
		ft_s_b(d, info);
		ft_rr_b(d, info);
	}
	else
	{
		ft_s_b(d, info);
		ft_r_b(d, info);
		ft_s_b(d, info);
		ft_rr_b(d, info);
		ft_s_b(d, info);
	}
}

/*
** Function: ft_sort_small_stack_a (type int)
** Parameters:	*t_pp *data2 : stack with 'number' (pointers on its)
**				*t_info *info2 : informations on current stack (start & len)
** Description:
**	Sort the stack B(/2) (given in parameter) in ascending order if the number
**	of elements in the relative stack B is equal to 3.
*/

int		ft_sort_small_stack_a(t_pp *d, t_info info)
{
	size_t	s;

	s = info.start1;
	if (*(d->stack1[s]) < *(d->stack1[s + 1])
		&& *(d->stack1[s + 1]) < *(d->stack1[s + 2]))
		return (0);
	else if (*(d->stack1[s]) > *(d->stack1[s + 1]) && *(d->stack1[s + 1])
		< *(d->stack1[s + 2]) && *(d->stack1[s]) > *(d->stack1[s + 2]))
	{
		ft_s_a(d, info);
		ft_r_a(d, info);
		ft_s_a(d, info);
		ft_rr_a(d, info);
	}
	else if (*(d->stack1[s]) < *(d->stack1[s + 1]) && *(d->stack1[s + 1])
		> *(d->stack1[s + 2]) && *(d->stack1[s]) > *(d->stack1[s + 2]))
	{
		ft_r_a(d, info);
		ft_s_a(d, info);
		ft_rr_a(d, info);
		ft_s_a(d, info);
	}
	else
		ft_sort_small_stack_a_next(d, info);
	return (1);
}

/*
** Function: ft_sort_small_stack_a_next (type void)
** Parameters:	*t_pp *stack : stack with 'number' (pointers on its)
**				*t_info *info : informations on current stack (start & len)
** Description:
**	Second par of the function ft_sort_small_a.
**	Sort the stack B(/2) (given in parameter) in ascending order if the number
**	of elements in the relative stack B is equal to 3.
*/

void	ft_sort_small_stack_a_next(t_pp *d, t_info info)
{
	size_t	s;

	s = info.start1;
	if (*(d->stack1[s]) > *(d->stack1[s + 1]) && *(d->stack1[s + 1])
		< *(d->stack1[s + 2]) && *(d->stack1[s]) < *(d->stack1[s + 2]))
		ft_s_a(d, info);
	else if (*(d->stack1[s]) > *(d->stack1[s + 1]) && *(d->stack1[s + 1])
		> *(d->stack1[s + 2]) && *(d->stack1[s]) > *(d->stack1[s + 2]))
	{
		ft_s_a(d, info);
		ft_r_a(d, info);
		ft_s_a(d, info);
		ft_rr_a(d, info);
		ft_s_a(d, info);
	}
	else
	{
		ft_r_a(d, info);
		ft_s_a(d, info);
		ft_rr_a(d, info);
	}
}
