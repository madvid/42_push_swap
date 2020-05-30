/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md4 <md4@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 22:09:55 by md4               #+#    #+#             */
/*   Updated: 2020/05/30 01:35:38 by md4              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

void	put_av_2_tab(int ac, char **av, char ***tab)
{
	int		i;

	i = 0;
	if (ac == 2)
	{
		*tab = ft_strsplit(av[1], ' ');
		return ;
	}
	if ((*tab = (char**)malloc(sizeof(char*) * ac)) == NULL)
		return ;
	(*tab)[ac - 1] = NULL;
	while (++i < ac)
	{
		(*tab)[i - 1] = (char*)malloc(sizeof(char) * (ft_strlen(av[i]) + 1));
		if ((*tab)[i - 1] == NULL)
		{
			while (--i >= 0)
				free((*tab)[i]);
			free(*tab);
			return ;
		}
		ft_strcpy((*tab)[i - 1], av[i]);
	}
}

/*
** Function ft_is_digit_and_spaces
** Parameters:
**		char *str: string containing possibly all the numbers
** Description:
**	Check if str is composed only of spaces and digits.
** Return:
**	1: str is composed only by spaces and digits
**	0: not only digits and spaces in str
*/

int		ft_is_digits_and_spaces(char *str)
{
	size_t	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] != '\0')
	{
		if (ft_isdigit((int)str[i]) == 0 && str[i] != ' '
			&& str[i] != '-')
			return (0);
		i++;
	}
	if (ft_isspaces_only(str) == 1)
		return (0);
	return (1);
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

int		parser(int ac, char **av, char ***tab)
{
	*tab = NULL;
	if (ac < 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (ac > 2)
	{
		if (check_args(ac, av) == 0)
			return (0);
		put_av_2_tab(ac, av, tab);
		return (1);
	}
	if (ft_is_digits_and_spaces(av[1]) == 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	put_av_2_tab(ac, av, tab);
	if (ft_isall_wthin_int(*tab) == 0)
		return (0);
	return (1);
}
