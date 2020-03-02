/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tab_actions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 17:02:17 by mdavid            #+#    #+#             */
/*   Updated: 2020/03/02 17:02:44 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "checker.h"
#include "common.h"

void		ft_tab_alloc(const char ***str)
{
	int		i;

	i = -1;
	if (!((*str) = (const char**)malloc(sizeof(const char*) * 12)))
		return;
	while (++i <= 7)
	{
		if (!((*str)[i] = (const char*)malloc(sizeof(const char*) * 4)))
		{
			while (--i >= 0)
				free((void*)(*str)[i]);
			free(*str);
			return;
		}
	}
	while (++i <= 10)
	{
		if (!((*str)[i] = (const char*)malloc(sizeof(const char*) * 5)))
		{
			while (--i >= 0)
				free((void*)(*str)[i]);
			free(*str);
			return;
		}
	}
	(*str)[11] = NULL;
}

const char	**ft_init_tab_actions(void)
{
	const char **actions;

	ft_tab_alloc(&actions);
	actions[0] = "sa\n";
	actions[1] = "sb\n";
	actions[2] = "ss\n";
	actions[3] = "pa\n";
	actions[4] = "pb\n";
	actions[5] = "ra\n";
	actions[6] = "rb\n";
	actions[7] = "rr\n";
	actions[8] = "rra\n";
	actions[9] = "rrb\n";
	actions[10] = "rrr\n";
	return (actions);
}