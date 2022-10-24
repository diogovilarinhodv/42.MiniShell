/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 11:24:02 by dpestana          #+#    #+#             */
/*   Updated: 2022/10/24 15:09:33 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

static void	free_token(t_data *data)
{
	while (data->store.table->cmd->qty_tkn > 0)
	{
		if ((data->store.table->cmd->token + (data->store.table->cmd->qty_tkn - 1)) != NULL)
		{
			free(*(data->store.table->cmd->token + (data->store.table->cmd->qty_tkn - 1)));
			*(data->store.table->cmd->token + (data->store.table->cmd->qty_tkn - 1)) = NULL;
		}
		data->store.table->cmd->qty_tkn--;
	}
	if (data->store.table->cmd->token != NULL)
	{
		free(data->store.table->cmd->token);
		data->store.table->cmd->token = NULL;
	}
}

static void	free_cmd(t_data *data)
{
	while ((data->store.table + data->store.qty_tbl - 1)->qty_cmd > 0)
	{
		if ((data->store.table + data->store.qty_tbl - 1)->cmd != NULL)
		{
			free_token(data);
			free((data->store.table + data->store.qty_tbl - 1)->cmd);
			(data->store.table + data->store.qty_tbl - 1)->cmd = NULL;
		}
		(data->store.table + data->store.qty_tbl - 1)->qty_pipes = 0;
		(data->store.table + data->store.qty_tbl - 1)->qty_cmd--;
	}
}

void	free_table(t_data *data)
{
	if (data->store.table != NULL)
	{
		free_cmd(data);
		free(data->store.table);
		data->store.table = NULL;
	}
}
