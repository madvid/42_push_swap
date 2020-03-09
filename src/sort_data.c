/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 13:44:49 by mdavid            #+#    #+#             */
/*   Updated: 2020/03/09 19:17:30 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

void	rank_sorting_score(t_pp *data1, t_pp *data2)
{
	size_t		i;
	size_t		j;
	size_t		tot;

	i = data1->t_len - 1;
	tot = data1->t_len - 1;
	printf("valeur de t_len = %zu\n", tot);
	while (i >= 0)
	{
		j = 0;
		while (j < data2->t_len)
		{
			if (data2->stack[tot - j] != NULL && *data1->stack[i] == *data2->stack[tot - j])
			{
				data2->stack[tot - j] = NULL;
				break ;
			}
			j++;
			pp_print_2stack_full(*data1, *data2);
		}
		//*data1->stack[i] = j + 1;
		if (i == 0)
			break ;
		i--;
	}
}

int		permute(t_pp *data, int left, int right, int pivot)
{
	int		*tmp;

	// printf("pivot = %d -- lefft = %d -- right = %d\n", pivot, left, right);
	while (left <= right)
	{
		while (*data->stack[left] > pivot)
			left++;
		// printf("valeur de left = %d\n", left);
		while (*data->stack[right] < pivot)
			right--;
		// printf("valeur de right = %d\n", right);
		// printf("*stack[left = %d] = %d -- *stack[right = %d] = %d\n", left, *data->stack[left], right, *data->stack[right]);
		if (left <= right)
		{
			tmp = data->stack[right];
			data->stack[right] = data->stack[left];
			data->stack[left] = tmp;
			left++;
			right--;
			pp_print_1stack_full(*data);
		}
	}
	return (left);
}

void		sort_data(t_pp *data, int left, int right)
{
	int		pivot;
	int		index;
	
	if (left >= right)
		return ;
	pivot = *data->stack[(left + right) / 2];
	index = permute(data, left, right, pivot);
	sort_data(data, left, index - 1);
	sort_data(data, index, right);
}