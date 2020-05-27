/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md4 <md4@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 15:30:59 by md4               #+#    #+#             */
/*   Updated: 2020/05/27 15:54:35 by md4              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include "common.h"

/*
** Function:  ft_initialization
** Arguments:	*data: pointer on struc stocking the 2 stacks
**				*info: pointer on struct stocking info about stacks
**				total: length of int list received in arguments
** Description:
** 	Initialization of the differents struct and variables.
*/

int		ft_initialization(t_pp **data, t_info **info, size_t total)
{
	if (!(*data = (t_pp*)malloc(sizeof(t_pp)))
		|| !(*info = (t_info*)malloc(sizeof(t_info))))
	{
		ft_destroy(*data, NULL, NULL, NULL);
		return (0);
	}
	if (!((*data)->stack1 = (int**)malloc(sizeof(int*) * total))
		|| !((*data)->stack2 = (int**)malloc(sizeof(int*) * total))
		|| !((*data)->act_list = ft_table_str(total, 4)))
	{
		ft_destroy(*data, *info, NULL, NULL);
		return (0);
	}
	(*data)->tot_len = total;
	(*data)->i_act = 0;
	(*info)->tot_len = total;
	(*info)->len1 = total;
	(*info)->len2 = 0;
	(*info)->start1 = 0;
	(*info)->start2 = total;
	return (1);
}

/*
** Function: ft_fill_stacks
** Arguments:	int **int_stack: adress of integer table.
**				t_pp *data: struct containing stack1, int ptr table
**				char ***av: argument(s) of the binary push_swap
**				size_t total: arguments numbre of binary push_swap
** Decription:
**	Function will make data->stack1 pointing on each integers in int_stack.
**	It will also set all the integer pointers of data->stack2 on null.
**	In other words, it is the initialization function of the data structure.
*/

void	ft_fill_stacks(int **int_stack, t_pp **data, char **tab, size_t total)
{
	size_t		i;

	i = 0;
	if (!((*int_stack) = (int*)malloc(sizeof(int) * total)))
		return ;
	while (tab[i] != NULL && i < total)
	{
		(*int_stack)[i] = ft_atoi(tab[i]);
		(*data)->stack1[i] = &(*int_stack)[i];
		(*data)->stack2[i] = NULL;
		i++;
	}
}

/*
** Function: ft_destroy
** Parameters:
**		t_pp *data: struct containing 2 tables of *int + buff and list of
**					actions.
**		t_info *info: struct object related to info on stack1 and stack2
**		int *int_stack: table of int containing the numbers of the list.
** Description:
**	Free all variables/objects allocated within data and info.
** Return:
**		None
*/

void	ft_destroy(t_pp *data, t_info *info, int *int_stack, char **tab)
{
	if (info != NULL)
	{
		free(info);
		info = NULL;
	}
	if (data != NULL)
	{
		free(data->stack1);
		data->stack1 = NULL;
		free(data->stack2);
		data->stack2 = NULL;
		//ft_free_table_str(data->buf_act);
		ft_free_table_str(data->act_list);
	}
	if (data)
	{
		free(data);
		data = NULL;
	}
	if (int_stack != NULL)
	{
		free(int_stack);
		int_stack = NULL;
	}
	ft_free_table_str(tab);
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