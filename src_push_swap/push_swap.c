/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md4 <md4@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 13:20:38 by mdavid            #+#    #+#             */
/*   Updated: 2020/05/30 01:36:01 by md4              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "push_swap.h"
#include "common.h"

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
	char	**tab;

	info = NULL;
	if (parser(ac, av, &tab) == 0)
	{
		ft_destroy(NULL, NULL, NULL, tab);
		return (0);
	}
	ft_initialization(&data, &info, ft_tablelen(tab));
	if (ft_fill_stacks(&int_stack, &data, tab, ft_tablelen(tab)) == 0)
	{
		ft_destroy(data, info, int_stack, tab);
		return (0);
	}
	if (info->tot_len <= 5 && ft_issort(data, *info, 1, 'a') == 0)
		ft_optimal_small_sort(data, info);
	if (info->tot_len > 5 && ft_issort(data, *info, 1, 'a') == 0)
		quicksort_2stacks(data, *info, 'a');
	ft_final_opti_1(data);
	pp_print_act_list(data->act_list);
	ft_destroy(data, info, int_stack, tab);
	return (0);
}
