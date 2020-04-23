/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md4 <md4@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 13:20:38 by mdavid            #+#    #+#             */
/*   Updated: 2020/04/22 21:49:45 by md4              ###   ########.fr       */
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
** Return:
**	0
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
	quicksort_2stacks(data, *info, 'a');
	pp_print_1stack_full(*data, *info, 1);
	ft_issort(data, *info, 1, 'a') == 1 ?
	write(1, "liste triée\n", 12) : write(1, "liste non triée\n", 17);
}
