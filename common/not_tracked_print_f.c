/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   not_tracked_print_f.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md4 <md4@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 02:11:38 by md4               #+#    #+#             */
/*   Updated: 2020/05/29 02:12:08 by md4              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "common.h"

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

	printf("\n-------------------------data1-------data2\n");
	printf("Number of int in .stack:  %zu           %zu\n", info.len1, info.len2);
	printf("Index of start in stack:  %zu           %zu\n", info.start1, info.start2);
	printf("--------------------------------------------------------data1--------------||---------------------data2-----------\n");
	while (j < data.tot_len)
	{
		if (data.stack1[j] == NULL)
			printf("[Cell adress]|[content][*content]: [%14p]|[%14p]|[%s] ||", &(data.stack1[j]), data.stack1[j], "null");
		else
			printf("[Cell adress]|[content][*content]: [%14p]|[%14p]|[%4d] ||", &(data.stack1[j]), data.stack1[j], *data.stack1[j]);
		if (data.stack2[j] == NULL)
			printf(" [%14p]|[%14p]|[%s]\n", &(data.stack2[j]), data.stack2[j], "null");
		else
			printf(" [%14p]|[%14p]|[%4d]\n", &(data.stack2[j]), data.stack2[j], *data.stack2[j]);
		j++;
	}
	printf("-------------------------------------------------------------------------||-------------------------------------\n\n");
}

/*
** FUNCTION:	pp_print_1stack_full
** ARGUMENTS:	t_pp data1:
** 				t_info info:
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