/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort_2stacks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md4 <md4@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 14:15:13 by mdavid            #+#    #+#             */
/*   Updated: 2020/05/01 17:54:48 by md4              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

	//pp_print_2stack_full(*data, info);
	info.len1 > 0 && info.len1 <= 3 ? ft_sort_short_stack(data, info, 'a') : 0;
	info.len2 > 0 && info.len2 <= 3 ? ft_sort_short_stack(data, info, 'b') : 0;
	
	// Copy of info to keep access to information before modifications due to push_back
	ft_info_cpy(&cpy, info);
	
	// If the length of the stack is greater than 3 (may be optimize and deal 5 length)
	// Plus of the stack is not sorted (may evolve to stack_issort because it detect the
	// if the stack is sorted even if the start is not on the top)
	// The 2 following if will split the stack A or B in half (using median)
	if (info.len1 > 3 && a_or_b == 'a' && ft_issort(data, info, 1, 'a') != 1)
	{
		ft_stck_splt2b(data, &info, ft_get_median);
		quicksort_2stacks(data, info, 'a');
		ft_info_recover(&cpy, &info);
		// This return appends when a ush_back call lead to put back a segment on the top
		// stack A/B because the segment was sorted
		if (!(data->stack1[info.start1]) || !(data->stack2[info.start2]))
			return;
		a_or_b = 'b';
	}
	if (info.len2 > 3 && a_or_b == 'b' && ft_issort(data, info, 0, 'b') != 1)
	{
		ft_stck_splt2a(data, &info, ft_get_median);
		quicksort_2stacks(data, info, 'b');
		ft_info_recover(&cpy, &info);
		if (!(data->stack1[info.start1]) || !(data->stack2[info.start2]))
			return;
		a_or_b = 'a';
	}

	// When both upper segment of the stacks are sorted, push_back is called
	// We avoid the case when the stack A would be empty (can append depending on the length
	// of the list).
	// Can be optimize: if the all stack A is sorted (go futher than len1) and the segment on
	// B is sorted then we should force the push back on A, otherwise we have sequence of actions
	// where we have segment going from A to B to be push back on A.
	if (ft_both_issort(data, info) == 2)
	{
		if (info.len1 + info.start1 == info.tot_len)
			ft_push_back(data, &info, 'b');
		else
			ft_push_back(data, &info, ft_not_a_or_b(a_or_b));
		return ;
	}
	// Allow to permute on the other stack if A (or B) is sorted
	if (ft_issort(data, info, 1, 'a') == 1 && ft_issort(data, info, 0, 'b') != 1)
		quicksort_2stacks(data, info, 'b');
	if (ft_issort(data, info, 1, 'a') != 1 && ft_issort(data, info, 0, 'b') == 1)
		quicksort_2stacks(data, info, 'a');
}
