/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stat_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md4 <md4@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 18:49:24 by md4               #+#    #+#             */
/*   Updated: 2020/04/19 16:21:40 by md4              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

/*
** FUNCTION : ft_get_median.
** PARAMETERS :	int *median: int pointer, place to stock calculated median.
**				int **stack : table of *int.
**				size_t nb_elem : nb elements of **stack.
** DESCRIPTION :
**		Get the median of the list of number by sorting it first.
** RETURN :
**		0 if any problem is encountered.
**		1 if everything is fine.
*/

int		ft_get_median(int *median, int **stack, size_t nb_elem)
{
	size_t		k;
	int			*tmp_lst;
	int			start;

	k = 0;
	start = 0;
	if (!(tmp_lst = (int*)malloc(sizeof(int) * nb_elem)) || nb_elem == 0)
		return (0);
	while (stack[start] == NULL)
		start++;
	while (k < nb_elem)
	{
		tmp_lst[k] = *stack[start + k];
		k++;
	}
	quicksort(&tmp_lst, 0, (int)(nb_elem - 1));
	*median = tmp_lst[(int)(nb_elem - 1) / 2];
	free((void*)tmp_lst);
	return (1);
}

/*
** FUNCTION : ft_get_average.
** PARAMETRES :	int **stack : table of *int.
**				size_t nb_elem : nb elements of **stack.
** DESCRIPTION :
**		Get the average of the list.
** RETURN :
**		value of the average of the integers list.
*/

int		ft_get_average(int *avg, int **stack, size_t nb_elem)
{
	size_t		k;

	k = 0;
	if (nb_elem == 0)
		return(0);
	while (stack[k] == NULL)
		k++;
	while (k < nb_elem)
	{
		*avg += *stack[k];
		k++;
	}
	*avg = *avg / ((int)nb_elem - 1);
	return (1);
}

/*
** Function: ft_get_min
** Arguments:	t_pp *data: stack of integers (pointers on them)
**				t_info info: information about the stack
** Description:
**	Get the index within the stack of the minimum number.
** Return:
**	pos: position au sein de la stack du minimum
*/

int		ft_get_pos_min(int **stack, t_info info, char a_or_b)
{
	size_t		i;
	size_t		pos;
	size_t		len;
	size_t		start;

	start = (a_or_b == 'a') ? info.start1 : info.start2;
	i = start;
	pos = start;
	len = (a_or_b == 'a') ? info.len1 : info.len2;
	while (i < len + start)
	{
		if (*stack[i] < *stack[pos])
			pos = i;
		i++;
	}
    return (pos);
}

/*
** Function: ft_get_max
** Arguments:	t_pp *data: stack of integers (pointers on them)
**				t_info info: information about the stack
** Description:
**	Get the index within the stack of the maximum number.
** Return:
**	pos: position au sein de la stack du maximum.
*/

int		ft_get_pos_max(int **stack, t_info info, char a_or_b)
{
	size_t		i;
	size_t		pos;
	size_t		len;
	size_t		start;

	start = (a_or_b == 'a') ? info.start1 : info.start2;
	i = start;
	pos = start;
	len = (a_or_b == 'a') ? info.len1 : info.len2;
	while (i < len + start)
	{
		if (*stack[i] > *stack[pos])
			pos = i;
		i++;
	}
    return (pos);
}