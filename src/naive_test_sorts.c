/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   naive_test_sorts.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 14:57:31 by mdavid            #+#    #+#             */
/*   Updated: 2020/03/05 18:22:27 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

int		ft_issort(t_pp *data1)
{
	size_t		i;

	i = 0;
	while (i + 1 < data1->t_len)
	{
		if (*data1->stack[i] > *data1->stack[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	insertion_sort_naive(t_pp *data1, t_pp *data2)
{
	size_t		compt;
	size_t		pos;
	int			start1;
	int			start2;

	compt = 0;
	pos = 0;
	if (*data1->stack[0] > *data1->stack[1])
		ft_p_b(data1, data2);
	ft_r_a(data1);
	while (ft_issort(data1) == 0)
	{
		start1 = data1->t_len -data1->len;
		start2 = data2->t_len -data2->len;
		if (*data1->stack[data1->t_len] > *data2->stack[start2])
			ft_p_a(data1, data2);
		if (ft_issort(data1) == 1)
			return;
		ft_r_a(data1);
		compt++;
		pos++;
		pp_print_1stack_full(*data1);
	}
	printf("retour de issort = %d\n", ft_issort(data1));
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