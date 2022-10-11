/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:15:15 by dpestana          #+#    #+#             */
/*   Updated: 2022/10/11 15:32:53 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

static void	add_first_tkn(t_data *data, char *cmd)
{
	(data->line.cmd + data->line.qty_pipes)->token = malloc(sizeof(char **) * ((data->line.cmd + data->line.qty_pipes)->qty_tkn + 1));
	*(data->line.cmd + data->line.qty_pipes)->token = cmd;
	*((data->line.cmd + data->line.qty_pipes)->token + 1) = NULL;
	data->line.qty_cmd++;
}

static void	add_other_tkn(t_data *data, char *cmd)
{
	int		inc;
	char	**clone;

	inc = 0;
	clone = malloc(sizeof(char **) * ((data->line.cmd + data->line.qty_pipes)->qty_tkn + 1));
	while (inc < (data->line.cmd + data->line.qty_pipes)->qty_tkn - 1)
	{
		*(clone + inc) = *((data->line.cmd + data->line.qty_pipes)->token + inc);
		inc++;
	}
	*(clone + inc) = cmd;
	*(clone + inc + 1) = NULL;
	if ((data->line.cmd + data->line.qty_pipes)->token != NULL)
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
	(data->line.cmd + data->line.qty_pipes)->qty_tkn++;
	if ((data->line.cmd + data->line.qty_pipes)->token == NULL)
		add_first_tkn(data, cmd);
	else
		add_other_tkn(data, cmd);
}
