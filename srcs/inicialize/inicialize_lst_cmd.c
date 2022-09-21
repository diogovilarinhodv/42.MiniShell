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

static void	increase_lst_cmd(t_data *data)
{
	int			inc;
	t_lst_cmd	*clone;

	inc = 0;
	clone = malloc(sizeof(t_lst_cmd) * (data->qty_pipes + 1));
	while (inc < data->qty_pipes)
	{
		(clone + inc)->cmd = (data->lst_cmd + inc)->cmd;
		(clone + inc)->args = (data->lst_cmd + inc)->args;
		(clone + inc)->qty_args = (data->lst_cmd + inc)->qty_args;
		inc++;
	}
	(clone + inc)->cmd = NULL;
	(clone + inc)->args = NULL;
	(clone + inc)->qty_args = 0;
	free(data->lst_cmd);
	data->lst_cmd = clone;
}

void	inicialize_lst_cmd(t_data *data)
{
	if (data->qty_pipes > 0)
		increase_lst_cmd(data);
	else
	{
		data->lst_cmd = malloc(sizeof(t_lst_cmd) * 1);
		data->lst_cmd->cmd = NULL;
		data->lst_cmd->args = NULL;
		data->lst_cmd ->qty_args = 0;
	}
}
