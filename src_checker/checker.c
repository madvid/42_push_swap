/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md4 <md4@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 13:20:21 by mdavid            #+#    #+#             */
/*   Updated: 2020/05/22 02:03:42 by md4              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "checker.h"
#include "common.h"

int			main(int ac, char **av)
{
	const char	**actions;

	if (check_args(ac, av) == 0)
		return (0);
	actions = ft_init_tab_actions();
	(ft_read_actions(actions) == 1) ?
		write(1, "OK\n", 3) : write(1, "KO\n", 3);
	return (0);
}
