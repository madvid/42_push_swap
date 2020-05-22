/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_actions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md4 <md4@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 15:33:44 by mdavid            #+#    #+#             */
/*   Updated: 2020/05/22 02:08:46 by md4              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "checker.h"
#include "libft.h"

int		ft_check_actions(char *buf, const char **actions)
{
	int		i;

	i = -1;
	while (actions[++i])
		if (ft_strcmp(buf, actions[i]) == 0)
			break ;
	return ((i == 11) ? 0 : 1);
}

int		ft_read_actions(const char **actions)
{
	char	*buf;
	int		stat_arg;

	stat_arg = 1;
	if (!(buf = ft_memalloc(4)))
		return (0);
	while (stat_arg == 1)
	{
		read(0, buf, 4);
		stat_arg = ft_check_actions(buf, actions);
		ft_bzero(buf, 4);
	}
	return (stat_arg);
}
