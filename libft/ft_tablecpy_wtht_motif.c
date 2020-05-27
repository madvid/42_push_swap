/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tablecpy_wtht_motif.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md4 <md4@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 14:13:27 by md4               #+#    #+#             */
/*   Updated: 2020/05/26 15:52:06 by md4              ###   ########.fr       */
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

void	ft_tablecpy_wtht_motif(char **dest, char **src, char *motif)
{
	size_t	i;
	size_t	d;

	i = 0;
	d = 0;
	if (src == NULL || dest == NULL || src[0] == NULL || dest[0] == NULL)
		return ;
	while (src[i + d] != NULL && dest[i] != NULL)
	{
		if (ft_strcmp(src[i + d], motif) != 0)
		{
			ft_strcpy(dest[i], src[i + d]);
			i++;
		}
		else
			d++;
	}
}
