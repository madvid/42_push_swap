/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_optimal_small_sort.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md4 <md4@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 19:05:43 by md4               #+#    #+#             */
/*   Updated: 2020/04/12 19:36:19 by md4              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
** Function: ft_optimal_small_sort
** Arguments:	t_pp *d1:
**				t_pp *d2:
**				t_pp *i1:
**				t_pp *i2:
**
*/

void    ft_optimal_small_sort(t_pp *d1, t_pp *d2, t_info i1, t_info i2)
{
	if (d1.permanent_len == 2)
		ft_sort_2_length(d1);
	else if (d1->permanent_len == 3)
		ft_sort_3_length(d1);
	else if (d1->permanent_len == 4)
		ft_sort_4_length(d1, d2, i1, i2);
	else
		ft_sort_5_length(d1, d2, i1, i2);
}