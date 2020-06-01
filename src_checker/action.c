/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md4 <md4@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 18:25:03 by md4               #+#    #+#             */
/*   Updated: 2020/06/01 18:26:22 by md4              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
#include "common.h"
#include "libft.h"

/*
** Function: ft_check_action
** Parameters:
**		char *action:
** Description:
**	Check the validity of the action read/given byt the user.
** Return:
**	char *str: a string corresponding to action
**	NULL: if the action is not correct
*/

char	*ft_check_action(char *action)
{
	if (action != NULL && ft_strcmp("sa", action) == 0)
		return ("sa");
	else if (action != NULL && ft_strcmp("sb", action) == 0)
		return ("sb");
	else if (action != NULL && ft_strcmp("ss", action) == 0)
		return ("ss");
	else if (action != NULL && ft_strcmp("pa", action) == 0)
		return ("pa");
	else if (action != NULL && ft_strcmp("pb", action) == 0)
		return ("pb");
	else if (action != NULL && ft_strcmp("ra", action) == 0)
		return ("ra");
	else if (action != NULL && ft_strcmp("rb", action) == 0)
		return ("rb");
	else if (action != NULL && ft_strcmp("rr", action) == 0)
		return ("rr");
	else if (action != NULL && ft_strcmp("rra", action) == 0)
		return ("rra");
	else if (action != NULL && ft_strcmp("rrb", action) == 0)
		return ("rrb");
	else if (action != NULL && ft_strcmp("rrr", action) == 0)
		return ("rrr");
	else
		return (NULL);
}

/*
** Function: ft_perform_action
** Parameters:
**		t_pp *data:
**		t_info info:
**		char *action:
** Description:
**	Perform the action "pa"/"pb"/"sa" ... present in string action
**	on the stacks.
** Return:
**		NOne
*/

void	ft_perform_action(t_pp *data, t_info *info, char *action)
{
	if (ft_strcmp("sa", action) == 0)
		ft_s_a(data, *info);
	else if (ft_strcmp("sb", action) == 0)
		ft_s_b(data, *info);
	else if (ft_strcmp("ss", action) == 0)
		ft_swap_ss(data, *info);
	else if (ft_strcmp("pa", action) == 0)
		ft_p_a(data, info);
	else if (ft_strcmp("pb", action) == 0)
		ft_p_b(data, info);
	else if (ft_strcmp("ra", action) == 0)
		ft_r_a(data, *info);
	else if (ft_strcmp("rb", action) == 0)
		ft_r_b(data, *info);
	else if (ft_strcmp("rr", action) == 0)
		ft_rr(data, *info);
	else if (ft_strcmp("rra", action) == 0)
		ft_rr_a(data, *info);
	else if (ft_strcmp("rrb", action) == 0)
		ft_rr_b(data, *info);
	else
		ft_rrr(data, *info);
}
