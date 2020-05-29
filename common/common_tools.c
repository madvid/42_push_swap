/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md4 <md4@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 15:30:59 by md4               #+#    #+#             */
/*   Updated: 2020/05/29 02:12:12 by md4              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
