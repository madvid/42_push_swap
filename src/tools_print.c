/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 15:19:31 by mdavid            #+#    #+#             */
/*   Updated: 2020/03/11 21:35:28 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

/*
** FUNCTION:	pp_print_addr
** ARGUMENTS:	t_pp data:
** DESCRIPTION:
** 		Print generic information about the data: len, start point.
** 		Then it print the address the start and head and all addresses of
** 		the cell of data.
** RETURN:
** 	None.
*/

void	pp_print_addr(t_pp data, t_info info)
{
	size_t	i = data.permanent_len - info.len;
	size_t	countdown = info.len;

	printf("total number of the list data.len=%zu\n", info.len);
	printf("start point on the stack[%zu] -- ", i);
	printf("start point address: %p\n", (void*)data.stack[i % info.len]);
	printf("head stack address : %p\n", (void*)data.stack[0]);
	while (countdown > 0)
	{
		printf("  address &data.pp[%zu] = %p\n", i - info.start, (void*)data.stack[i % info.len]);
		i++;
		countdown--;
	}
}

/*
** FUNCTION:	pp_print_2stack_full
** ARGUMENTS:	t_pp data1:
** 				t_pp data2:
** DESCRIPTION:
** 		Print generic information about the data: len, start point.
** 		Print the adresses and contents of data1 and data2
** RETURN:
** 	None.
*/

void	pp_print_2stack_full(t_pp data1, t_pp data2, t_info info1, t_info info2)
{
	size_t	j = 0;

	printf("\n-------------------------data1-------data2\n");
	printf("Number of int in .stack:  %zu           %zu\n", info1.len, info2.len);
	printf("Index of start in stack:  %zu           %zu\n", info1.start, info2.start);
	printf("--------------------------------------------------------data1--------------||---------------------data2-----------\n");
	while (j < data1.permanent_len)
	{
		if (data1.stack[j] == NULL)
			printf("[Cell adress]|[content][*content]: [%14p]|[%14p]|[%s] ||", &(data1.stack[j]), data1.stack[j], "null");
		else
			printf("[Cell adress]|[content][*content]: [%14p]|[%14p]|[%4d] ||", &(data1.stack[j]), data1.stack[j], *data1.stack[j]);
		if (data2.stack[j] == NULL)
			printf(" [%14p]|[%14p]|[%s]\n", &(data2.stack[j]), data2.stack[j], "null");
		else
			printf(" [%14p]|[%14p]|[%4d]\n", &(data2.stack[j]), data2.stack[j], *data2.stack[j]);
		j++;
	}
	printf("-------------------------------------------------------------------------||-------------------------------------\n\n");
}

/*
** FUNCTION:	pp_print_2stack_full
** ARGUMENTS:	t_pp data1:
** 				t_pp data2:
** DESCRIPTION:
** 		Print generic information about the data: len, start point.
** 		Print the adresses and contents of data1 and data2
** RETURN:
** 	None.
*/

void	pp_print_1stack_full(t_pp data, t_info info)
{
	size_t	j = 0;
	size_t	start = info.start;

	printf("\n-------------------------data----\n");
	printf("Number of int in .stack:  %zu\n", info.len);
	printf("Start index in .stack  :  %zu\n", start);
	printf("--------------------------------------------------------data1---------------\n");
	while (j < info.len)
	{
		if (data.stack[j] == NULL)
			printf("[Cell adress]|[content][*content]: [14%p]|[14%p]|[%s]\n", &(data.stack[j]), data.stack[j], "null");
		else
			printf("[Cell adress]|[content][*content]: [14%p]|[14%p]|[%4d]\n", &(data.stack[j]), data.stack[j], *data.stack[j]);
		j++;
	}
	printf("---------------------------------------------------------------------------\n\n");
}

/*
** FUNCTION:	pp_print_stack
** ARGUMENTS:	t_pp data:
** DESCRIPTION:
** 		Print generic information about the data: len, start point.
** 		Print the content of data
** RETURN:
** 	None.
*/

void	pp_print_stack(t_pp data, t_info info)
{
	size_t i = info.start;
	size_t countdown = info.len;

	printf("total number of the list data.len=%zu\n", info.len);
	printf("stack point on the stack[%zu]\n", info.start);
	while (countdown > 0)
	{
		printf("  data.pp[%zu]=%d\n", i - info.start, *data.stack[i % info.len]);
		i++;
		countdown--;
	}
}