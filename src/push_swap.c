/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 13:20:38 by mdavid            #+#    #+#             */
/*   Updated: 2020/03/12 17:22:11 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "push_swap.h"
#include "common.h"
#include "libft.h"

/*
** Function: ft_stock_nb
** Arguments:	int n: number of arguments
** 				char **av: all the number to stock
** Description:
** 	Convert the string numbers to integer and stock all the number in a table
** 	of int.
** Return:
**	NULL if something wrong comes up.
**	int *tab: a table of int.
*/

/*int		*ft_stock_nb(int n, char **av)
{

}*/


int		main(int ac, char **av)
{
	int		i = 0;
	int		total;
	int		*stack0;
	int		*sorted_list;
	t_pp	data1;
	t_pp	data2;
	t_info	info1;
	t_info	info2;

	if (!ft_check_args(ac, av))
		return (0);

	total = ac - 1;
	stack0 = (int*)malloc(sizeof(int) * (total));
	sorted_list = (int*)malloc(sizeof(int) * (total));
	data1.permanent_len = total;
	data2.permanent_len = total;
	data1.stack = (int**)malloc(sizeof(int*) * (total));
	data2.stack = (int**)malloc(sizeof(int*) * (total));
	info1.tot_len = total;
	info2.tot_len = total;
	info1.len = total;
	info2.len = 0;
	info1.start = 0;
	info2.start = total;
	while (i < total)
	{
		stack0[i] = ft_atoi(av[i + 1]);
		sorted_list[i] = ft_atoi(av[i + 1]);
		data1.stack[i] = &stack0[i];
		data2.stack[i] = NULL;
		i++;
	}

	quicksort(&sorted_list, 0, total - 1);
	ft_print_intab(sorted_list, total - 1);
	pp_print_2stack_full(data1, data2, info1, info2);
	quicksort_2stacks(&data1, &data2, info1, info2, 1);
	pp_print_2stack_full(data1, data2, info1, info2);
	
	// pp_print_1stack_full(data1);

	// pp_print_2stack_full(data1, data2, info1, info2);
	// ft_p_b(&data1, &data2, &info1, &info2);
	// pp_print_2stack_full(data1, data2, info1, info2);
	// ft_p_b(&data1, &data2, &info1, &info2);
	// pp_print_2stack_full(data1, data2, info1, info2);
	// ft_p_b(&data1, &data2, &info1, &info2);
	// pp_print_2stack_full(data1, data2, info1, info2);
	// ft_p_a(&data1, &data2, &info1, &info2);
	// pp_print_2stack_full(data1, data2, info1, info2);
	// ft_r_a(&data1, info1);
	// pp_print_2stack_full(data1, data2, info1, info2);
	// ft_r_a(&data1, info1);
	// pp_print_2stack_full(data1, data2, info1, info2);
	// ft_r_b(&data2, info2);
	// pp_print_2stack_full(data1, data2, info1, info2);
	// ft_r_b(&data2, info2);
	// pp_print_2stack_full(data1, data2, info1, info2);
	// ft_rr(&data1, &data2, info1, info2);
	// pp_print_2stack_full(data1, data2, info1, info2);
	// ft_rr_a(&data1);
	// pp_print_2stack_full(data1, data2);
	// special_swap(&data1, &data2, 3, 1);

}
	//printf("sizeof(int)=%lu\n",sizeof(int));// = 4
	//printf("sizeof(int*)=%lu\n",sizeof(int*));// = 8
	//printf("sizeof(size_t)=%lu\n",sizeof(size_t));// = 8