/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:15:15 by dpestana          #+#    #+#             */
/*   Updated: 2022/09/23 13:43:47 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

static void	add_first_cmd(t_data *data, char *cmd)
{
	(data->line.cmd + data->line.qty_pipes)->token = malloc(sizeof(char **) * (data->line.cmd + data->line.qty_pipes)->qty);
	*(data->line.cmd + data->line.qty_pipes)->token = cmd;
}

static void	add_other_cmd(t_data *data, char *cmd)
{
	int		inc;
	char	**clone;

	inc = 0;
	clone = malloc(sizeof(char **) * (data->line.cmd + data->line.qty_pipes)->qty);
	while (inc < (data->line.cmd + data->line.qty_pipes)->qty - 1)
	{
		*(clone + inc) = *((data->line.cmd + data->line.qty_pipes)->token + inc);
		inc++;
	}
	*(clone + inc) = cmd;
	free((data->line.cmd + data->line.qty_pipes)->token);
	(data->line.cmd + data->line.qty_pipes)->token = clone;
}

void	set_cmd(t_data *data, int has_pipe, int pos_beg, int pos_end)
{
	char	*cmd;

	if (has_pipe > 0)
	{
		data->line.qty_pipes++;
		add_cmd(data);
	}
	cmd = ft_substr(data->input, pos_beg, pos_end - pos_beg);
	(data->line.cmd + data->line.qty_pipes)->qty++;
	if ((data->line.cmd + data->line.qty_pipes)->token == NULL)
		add_first_cmd(data, cmd);
	else
		add_other_cmd(data, cmd);
}
