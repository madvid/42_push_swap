/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md4 <md4@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 15:19:31 by mdavid            #+#    #+#             */
/*   Updated: 2020/05/10 13:47:31 by md4              ###   ########.fr       */
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

void	pp_print_addr(t_pp data, t_info info, int i_stack)
{
	size_t	i;
	size_t	countdown;
	size_t	len;
	size_t	start;
	int		**stack;

	i = data.tot_len - (i_stack == 1) ? info.len1 : info.len2;
	countdown = (i_stack == 1) ? info.len1 : info.len2;
	len = (i_stack == 1) ? info.len1 : info.len2;
	start = (i_stack == 1) ? info.start1 : info.start2;
	stack = (i_stack == 1) ? data.stack1 : data.stack2;
	printf("total number of the list data.len=%zu\n", len);
	printf("start point on the stack[%zu] -- ", i);
	printf("start point address: %p\n", (void*)stack[i % len]);
	printf("head stack address : %p\n", (void*)stack[0]);
	while (countdown > 0)
	{
		printf("  address &data.pp[%zu] = %p\n", i - start, (void*)stack[i % len]);
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

void	pp_print_2stack_full(t_pp data, t_info info)
{
	size_t	j = 0;
	size_t	l1 = info.len1;
	size_t	l2 = info.len2;

	printf("\n-------------------------data1-------data2\n");
	printf("Number of int in .stack:  %zu           %zu\n", l1, l2);
	printf("Index of start in stack:  %zu           %zu\n", info.start1, info.start2);
	printf("--------------------------------------------------------data1--------------||---------------------data2-----------\n");
	while (j < data.tot_len)
	{
		if (data.stack1[j] == NULL)
			printf("[%ld] [Cell adress]|[content][*content]: [%14p]|[%14p]|[%s] ||", j, &(data.stack1[j]), data.stack1[j], "null");
		else
			printf("[%ld] [Cell adress]|[content][*content]: [%14p]|[%14p]|[%4d] ||", j, &(data.stack1[j]), data.stack1[j], *data.stack1[j]);
		if (data.stack2[j] == NULL)
			printf(" [%14p]|[%14p]|[%s]\n", &(data.stack2[j]), data.stack2[j], "null");
		else
			printf(" [%14p]|[%14p]|[%4d]\n", &(data.stack2[j]), data.stack2[j], *data.stack2[j]);
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

void	pp_print_1stack_full(t_pp data, t_info info, int i_stack)
{
	size_t	j;
	size_t	len;
	size_t	start;
	int		**stack;

	j = 0;
	len = (i_stack == 1) ? info.len1 : info.len2;
	start = (i_stack == 1) ? info.start1 : info.start2;
	stack = (i_stack == 1) ? data.stack1 : data.stack2;
	printf("\n-------------------------data----\n");
	printf("Number of int in .stack:  %zu\n", len);
	printf("Start index in .stack  :  %zu\n", start);
	printf("--------------------------------------------------------data1---------------\n");
	while (j < len)
	{
		if (stack[j] == NULL)
			printf("[Cell adress]|[content][*content]: [14%p]|[14%p]|[%s]\n", &(stack[j]), stack[j], "null");
		else
			printf("[Cell adress]|[content][*content]: [14%p]|[14%p]|[%4d]\n", &(stack[j]), stack[j], *stack[j]);
		j++;
	}
	printf("---------------------------------------------------------------------------\n\n");
}

/*
** FUNCTION:	pp_print_2_info
** PARAMETERS:	t_info info1:
**				t_info info2:
** DESCRIPTION:
** 		Print all data inside info1 and info2.
** RETURN:
** 	None.
*/

void	pp_print_2_info(t_info info)
{
	printf("\n--------info1---info2--\n");
	printf("tot_len:  %3zu   %3zu\n", info.tot_len, info.tot_len);
	printf("len    :  %3zu   %3zu\n", info.len1, info.len2);
	printf("start  :  %3zu   %3zu\n", info.start1, info.start2);
	printf("-------------------------\n\n");
}

/*
** FUNCTION:	pp_print_stack_only
** PARAMETERS:	t_pp *data:
**				t_info *info:
** DESCRIPTION:
** 		Print the numbers of stack.
** RETURN:
** 	None.
*/

void	pp_print_stack_only(t_pp *data, t_info *info)
{
	size_t	start = info->start1;
	size_t	len = info->len1;
	size_t i = 0;

	while (i < len)
	{
		printf("%d ", *(data->stack1[start + i]));
		i++;
	}
	printf("\n");
}