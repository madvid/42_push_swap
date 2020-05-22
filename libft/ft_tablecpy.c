/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tablecpy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md4 <md4@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 14:12:24 by md4               #+#    #+#             */
/*   Updated: 2020/05/19 17:12:34 by md4              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Function: ft_tablecpy
** Paramaters:
**		char **dest: destination table
**		char **src: source table
** Decription:
**		Copy table src to table dest.
** Return:
**		None.
*/

void	ft_tablecpy(char **dest, char **src)
{
	size_t	i;

	i = 0;
	if (src == NULL || dest == NULL)
		return ;
	while (src[i] != NULL)
	{
		ft_strcpy(dest[i], src[i]);
		i++;
	}
}
