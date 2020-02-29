/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdavid <mdavid@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 17:30:18 by mdavid            #+#    #+#             */
/*   Updated: 2020/02/29 17:41:42 by mdavid           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "common.h"

int		ft_isnumber(const char *str)
{
	int		i;

	i = -1;
	if (!str)
		return ((int)STAT_ERR);
	while (str[++i])
	{
		if (ft_isdigit(str[i]) == (int)STAT_ERR)
			return ((int)STAT_ERR);
	}
}
