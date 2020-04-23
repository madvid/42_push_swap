/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optimal_small_sort.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md4 <md4@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 19:05:43 by md4               #+#    #+#             */
/*   Updated: 2020/04/22 22:08:00 by md4              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Function: ft_optimal_small_sort
** Arguments:	t_pp *data:
**				t_info info: info related stack structure.
** Description:
**	Optimize sorting for stack length smaller or equal to 5.
*/

void	ft_optimal_small_sort(t_pp *data, t_info info)
{
	if (info.tot_len == 2)
		ft_sort_2_length(data, info);
	else if (info.tot_len == 3)
		ft_sort_3_length(data, info);
	else if (info->tot_len == 4)
		ft_sort_4_length(data, info);
	else
		ft_sort_5_length(data, info);
}
