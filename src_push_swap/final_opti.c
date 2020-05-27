/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   final_opti.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: md4 <md4@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 22:02:22 by md4               #+#    #+#             */
/*   Updated: 2020/05/28 00:34:38 by md4              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"
#include "libft.h"

/*
** Function: ft_final_opti_1
** Parameters:
**		t_pp *data: struct containing stack ints and the table of actions
** Description:
**		A last run for opti: collecting the last actions still in buffer
**      which are add in act_list, then optimization, copying without "000\n"
**      then a very last optimization (indeed during the "first last opti"
**      "00\n" can remain between sequence actions list that can be reduced).
**	Return:
**		1: if no memory allocation of NULL pointer was encountered.
**		0: if memory allocation of NULL pointer was encountered.
*/

/*int		ft_final_opti_1(t_pp *data)
{
	char	**table;
	int		len;
	int		d;

	table = ft_buf_to_list(data->act_list, data->buf_act);
	ft_free_table_str(data->act_list);
	ft_optimize_act_sequence(table);
	len = ft_tablelen(table);
	d = ft_table_nb_motif(table, "000\n");
	data->act_list = ft_table_str(len - d, 4);
	if (table == NULL || d == -1 || len == -1 || data->act_list == NULL)
	{
		ft_free_table_str(table);
		return (0);
	}
	ft_tablecpy_wtht_motif(data->act_list, table, "000\n");
	ft_free_table_str(table);
	ft_optimize_act_sequence(data->act_list);
	d = ft_table_nb_motif(data->act_list, "000\n");
	len = ft_tablelen(data->act_list);
	table = ft_table_str(len - d, 4);
	return (ft_final_opti_2(data, table, len, d));
}*/

/* a tester*/
int		ft_final_opti_1(t_pp *data)
{
	char	**table;
	int		len;
	int		d;

	table = NULL;
	ft_optimize_act_sequence(data->act_list);
	len = ft_tablelen(data->act_list);
	d = ft_table_nb_motif(data->act_list, "000\n");
	//printf("valeur de len = %d -- valeur de d = %d\n", len, d);
	table = ft_table_str(len - d, 4);
	if (table == NULL || d == -1 || len == -1 || data->act_list == NULL)
	{
		ft_free_table_str(table);
		return (0);
	}
	ft_tablecpy_wtht_motif(table, data->act_list, "000\n");
	ft_free_table_str(data->act_list);
	data->act_list = table;
	//pp_print_act_list(data->act_list);
	return (1);
}

/*
** Function: ft_final_opti_2
** Parameters:
**		t_pp *data: struct containing stack ints and the table of actions.
**		char **table: table of string to manipulate the list of actions.
**		int len: length of action list (act_list)
**		int d: number of str "000\n" after a run of opti on actions table.
** Description:
**		Second part of ft_final_opti_2.
**	Return:
**		1: if no memory allocation of NULL pointer was encountered.
**		0: if memory allocation of NULL pointer was encountered.
*/

/*int		ft_final_opti_2(t_pp *data, char **table, int len, int d)
{
	if (table == NULL || d == -1 || len == -1 || data->act_list == NULL)
	{
		ft_free_table_str(data->buf_act);
		ft_free_table_str(table);
		return (0);
	}
	ft_tablecpy_wtht_motif(table, data->act_list, "000\n");
	ft_free_table_str(data->act_list);
	data->act_list = table;
	return (1);
}*/
