/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_another_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 19:48:18 by dpestana          #+#    #+#             */
/*   Updated: 2023/03/08 15:20:34 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

static t_cmd	inicialize_new_cmd(void)
{
	t_cmd	cmd;

	cmd.token = NULL;
	cmd.qty_tkn = 0;
	cmd.is_red = NO;
	cmd.qty_red = 0;
	cmd.red = NULL;
	cmd.is_heredoc = NO;
	cmd.pid = 0;
	cmd.is_builtin = NO;
	return (cmd);
}

void	add_another_cmd(t_data *data)
{
	int		inc;
	t_cmd	*clone;

	inc = 0;
	clone = malloc(sizeof(t_cmd) * (data->cur.table->qty_cmd + 1));
	while (inc < data->cur.table->qty_cmd)
	{
		(clone + inc)->token = (data->cur.table->cmd + inc)->token;
		(clone + inc)->qty_tkn = (data->cur.table->cmd + inc)->qty_tkn;
		(clone + inc)->is_red = (data->cur.table->cmd + inc)->is_red;
		(clone + inc)->qty_red = (data->cur.table->cmd + inc)->qty_red;
		(clone + inc)->red = (data->cur.table->cmd + inc)->red;
		(clone + inc)->is_heredoc = (data->cur.table->cmd + inc)->is_heredoc;
		(clone + inc)->pid = (data->cur.table->cmd + inc)->pid;
		(clone + inc)->is_builtin = (data->cur.table->cmd + inc)->is_builtin;
		inc++;
	}
	*(clone + inc) = inicialize_new_cmd();
	if (data->cur.table->cmd != NULL)
		free(data->cur.table->cmd);
	data->cur.table->cmd = clone;
	data->cur.table->qty_cmd++;
}
