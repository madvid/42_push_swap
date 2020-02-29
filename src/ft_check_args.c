/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 17:10:55 by mdavid            #+#    #+#             */
/*   Updated: 2020/02/29 17:43:10 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "common.h"
#include "libft.h"

int		ft_check_args(int nb_arg, char **av)
{
	static int	i;
	int			arg;

	while (++i <= nb_arg)
	{
		if (ft_isnumber(av[i] == (int)STAT_ERR))
			return ((int)STAT_ERR);
	}
	return((int)STAT_OK);
}