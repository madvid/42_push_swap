/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 13:20:21 by mdavid            #+#    #+#             */
/*   Updated: 2020/03/05 13:06:58 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "checker.h"
#include "common.h"

int			main(int ac, char **av)
{
	const char	**actions;

	if (ft_check_args(ac, av) == (int)STAT_ERR)
		return (0);
	actions = ft_init_tab_actions();
	(ft_read_actions(actions) == (int)STAT_OK) ?
		write(1, "OK\n", 3) : write(1, "KO\n", 3);
	return (0);
}
