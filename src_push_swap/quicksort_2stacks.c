/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_2stacks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md4 <md4@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 14:15:13 by mdavid            #+#    #+#             */
/*   Updated: 2020/05/20 16:46:15 by md4              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Function: ft_check_for_return
** Parameters:
**		variables..........
** Description:
**	Check if a return have to be performed back to a
**	recursive call to ft_quicksort_2stacks.
** Return:
**		0: no return in quicksort_2stack to be performed
**		1: return in quicksort_2stack have to be performed
*/

int		ft_check_for_return(t_pp *data, t_info info)
{
	if (info.start1 == info.tot_len)
		if (data->stack2[info.start2] == NULL)
			return (1);
	if (info.start2 == info.tot_len)
		if (data->stack1[info.start1] == NULL)
			return (1);
	if (info.start1 != info.tot_len && info.start2 != info.tot_len)
		if (data->stack1[info.start1] == NULL || data->stack2[info.start2] == NULL)
			return (1);
	return (0);
}

/*
** FUNCTION : quicksort_2stacks
** PARAMETRES :	t_pp *data1 : 1st struct of data holding the 1st stack.
**				t_pp *data2 : 2nd struct of data holding the 2nd stack.
** DESCRIPTION :
**		Sort the stack of .
** RETOUR :
**		RIEN.
*/

void	quicksort_2stacks(t_pp *data, t_info info, char a_or_b)
{
	t_info	cpy;

	info.len1 > 0 && info.len1 <= 3 ? ft_sort_short_stack(data, info, 'a') : 0;
	info.len2 > 0 && info.len2 <= 3 ? ft_sort_short_stack(data, info, 'b') : 0;
	ft_info_cpy(&cpy, info);
	if (info.len1 > 3 && a_or_b == 'a' && ft_issort(data, info, 1, 'a') != 1)
	{
		ft_stck_splt2b(data, &info, ft_get_median);
		quicksort_2stacks(data, info, 'a');
		ft_info_back(&cpy, &info);
		if (ft_check_for_return(data, info) == 1)
			return ;
		a_or_b = 'b';
	}
	if (info.len2 > 3 && a_or_b == 'b' && ft_issort(data, info, 0, 'b') != 1)
	{
		ft_stck_splt2a(data, &info, ft_get_median);
		quicksort_2stacks(data, info, 'b');
		ft_info_back(&cpy, &info);
		if (ft_check_for_return(data, info) == 1)
			return ;
		a_or_b = 'a';
	}
	if (ft_both_issort(data, info) == 2)
	{
		if (info.len1 + info.start1 == info.tot_len)
			ft_push_back(data, &info, 'b');
		else
			ft_push_back(data, &info, ft_not_a_or_b(a_or_b));
		return ;
	}
	if (ft_issort(data, info, 1, 'a') == 1 && ft_issort(data, info, 0, 'b') != 1)
	{
		quicksort_2stacks(data, info, 'b');
		ft_info_recover(&info, data);
	}
	if (ft_issort(data, info, 1, 'a') != 1 && ft_issort(data, info, 0, 'b') == 1)
	{
		quicksort_2stacks(data, info, 'a');
		ft_info_recover(&info, data);
	}
	if (ft_issort(data, info, 1, 'a') != 1 && ft_issort(data, info, 0, 'b') != 1)
		quicksort_2stacks(data, info, 'a');
}
