/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md4 <md4@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 17:10:55 by mdavid            #+#    #+#             */
/*   Updated: 2020/05/26 00:38:20 by md4              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "common.h"
#include "libft.h"

/*
** Function: ft_iswithin_int
** Parameters:
**		char *av: one of the argument of the program
** Description:
**		Check if the argument is within INT_MIN and INT_MAX.
** Return:
**		1: if number in string is within INT_MIN and INT_MAX
**		0: otherwise
*/

int		ft_iswithin_int(char *s)
{
	size_t		i;
	int			sign;
	size_t		result;

	i = 0;
	sign = 1;
	result = 0;
	if (s[i] == '+' || s[i] == '-')
	{
		sign = (s[i] == '-') ? -1 : 1;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		result = 10 * result + ((int)s[i] - 48);
		i++;
		if (sign == 1 && result > INTG_MAX)
			return (0);
		if (sign == -1 && result > (size_t)INTG_MAX + 1)
			return (0);
	}
	if (s[i] != '\0')
		return (0);
	return (1);
}


/*
** Function: ft_isall_wthin_int
** Parameters:
**		char **tab: table of str, one number per line
** Description:
**	Check all the string inside the table, if it is a number
**	between INT_MIN and INT_MAX
*/

int		ft_isall_wthin_int(char **tab)
{
	size_t	i;

	i = 0;
	if (tab == NULL)
	{
		write(1, "Error\n", 8);
		return (0);
	}
	while (tab[i] != NULL)
	{
		if (ft_iswithin_int(tab[i]) == 0)
		{
			write(1, "Error\n", 8);
			return (0);
		}
		i++;
	}
	return (1);
}

/*
** Function: ft_check_args
** Parameters:
**		int ac: number of arguments
**		char **av: the arguments of the program
** Description:
**		Check if the arguments of the program.
** Return:
**		1: ok
**		0: error
*/

int		check_args(int ac, char **av)
{
	int	i;

	i = 0;
	while (++i < ac)
	{
		if (ft_iswithin_int(av[i]) == 0)
		{
			write(1, "Error\n", 6);
			return (0);
		}
	}
	return (1);
}
