/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_table_nb_char.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md4 <md4@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 14:43:51 by md4               #+#    #+#             */
/*   Updated: 2020/05/19 17:11:30 by md4              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_table_nb_char(char **table)
{
	size_t	n_char;
	size_t	l;
	size_t	c;

	n_char = 0;
	l = 0;
	if (table == NULL)
		return (0);
	while (table[l] != NULL)
	{
		c = 0;
		while (table[l][c] != '\0')
		{
			c++;
			n_char++;
		}
		l++;
	}
	return (n_char);
}
