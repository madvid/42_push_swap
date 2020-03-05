/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 15:19:31 by mdavid            #+#    #+#             */
/*   Updated: 2020/03/05 16:17:29 by mdavid           ###   ########.fr       */
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

void	pp_print_addr(t_pp data)
{
	size_t	start = data.t_len - data.len;
	size_t	i = data.t_len - data.len;
	size_t	countdown = data.len;

	printf("total number of the list data.len=%zu\n", data.len);
	printf("start point on the stack[%zu] -- ", i);
	printf("start point address: %p\n", (void*)data.stack[i % data.len]);
	printf("head stack address : %p\n", (void*)data.stack[0]);
	while (countdown > 0)
	{
		printf("  address &data.pp[%zu] = %p\n", i - start, (void*)data.stack[i % data.len]);
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

void	pp_print_2stack_full(t_pp data1, t_pp data2)
{
	size_t	j = 0;
	int		ori;
	int		dst;

	ori = (int)data1.t_len - (int)data1.len;
	dst = (int)data2.t_len - (int)data2.len;
	printf("\n-------------------------data1-------data2\n");
	printf("Number of int in .stack:  %zu           %zu\n", data1.t_len, data2.t_len);
	printf("Index of start in stack:  %d           %d\n", ori, dst);
	printf("--------------------------------------------------------data1--------------||---------------------data2-----------\n");
	while (j < data1.t_len)
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

void	pp_print_1stack_full(t_pp data)
{
	size_t	j = 0;
	int		start = (int)(data.t_len - data.len);

	printf("\n-------------------------data----\n");
	printf("Number of int in .stack:  %zu\n", data.len);
	printf("Start index in .stack  :  %d\n", start);
	printf("--------------------------------------------------------data1---------------\n");
	while (j < data.len)
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

void	pp_print_stack(t_pp data)
{
	int		start = (int)(data.t_len - data.len);
	size_t i = data.t_len - data.len;
	size_t countdown = data.len;

	printf("total number of the list data.len=%zu\n", data.len);
	printf("stack point on the stack[%d]\n", start);
	while (countdown > 0)
	{
		printf("  data.pp[%zu]=%d\n", i - start, *data.stack[i % data.len]);
		i++;
		countdown--;
	}
}