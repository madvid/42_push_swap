/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md4 <md4@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 13:20:38 by mdavid            #+#    #+#             */
/*   Updated: 2020/05/21 15:31:47 by md4              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"
#include "common.h"
#include "libft.h"

/*
** Function:  ft_initialization
** Arguments:	*data: pointer on struc stocking the 2 stacks
**				*info: pointer on struct stocking info about stacks
**				total: length of int list received in arguments
** Description:
** 	Initialization of the differents struct and variables.
*/

void	ft_initialization(t_pp **data, t_info **info, size_t total)
{
	if (!(*data = (t_pp*)malloc(sizeof(t_pp))))
		return ;
	if (!(*info = (t_info*)malloc(sizeof(t_info))))
		return ;
	(*data)->tot_len = total;
	if (!((*data)->stack1 = (int**)malloc(sizeof(int*) * total)))
		return ;
	if (!((*data)->stack2 = (int**)malloc(sizeof(int*) * total)))
	{
		free((*data)->stack1);
		return ;
	}
	if (((*data)->buf_act = ft_table_str(total, 4)) == NULL)
	{
		free((*data)->stack2);
		free((*data)->stack1);
		return ;
	}
	(*data)->act_list = NULL;
	(*data)->i_act = 0;
	(*info)->tot_len = total;
	(*info)->len1 = total;
	(*info)->len2 = 0;
	(*info)->start1 = 0;
	(*info)->start2 = total;
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

void	ft_fill_stacks(int **int_stack, t_pp **data, char **av, size_t total)
{
	size_t		i;

	i = 0;
	if (!((*int_stack) = (int*)malloc(sizeof(int) * total)))
		return ;
	while (i < total)
	{
		(*int_stack)[i] = ft_atoi(av[i + 1]);
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

void	ft_destroy(t_pp *data, t_info *info, int *int_stack)
{
	free(info);
	info = NULL;
	free(data->stack1);
	data->stack1 = NULL;
	free(data->stack2);
	data->stack2 = NULL;

	ft_free_table_str(data->buf_act);
	ft_free_table_str(data->act_list);
	free(data);
	data = NULL;
	free(int_stack);
	int_stack = NULL;
}

/*
** Function: main
** Parameters:
**		int ac:
**		char **av:
** Description:
**		main is main nothing else.
*/

int		main(int ac, char **av)
{
	int		*int_stack;
	t_pp	*data;
	t_info	*info;

	info = NULL;
	if (check_args(ac, av) == 0)
		return (0);
	ft_initialization(&data, &info, ac - 1);
	ft_fill_stacks(&int_stack, &data, av, ac - 1);
	if (info->tot_len <= 5 && ft_issort(data, *info, 1, 'a') == 0)
		ft_optimal_small_sort(data, info);
	if (info->tot_len > 5 && ft_issort(data, *info, 1, 'a') == 0)
		quicksort_2stacks(data, *info, 'a');
	ft_final_opti_1(data);
	pp_print_act_list(data->act_list);
	ft_destroy(data, info, int_stack);
	return (0);
}
