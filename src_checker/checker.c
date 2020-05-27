/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md4 <md4@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 13:20:21 by mdavid            #+#    #+#             */
/*   Updated: 2020/05/27 18:24:42 by md4              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "checker.h"
#include "common.h"
#include "libft.h"


/*
** Function: ft_check_action
** Parameters:
**		char *action:
** Description:
**	Check the validity of the action read/given byt the user.
** Return:
**	char *str: a string corresponding to action
**	NULL: if the action is not correct
*/

char	*ft_check_action(char *action)
{
	if (action == NULL)
		return (NULL);
	if (ft_strcmp("sa", action) == 0)
		return ("sa");
	else if (ft_strcmp("sb", action) == 0)
		return ("sb");
	else if (ft_strcmp("ss", action) == 0)
		return ("ss");
	else if (ft_strcmp("pa", action) == 0)
		return ("pa");
	else if (ft_strcmp("pb", action) == 0)
		return ("pb");
	else if (ft_strcmp("ra", action) == 0)
		return ("ra");
	else if (ft_strcmp("rb", action) == 0)
		return ("rb");
	else if (ft_strcmp("rr", action) == 0)
		return ("rr");
	else if (ft_strcmp("rra", action) == 0)
		return ("rra");
	else if (ft_strcmp("rrb", action) == 0)
		return ("rrb");
	else if (ft_strcmp("rrr", action) == 0)
		return ("rrr");
	else
		return (NULL);
}

/*
** Function: ft_perform_action
** Parameters:
**		t_pp *data:
**		t_info info:
**		char *action:
** Description:
**	Perform the action "pa"/"pb"/"sa" ... present in string action
**	on the stacks.
** Return:
**		NOne
*/

void	ft_perform_action(t_pp *data, t_info *info, char *action)
{
	if (ft_strcmp("sa", action) == 0)
		ft_s_a(data, *info);
	else if (ft_strcmp("sb", action) == 0)
		ft_s_b(data, *info);
	else if (ft_strcmp("ss", action) == 0)
		ft_swap_ss(data, *info);
	else if (ft_strcmp("pa", action) == 0)
		ft_p_a(data, info);
	else if (ft_strcmp("pb", action) == 0)
		ft_p_b(data, info);
	else if (ft_strcmp("ra", action) == 0)
		ft_r_a(data, *info);
	else if (ft_strcmp("rb", action) == 0)
		ft_r_b(data, *info);
	else if (ft_strcmp("rr", action) == 0)
		ft_rr(data, *info);
	else if (ft_strcmp("rra", action) == 0)
		ft_rr_a(data, *info);
	else if (ft_strcmp("rrb", action) == 0)
		ft_rr_b(data, *info);
	else
		ft_rrr(data, *info);
}

/*
** Function: ft_parse_and_init
** Parameters:
**		t_pp *data:
**		t_info *info:
**		int ***int_stack:
**		char ***tab:
** Description:
**	Perform the parsing and the intialization of the structure
**	necessary for the program.
** Return:
**	1: if parsing and initialization have gone well
**	0: otherwise
*/

int		ft_parse_and_init(int ac, char **av, t_pp **data, t_info **info, int **stack)
{
	char		**tab;

	if (parser(ac, av, &tab) == 0)
		return (0);
	if (ft_initialization(data, info, ft_tablelen(tab)) == 0)
	{
		ft_free_table_str(tab);
		write (1, "Error, parsing or memory allocation issue\n", 42);
		return (0);
	}
	ft_fill_stacks(stack, data, tab, ft_tablelen(tab));
	if (*stack == NULL)
	{
		ft_destroy(*data, *info, *stack, tab);
		write (1, "Error, parsing or memory allocation issue\n", 42);
		return (0);
	}
	ft_free_table_str(tab);
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
*/

int		main(int ac, char **av)
{
	int			*int_stack;
	t_pp		*data;
	char		*line;
	char		*action;
	t_info		*info;

	if (ft_parse_and_init(ac, av, &data, &info, &int_stack) == 0)
		return (0);
	while (get_next_line_lite(0, &line) == 1)
	{
		if ((action = ft_check_action(line)) == NULL)
		{
			write (1, "Error, action is not in the list\n", 33);
			printf("not in list of action: %s\n", action);
			ft_destroy(data, info, int_stack, NULL);
			return (0);
		}
		ft_strdel(&line);
		ft_perform_action(data, info, action);
	}
	(info->len1 == info->tot_len && ft_issort(data, *info, 1, 'a') == 1) ?
		 write(1, "OK\n", 3) : write(1, "KO\n", 3);
	pp_print_1stack_full(*data, *info, 1);
	ft_destroy(data, info, int_stack, NULL);
	ft_strdel(&line);
	return (0);
}
