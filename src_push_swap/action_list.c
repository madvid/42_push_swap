/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md4 <md4@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 10:04:37 by md4               #+#    #+#             */
/*   Updated: 2020/05/28 01:13:03 by md4              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft.h"

/*
** Function: ft_reductible_motif_detector
** Parameters:
**		char *str1: string contening an action performed on the int stack
**		char *str2: string contening an action performed on the int stack
** Description:
**		Test if the action in str1 and the action in str2 can be reduced.
**		Indeed if str1 and str2 are 2 reverse actions they are annihilating
**		each others.
**		Caution: the 2 actions have to be consecutive or separate by no action
**		("000\n" string).
** Return:
**		0: no reduction motif action detected.
**		1: reduction motif action detected.
*/

int		ft_reductible_motif_detector(char *str1, char *str2)
{
	if ((ft_strcmp(str1, "pa\n") == 0 && ft_strcmp(str2, "pb\n") == 0)
		|| (ft_strcmp(str1, "pb\n") == 0 && ft_strcmp(str2, "pa\n") == 0)
		|| (ft_strcmp(str1, "ra\n") == 0 && ft_strcmp(str2, "rra\n") == 0)
		|| (ft_strcmp(str1, "rra\n") == 0 && ft_strcmp(str2, "ra\n") == 0)
		|| (ft_strcmp(str1, "rrb\n") == 0 && ft_strcmp(str2, "rb\n") == 0)
		|| (ft_strcmp(str1, "rb\n") == 0 && ft_strcmp(str2, "rrb\n") == 0))
	{
		return (1);
	}
	else
		return (0);
}

/*
** Function: ft_optimize_act_sequence
** Parameters:
**		t_pp *data:
** Description:
**	Check the sequence of actions stock in buffer and "destroy" segment of
**	actions useless. E.g: "pa pa pb pb" becomes "000 000 000".
**	"000" will be ignored when the sequence of actions stock in buffer will be
**	copy in act_list.
** Return:
**	None
*/

void	ft_optimize_act_sequence(char **buf)
{
	int		i;
	int		d;

	i = -1;
	while (buf != NULL && buf[++i])
	{
		d = 0;
		while (i - d > 0 && (buf[i - d] && buf[i + 1 + d]))
		{
			if (ft_reductible_motif_detector(buf[i - d], buf[i + 1 + d]) == 1)
			{
				ft_strcpy(buf[i - d], "000\n");
				ft_strcpy(buf[i + 1 + d], "000\n");
				d++;
			}
			else
			{
				i += d;
				break ;
			}
		}
	}
}

/*
** Function: ft_buf_to_list
** Parameters:
**		char **ac_list:
**		char **buffer:
** Description:
**	Copy the actions from buffer to act_list.
** Return:
**	1: no allocation memory issue raisen up
**	0: memory allocation issue occured.
*/

char	**ft_buf_to_list(char **act_list, char **buffer)
{
	int			len1;
	int			len2;
	char		**table;
	int			d;

	if (ft_check_full(buffer, "000\n") == 1)
		return (NULL);
	len1 = (act_list != NULL) ? ft_tablelen(act_list) : 0;
	len2 = (buffer != NULL) ? ft_tablelen(buffer) : 0;
	d = ft_table_nb_motif(buffer, "000\n");
	if ((table = ft_table_str(len1 + len2 - d, 4)) == NULL)
		return (NULL);
	ft_tablecpy_wtht_motif(table, act_list, "000\n");
	ft_tablecpy_wtht_motif((table + len1), buffer, "000\n");
	return (table);
}

/*
** Function: ft_clear_buf
** Parameters:
**		char* bufer:
** Description:
**	Clear the buffer, meaning the buffer is filled with "000".
** Return:
**	None
*/

void	ft_clear_buf(char **buffer)
{
	size_t	i;

	i = 0;
	while (buffer[i] != NULL)
	{
		ft_strcpy(buffer[i], "000\n");
		i++;
	}
}

/*
** Function: ft_add_actions
** Parameters:
**		t_pp *data:
**		char* act:
** Description:
**	Add the action act to the list of actions which will be the list of
**  actions to perform to sort the list.
** Return:
**	None
*/

int		ft_add_actions(t_pp *data, char *act)
{
	char	**table;

	table = NULL;
	if (data->act_list[data->i_act] != NULL)
	{
		ft_strcpy(data->act_list[data->i_act], act);
		data->i_act++;
		return (1);
	}
	table = ft_table_str(ft_tablelen(data->act_list) + data->tot_len, 4);
	if (table == NULL)
	{
		ft_free_table_str(data->act_list);
		write(1, "Error, memory allocation failed or buffer is empty\n", 51);
		return (0);
	}
	ft_tablecpy(table, data->act_list);
	ft_strcpy(table[data->i_act], act);
	ft_free_table_str(data->act_list);
	data->act_list = table;
	data->i_act++;
	return (1);
}
