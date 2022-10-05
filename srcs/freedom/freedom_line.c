/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freedom_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 11:24:02 by dpestana          #+#    #+#             */
/*   Updated: 2022/10/05 18:16:01 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

static void	freedom_cmd(t_data *data)
{
	while (data->line.cmd->qty_tkn > 0)
	{
		if ((data->line.cmd->token + (data->line.cmd->qty_tkn - 1)) != NULL)
		{
			free(*(data->line.cmd->token + (data->line.cmd->qty_tkn - 1)));
			*(data->line.cmd->token + (data->line.cmd->qty_tkn - 1)) = NULL;
		}
		data->line.cmd->qty_tkn--;
	}
	if (data->line.cmd->token != NULL)
	{
		free(data->line.cmd->token);
		data->line.cmd->token = NULL;
	}
}

void	freedom_line(t_data *data)
{
    if (data->line.cmd != NULL)
    {
        freedom_cmd(data);
	  	free(data->line.cmd);
		data->line.cmd = NULL;
    }
    data->line.qty_pipes = 0;
}
