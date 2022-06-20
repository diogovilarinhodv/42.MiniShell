/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   organize_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/19 17:18:01 by dpestana          #+#    #+#             */
/*   Updated: 2022/06/20 20:00:07 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

static void	set_args(t_data *data, int pos_beg, int pos_end)
{
	int		inc;
	char	*tmp;
	char	**clone;

	inc = 0;
	data->input.qty_args++;
	tmp = ft_substr(data->input.line, pos_beg, pos_end - pos_beg);
	if (data->input.args != NULL)
	{
		clone = malloc(sizeof(char **) * data->input.qty_args);
		while (inc < data->input.qty_args - 1)
		{
			*(clone + inc) = *(data->input.args + inc);
			inc++;
		}
		*(clone + inc) = tmp;
		free(data->input.args);
		data->input.args = clone;
	}
	else
	{
		data->input.args = malloc(sizeof(char **) * data->input.qty_args);
		*data->input.args = tmp;
	}
}

void	organize_line(t_data *data)
{
	int		inc;
	int		cmd;
	int		pos_beg;
	int		pos_end;

	inc = 0;
	cmd = 0;
	pos_beg = 0;
	pos_end = 0;
	while (1)
	{
		while (*(data->input.line + inc) == ' ')
			inc++;
		pos_beg = inc;
		while (*(data->input.line + inc) != ' ' && *(data->input.line + inc) != '\0')
			inc++;
		pos_end = inc;
		if (pos_beg == pos_end)
			break;
		if (cmd == 0)
		{
			data->input.cmd = ft_substr(data->input.line, pos_beg, pos_end - pos_beg);
			cmd = 1;
		}
		else
			set_args(data, pos_beg, pos_end);
		if (*(data->input.line + inc) == '\0')
			break;
	}
}