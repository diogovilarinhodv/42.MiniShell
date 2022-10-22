/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 11:24:02 by dpestana          #+#    #+#             */
/*   Updated: 2022/10/22 13:12:06 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

static void	free_cmd(t_data *data)
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

void	free_line(t_data *data)
{
    if (data->store.table->cmd != NULL)
    {
        free_cmd(data);
	  	free(data->store.table->cmd);
		data->store.table->cmd = NULL;
    }
    data->store.table->qty_pipes = 0;
}
