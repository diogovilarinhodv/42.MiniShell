/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_store.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 11:24:02 by dpestana          #+#    #+#             */
/*   Updated: 2023/02/10 14:59:14 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

static void	free_red(t_cmd *cmd)
{
	int	inc;

	inc = 0;
	if (cmd->red != NULL)
	{
		while (inc < cmd->qty_red)
		{
			free((cmd->red + inc)->token);
			(cmd->red + inc)->token = NULL;
			(cmd->red + inc)->type = NO;
			inc++;
		}
		free(cmd->red);
		cmd->red = NULL;
	}
}

static void	free_cmd(t_cmd *cmd)
{
	int	inc_token;

	inc_token = 0;
	if (cmd->token != NULL)
	{
		while (inc_token < cmd->qty_tkn)
		{
			if (*(cmd->token + inc_token) != NULL)
				free(*(cmd->token + inc_token));
			inc_token++;
		}
		free(cmd->token);
		cmd->token = NULL;
	}
	free_red(cmd);
}

static void	free_table(t_table *table)
{
	int	inc_cmd;

	inc_cmd = 0;
	if (table->cmd != NULL)
	{
		while (inc_cmd < table->qty_cmd)
		{
			free_cmd((table->cmd + inc_cmd));
			inc_cmd++;
		}
		free(table->cmd);
		table->cmd = NULL;
	}
}

void	free_store(t_data *data)
{
	int	inc_table;

	inc_table = 0;
	if (data->store.table != NULL)
	{
		while (inc_table < data->store.qty_tbl)
		{
			free_table((data->store.table + inc_table));
			inc_table++;
		}
		free(data->store.table);
		data->store.table = NULL;
	}
	data->store.qty_tbl = 0;
}
