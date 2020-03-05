/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 17:10:55 by mdavid            #+#    #+#             */
/*   Updated: 2020/03/05 13:23:09 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "common.h"
#include "libft.h"

int		ft_check_args(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac < 2)
	{
		write(1, "Empty list of arguments.\n", 25);
		return ((int)STAT_ERR);
	}
	while (++i < ac)
	{
		if (ft_isnumber(av[i]) == (int)STAT_ERR)
		{
			write(1, "Error\n", 6);
			return ((int)STAT_ERR);
		}
	}
	if (ac == 2)
	{
		write(1, "OK\n", 3);
		return ((int)STAT_ERR);
	}
	return ((int)STAT_OK);
}
