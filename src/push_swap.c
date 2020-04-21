/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md4 <md4@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 13:20:38 by mdavid            #+#    #+#             */
/*   Updated: 2020/04/19 19:22:54 by md4              ###   ########.fr       */
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
		return;
	if (!(*info = (t_info*)malloc(sizeof(t_info))))
		return;
	(*data)->tot_len = total;
	if (!((*data)->stack1 = (int**)malloc(sizeof(int*) * total)))
		return;
	if (!((*data)->stack2 = (int**)malloc(sizeof(int*) * total)))
	{
		free((*data)->stack1);
		return;
	}
	(*info)->tot_len = total;
	(*info)->len1 = total;
	(*info)->len2 = 0;
	(*info)->start1 = 0;
	(*info)->start2 = total;
}

/*
**
**
**
*/

void	ft_fill_stacks(int **int_stack, t_pp **data, char **av, size_t total)
{
	size_t		i;

	i = 0;
	if (!((*int_stack) = (int*)malloc(sizeof(int) * total)))
		return;
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

	//data = NULL;
	info = NULL;
	if (!ft_check_args(ac, av))
		return (0);
	ft_initialization(&data, &info, ac - 1);
	ft_fill_stacks(&int_stack, &data, av, ac - 1);
	pp_print_2stack_full(*data, *info);
	printf("ici avant quicksort_2_stacks\n");
	quicksort_2stacks(data, *info, 'a');
	pp_print_2stack_full(*data, *info);
	// pp_print_2stack_full(data1, data2);
	// special_swap(&data1, &data2, 3, 1);
}
	//printf("sizeof(int)=%lu\n",sizeof(int));// = 4
	//printf("sizeof(int*)=%lu\n",sizeof(int*));// = 8
	//printf("sizeof(size_t)=%lu\n",sizeof(size_t));// = 8