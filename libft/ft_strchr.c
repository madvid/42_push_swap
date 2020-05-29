/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md4 <md4@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/11 19:55:17 by mdavid            #+#    #+#             */
/*   Updated: 2020/05/29 02:43:20 by md4              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t		i;

	i = 0;
	if (s[i] != '\0')
	{
		while (s[i] != (const char)c && s[i] != '\0')
			i++;
		if (s[i] == '\0' && c != 0)
			return (NULL);
		return ((char*)(s + i));
	}
	else if (s[i] == '\0' && c == '\0')
		return ((char*)(s + i));
	else
		return (NULL);
}
