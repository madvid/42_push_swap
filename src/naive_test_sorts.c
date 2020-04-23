/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   naive_test_sorts.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md4 <md4@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 14:57:31 by mdavid            #+#    #+#             */
/*   Updated: 2020/04/22 21:54:07 by md4              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insertion_sort_naive(t_pp *data, t_info *info)
{
	size_t		compt;
	size_t		pos;

	compt = 0;
	pos = 0;
	if (*data->stack1[0] > *data->stack1[1])
		ft_p_b(data, info);
	ft_r_a(data, *info);
	while (ft_issort(data, *info, 1, 'a') == 0)
	{
		if (*data->stack1[info->tot_len] > *data->stack2[info->start2])
			ft_p_a(data, info);
		if (ft_issort(data, *info, 1, 'a') == 1)
			return ;
		ft_r_a(data, *info);
		compt++;
		pos++;
		pp_print_1stack_full(*data, *info, 1);
	}
}
