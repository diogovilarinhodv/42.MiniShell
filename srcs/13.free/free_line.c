/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 11:24:02 by dpestana          #+#    #+#             */
/*   Updated: 2022/10/21 11:44:55 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

static void	free_cmd(t_data *data)
{
	while (data->table.cmd->qty_tkn > 0)
	{
		if ((data->table.cmd->token + (data->table.cmd->qty_tkn - 1)) != NULL)
		{
			free(*(data->table.cmd->token + (data->table.cmd->qty_tkn - 1)));
			*(data->table.cmd->token + (data->table.cmd->qty_tkn - 1)) = NULL;
		}
		data->table.cmd->qty_tkn--;
	}
	if (data->table.cmd->token != NULL)
	{
		free(data->table.cmd->token);
		data->table.cmd->token = NULL;
	}
}

void	free_line(t_data *data)
{
    if (data->table.cmd != NULL)
    {
        free_cmd(data);
	  	free(data->table.cmd);
		data->table.cmd = NULL;
    }
    data->table.qty_pipes = 0;
}
