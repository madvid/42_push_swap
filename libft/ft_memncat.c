/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md4 <md4@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/25 01:25:52 by md4               #+#    #+#             */
/*   Updated: 2020/05/29 02:38:42 by md4              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
** Function: ft_mamncat
** Parameters:
**		char **main:
**		char *add:
**		int len:
** Description:
**		Create one allocated string from 2 allocated strings.
**		main and add are concatenates into a new string and this new string
**		and this new string is pointed by main address.
**		Previous main allocated string is freed before return.
** Return:
**	1: if the all proccess is done succefully
**	0: if len is zero or either main or add is NULL
**	-1: if allocation memory fail
*/

int		ft_memncat(char **main, char *add, int len)
{
	char	*new;
	int		lenstr;

	if (len != 0 && main != NULL && add != NULL)
	{
		new = NULL;
		lenstr = ft_strlen(*main);
		if ((new = (char *)malloc(sizeof(char) * (lenstr + len + 1))) == NULL)
			return (-1);
		ft_memcpy(new, *main, lenstr);
		ft_memcpy(new + lenstr, add, len);
		new[lenstr + len] = '\0';
		if (*main != NULL)
			free(*main);
		*main = new;
		return (1);
	}
	return (0);
}
