/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   naive_test_sorts.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md4 <md4@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 14:57:31 by mdavid            #+#    #+#             */
/*   Updated: 2020/04/13 19:06:54 by md4              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	insertion_sort_naive(t_pp *data1, t_pp *data2, t_info *info1, t_info *info2)
{
	size_t		compt;
	size_t		pos;

	compt = 0;
	pos = 0;
	if (*data1->stack[0] > *data1->stack[1])
		ft_p_b(data1, data2, info1, info2);
	ft_r_a(data1, *info1);
	while (ft_issort(data1, *info1, 1) == 0)
	{
		if (*data1->stack[info1->tot_len] > *data2->stack[info2->start])
			ft_p_a(data1, data2, info1, info2);
		if (ft_issort(data1, *info1, 1) == 1)
			return;
		ft_r_a(data1, *info1);
		compt++;
		pos++;
		pp_print_1stack_full(*data1, *info1);
	}
	printf("retour de issort = %d\n", ft_issort(data1, *info1, 1));
}

// >>>> ALGORITHM INSERTION SORT <<<<<<
// int		i;
// int		j;
// int		*tmp;

// j = 1;
// while (j < data1->t_len)
// {
// 	tmp = data1->stack[j];
// 	i = j - 1;
// 	while (i > 0 && data1->stack[i] > tmp)
// 	{
// 		data1->stack[i + 1] = data1->stack[i];
// 		i--;
// 	}
// 	data1->stack[i + 1] = tmp;
// 	j++;
// }