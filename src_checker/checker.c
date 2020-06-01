/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md4 <md4@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 13:20:21 by mdavid            #+#    #+#             */
/*   Updated: 2020/06/01 18:32:12 by md4              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "checker.h"
#include "common.h"
#include "libft.h"

/*
** Function: ft_parse
** Parameters:
**		int ac:
**		char **av
**		char ***tab:
** Description:
**	Perform the parsing of the argument of the program.
** Return:
**	1: if parsing has gone well
**	0: otherwise
*/

int		ft_parse(int ac, char **av, char ***tab)
{
	if (parser(ac, av, tab) == 0)
	{
		ft_destroy(NULL, NULL, NULL, *tab);
		return (0);
	}
	return (1);
}

/*
** Function: ft_init
** Parameters:
**		char ***tab:
**		t_pp *data:
**		t_info *info:
**		int ***int_stack:
** Description:
**	Perform the intialization of the structure
**	necessary for the program.
** Return:
**	1: if initialization has gone well
**	0: otherwise
*/

int		ft_init(char **tab, t_pp **data, t_info **info, int **stack)
{
	if (ft_initialization(data, info, ft_tablelen(tab)) == 0)
	{
		ft_destroy(*data, *info, *stack, tab);
		return (0);
	}
	if (ft_fill_stacks(stack, data, tab, ft_tablelen(tab)) == 0)
	{
		ft_destroy(*data, *info, *stack, tab);
		return (0);
	}
	if (*stack == NULL)
	{
		ft_destroy(*data, *info, *stack, tab);
		write(1, "Error\n", 6);
		return (0);
	}
	ft_free_table_str(tab);
	return (1);
}

/*
** Function: ft_act_parse_perform
** Arguments:
**		t_pp *data: struct with stack1 & 2 and table of actions
**		t_info *info: struct with differents index and length info
** Description:
**	Function check first and perform the actions read on standard entry.
** Return:
**		1: if all actions was correct
**		0: if an action is not in the possible actions list
*/

int		ft_act_parse_perform(t_pp *data, t_info *info)
{
	char		*line;
	char		*action;

	while (get_next_line_lite(0, &line) == 1)
	{
		if ((action = ft_check_action(line)) == NULL)
		{
			ft_strdel(&line);
			return (0);
		}
		ft_strdel(&line);
		ft_perform_action(data, info, action);
	}
	ft_strdel(&line);
	return (1);
}

/*
** Function: main
** Parameters:
**		int ac:		number of arguments program name included
**		char **av:	[checker] + list of numbers (either a string with all
**					the numbers or one number per argument)
** Description
**	Main of the pregram checker.
**	The goal of this program is to check the sequence of action read
**	given by the user or by another program (push_swap) permit to sort
**	the list of numbers given as parameters.
**	Checker has a parser which check the validity of the arguments: it
**	has to be integer within IN_MIN and INT_MAX.
** Return:
**	0.
** Note: Use pp_print_1stack_full(*data, *info, 1).
**		 File can be find on https://github.com/madvid/push_swap
**		 in common/not_tracked_print_f.c
**		 Do not forget to modify /common/Makefile and /include/common.h
*/

int		main(int ac, char **av)
{
	int			*int_stack;
	t_pp		*data;
	t_info		*info;
	char		**tab;

	tab = NULL;
	if (ft_parse(ac, av, &tab) == 0
		|| ft_init(tab, &data, &info, &int_stack) == 0)
		return (0);
	if (ft_act_parse_perform(data, info) == 0)
	{
		ft_destroy(data, info, int_stack, NULL);
		return (0);
	}
	(info->len1 == info->tot_len && ft_issort(data, *info, 1, 'a') == 1) ?
		write(1, "OK\n", 3) : write(1, "KO\n", 3);
	ft_destroy(data, info, int_stack, NULL);
	return (0);
}
