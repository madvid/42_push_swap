/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md4 <md4@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 13:20:38 by mdavid            #+#    #+#             */
/*   Updated: 2020/05/01 17:52:54 by md4              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
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
**
**
**
*/

int		main(int ac, char **av)
{
	int		*int_stack;
	t_pp	*data;
	t_info	*info;

	info = NULL;
	if (!ft_check_args(ac, av))
		return (0);
	ft_initialization(&data, &info, ac - 1);
	ft_fill_stacks(&int_stack, &data, av, ac - 1);
	if (info->tot_len <= 5)
		ft_optimal_small_sort(data, info);
	else
	{
		// Here it have to be check if the stack is sorted but where the start
		// is not on top : look at stack_issort
		// Plus, add a function to look if the stack can be sort with one or several actions
		// Kind of coding an estimation function to determinerthe disorder of the stack and
		// decide if quick sort should be run or not.
		quicksort_2stacks(data, *info, 'a');
	}
	pp_print_2stack_full(*data, *info);
	ft_issort(data, *info, 1, 'a') == 1 ?
	write(1, "list sorted\n", 12) : write(1, "liste not sorted\n", 17);
}
