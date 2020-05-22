/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md4 <md4@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 22:09:55 by md4               #+#    #+#             */
/*   Updated: 2020/05/21 15:52:19 by md4              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "common.h"
#include "libft.h"

/*
** Function: put_av_2_tab
** Parameters:
**		int ac: nb of arguments of the executable
**		char **av: arguments of the executable
** Description:
**		Put the arguments into a table of string.
** Return:
**		char **tab:
**		NULL:
*/

void		put_av_2_tab(int ac, char **av, char **tab)
{
	int		i;

	i = 0;
	if ((tab = (char**)malloc(sizeof(char*) * ac)) == NULL)
		return ;
	tab[ac - 1] = NULL;
	while(++i < ac)
	{
		tab[i - 1] = (char*)malloc(sizeof(char) * ft_strlen(av[i]));
		if (tab[i - 1] == NULL)
		{
			while(--i >= 0)
				free(tab[i]);
			free(tab);
			return ;
		}
		ft_strcpy(tab[i - 1], av[i]);
	}
}

/*
** Function: parser
** Parameters:
**		int ac:
**		char **av:
** Description:
**		Parsing and checking of the arguments.
** Return:
**		char **tab:
**		NULL:
*/

void		parser(int ac, char **av, char **tab)
{
	if (ac < 2)
	{
		write(1, "Empty list of arguments.\n", 25);
		return ;
	}
	if (ac > 2)
	{
		if (check_args(ac, av) == 0)
			return ;
		return (put_av_2_tab(ac, av, tab));
	}
	if (ft_isnumber_wthin_int(av[1]) == 0)
		return ;
	put_av_2_tab(ac, av, tab);
}
