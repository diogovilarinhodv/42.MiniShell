/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freedom_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 11:24:02 by dpestana          #+#    #+#             */
/*   Updated: 2022/09/23 10:14:33 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

static void	freedom_cmd(t_data *data)
{
	if (data->line.cmd->token != NULL)
	{
		while (data->line.cmd->qty > 0)
		{
			if ((data->line.cmd->token + (data->line.cmd->qty - 1)) != NULL)
				free(*(data->line.cmd->token + (data->line.cmd->qty - 1)));
			data->line.cmd->qty--;
		}
		free(data->line.cmd->token);
	}
}

void	freedom_line(t_data *data)
{
    if (data->line.cmd != NULL)
    {
        freedom(data, FREEDOM_CMD);
	  	free(data->line.cmd);
    }
    data->line.qty_pipes = 0;
}