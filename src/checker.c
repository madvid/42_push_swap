/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 13:20:21 by mdavid            #+#    #+#             */
/*   Updated: 2020/03/02 17:03:00 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "checker.h"
#include "common.h"

int			main(int ac, char **av)
{
	const char	**actions;

	if (ac < 2)
	{
		write(1, "OK\n", 3);
		return (0);
	}
	if (ft_check_args(ac - 1, av) == (int)STAT_ERR)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	actions = ft_init_tab_actions();
	(ft_read_actions(actions) == (int)STAT_OK) ?
		write(1, "OK\n", 3) : write(1, "KO\n", 3);
	return (0);
}
