/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tab_actions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md4 <md4@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 17:02:17 by mdavid            #+#    #+#             */
/*   Updated: 2020/05/28 01:31:52 by md4              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "checker.h"
#include "libft.h"

void	ft_tab_alloc(char ***str)
{
	int		i;

	i = -1;
	if (!((*str) = (char**)malloc(sizeof(char*) * 12)))
		return ;
	while (++i <= 7)
	{
		if (!((*str)[i] = (char*)malloc(sizeof(char*) * 3)))
		{
			while (--i >= 0)
				free((void*)(*str)[i]);
			free(*str);
			return ;
		}
	}
	while (++i <= 10)
	{
		if (!((*str)[i] = (char*)malloc(sizeof(char*) * 4)))
		{
			while (--i >= 0)
				free((void*)(*str)[i]);
			free(*str);
			return ;
		}
	}
}

char	**ft_init_tab_actions(void)
{
	char **actions;

	ft_tab_alloc(&actions);
	ft_strcpy(actions[0], "sa");
	ft_strcpy(actions[1], "sb");
	ft_strcpy(actions[2], "ss");
	ft_strcpy(actions[3], "pa");
	ft_strcpy(actions[4], "pb");
	ft_strcpy(actions[5], "ra");
	ft_strcpy(actions[6], "rb");
	ft_strcpy(actions[7], "rr");
	ft_strcpy(actions[8], "rra");
	ft_strcpy(actions[9], "rrb");
	ft_strcpy(actions[10], "rrr");
	actions[11] = NULL;
	return (actions);
}
