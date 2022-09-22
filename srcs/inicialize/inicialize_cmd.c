/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inicialize_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 14:39:16 by dpestana          #+#    #+#             */
/*   Updated: 2022/07/22 13:20:50 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

static void	increase_basic_cmd(t_data *data)
{
	int		inc;
	t_cmd	*clone;

	inc = 0;
	clone = malloc(sizeof(t_cmd) * (data->line.qty_pipes + 1));
	while (inc < data->line.qty_pipes)
	{
		(clone + inc)->token = (data->line.cmd + inc)->token;
		(clone + inc)->qty = (data->line.cmd + inc)->qty;
		inc++;
	}
	(clone + inc)->token = NULL;
	(clone + inc)->qty = 0;
	free(data->line.cmd);
	data->line.cmd = clone;
}

void	inicialize_cmd(t_data *data)
{
	if (data->line.qty_pipes > 0 && data->line.cmd != NULL)
		increase_basic_cmd(data);
	else
	{
		data->line.cmd = malloc(sizeof(t_cmd) * 1);
		data->line.cmd->token = NULL;
		data->line.cmd->qty = 0;
	}
}
