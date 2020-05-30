/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspaces_only.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md4 <md4@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 23:08:38 by md4               #+#    #+#             */
/*   Updated: 2020/05/29 23:24:15 by md4              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Function: ft_isspaces_only
** Arguments:
**		char *str: string to check
** Description:
**	Check if the string is only constituted of spaces.
** Return:
**	0: The string has at least one character differents from space
**	1: The string is only spaces
*/

int		ft_isspaces_only(char *str)
{
	size_t		i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
	{
		if (str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}
