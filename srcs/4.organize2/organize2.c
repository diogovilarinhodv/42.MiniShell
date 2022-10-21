/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   organize2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 11:05:41 by dpestana          #+#    #+#             */
/*   Updated: 2022/10/21 12:04:23 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"
/*
static int	is_delimiter_table(char *str)
{
	if (*str == ';')
		return (YES);
	else if (*str == '|' && *(str + 1) == '|')
		return (YES);
	else if (*str == '&' && *(str + 1) == '&')
		return (YES);
	return (NO);
}

static void	get_new_table(t_data *data)
{
	while (*(data->input.line + data->input.idx) != '\0' && is_delimiter_table((data->input.line + data->input.idx)) == NO)
	{
		remove_spaces(data);
		if (*(data->input.line + data->input.idx) == '\0')
			break ;
		
	}
}
*/
void	organize2(t_data *data)
{

	data->table.qty_cmd = data->table.qty_cmd;

	/*t_table	*table;

	table = malloc(sizeof(t_table) * 1);
	while (*(data->input.line + data->input.idx) != '\0')
	{
		remove_spaces(data);
		if (*(data->input.line + data->input.idx) == '\0')
			break ;
		table = get_new_table(data);
		set_new_table(table);
	}*/
}