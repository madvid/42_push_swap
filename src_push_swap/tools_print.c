/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md4 <md4@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 15:19:31 by mdavid            #+#    #+#             */
/*   Updated: 2020/05/28 01:15:58 by md4              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

/*
** Function: pp_print_act_list
** Parameters:
**		char **act_list: table of optimized actions sequence.
** Description:
**		Print the list of actions to sort the stack which has been optimized.
** Return:
**		None
*/

void	pp_print_act_list(char **act_list)
{
	int			i;

	i = 0;
	while (act_list[i] != NULL)
	{
		if (ft_strcmp(act_list[i], "000\n") != 0)
			ft_putstr(act_list[i]);
		i++;
	}
}
