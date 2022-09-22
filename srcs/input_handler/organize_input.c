/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   organize_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 17:18:01 by dpestana          #+#    #+#             */
/*   Updated: 2022/09/22 11:56:59 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

static	int	get_str_pos_beg(t_data *data, int *inc)
{
	while (*(data->input + *inc) == ' ')
		(*inc)++;
	return (*inc);
}

static	int	get_str_pos_end(t_data *data, int *inc)
{
	while (*(data->input + *inc) != ' ' && *(data->input + *inc) != '\0' && *(data->input + *inc) != '|')
		(*inc)++;
	return (*inc);
}

void	organize_input(t_data *data)
{
	int		inc;
	int		is_cmd;
	int		pos_beg;
	int		pos_end;

	inc = 0;
	is_cmd = 0;
	while (1)
	{
		if (*(data->input + inc) == '|')
		{
			data->line.qty_pipes++;
			inicialize_lst_cmd(data);
			is_cmd = 0;
			inc++;
		}
		pos_beg = get_str_pos_beg(data, &inc);
		pos_end = get_str_pos_end(data, &inc);
		if (pos_beg == pos_end)
			break ;
		if (is_cmd == 0)
			set_cmd(data, &is_cmd, pos_beg, pos_end);
		else
			set_args(data, pos_beg, pos_end);
		if (*(data->input + inc) == '\0')
			break ;
	}
}
