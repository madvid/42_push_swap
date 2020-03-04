/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 13:20:38 by mdavid            #+#    #+#             */
/*   Updated: 2020/03/04 19:14:25 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"
#include "common.h"


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
	t_pp	data1;
	t_pp	data2;

	if (!ft_check_args(ac, av))
		return (0);

	total = ac - 1;
	stack0 = (int*)malloc(sizeof(int) * (total));

	data1.t_len = total;
	data1.len = total;
	data2.t_len = total;
	data2.len = 0;
	data1.stack = (int**)malloc(sizeof(int*) * (total));
	data2.stack = (int**)malloc(sizeof(int*) * (total));
	while (i < total)
	{
		stack0[i] = ft_atoi(av[i + 1]);
		data1.stack[i] = &stack0[i];
		data2.stack[i] = NULL;
		i++;
	}

	// data1.head = (void*)&data1.stack[0];
	// data1.tail = (void*)&data1.stack[total];
	// data2.head = (void*)&data2.stack[0];
	// data2.tail = (void*)&data2.stack[total];

	// printf("&d1.head = %p\n", data1.head);
	// printf("&d1.queue = %p\n", data1.queue);
	// printf("&d2.head = %p\n", data2.head);
	// printf("&d2.queue = %p\n", data2.queue);
	
	pp_print_2stack_full(data1, data2);
	ft_rr_a(&data1);
	pp_print_2stack_full(data1, data2);
	ft_rr_a(&data1);
	pp_print_2stack_full(data1, data2);
	ft_rr_a(&data1);
	pp_print_2stack_full(data1, data2);
	ft_rr_a(&data1);
	pp_print_2stack_full(data1, data2);
	// special_swap(&data1, &data2, 3, 1);

}
	//printf("sizeof(int)=%lu\n",sizeof(int));// = 4
	//printf("sizeof(int*)=%lu\n",sizeof(int*));// = 8
	//printf("sizeof(size_t)=%lu\n",sizeof(size_t));// = 8