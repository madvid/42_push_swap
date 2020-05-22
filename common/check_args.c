/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md4 <md4@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 17:10:55 by mdavid            #+#    #+#             */
/*   Updated: 2020/05/21 16:15:48 by md4              ###   ########.fr       */
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
**		STAT_ERR(=0):
**		STAT_OK(=1):
*/

char	*ft_iswithin_int(char *s)
{
	size_t		i;
	int			sign;
	size_t		result;

	i = 0;
	sign = 1;
	result = 0;
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == 32)
		i++;
	if (s[i] == '+' || s[i] == '-')
	{
		sign = (s[i] == '-') ? -1 : 1;
		i++;
	}
	while ((s[i] >= '0') && (s[i] <= '9'))
	{
		result = 10 * result + ((int)s[i] - 48);
		i++;
		if (sign == 1 && result > INTG_MAX)
			return ("error");
		if (sign == -1 && result > (size_t)INTG_MAX + 1)
			return ("error");
	}
	return ("ok");
}

/*
** Function: ft_isnumber_wthin_int
** Parameters:
**		char *av: one of the argument of the program
** Description:
**		Check if the argument is a number and calls the function
**		ft_iswithin_int to verify if argument is within INT_MIN and INT_MAX.
** Return:
**		STAT_ERR(=0):
**		STAT_OK(=1):
*/

int		ft_isnumber_wthin_int(char *av)
{
	if (ft_isnumber(av) == 0)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	if (ft_strcmp(ft_iswithin_int(av), "error") == 0)
	{
		write(1, "Not all numbers within int range.\n", 34);
		return (0);
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
**		STAT_ERR(=0):
**		STAT_OK(=1):
*/

int		check_args(int ac, char **av)
{
	int	i;

	i = 0;
	while (++i < ac)
	{
		if (ft_isnumber_wthin_int(av[i]) == 0)
			return (0);	
	}
	return (1);
}
