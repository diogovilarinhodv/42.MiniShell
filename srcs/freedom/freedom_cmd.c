/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freedom_lst_cmd->c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 19:03:20 by dpestana          #+#    #+#             */
/*   Updated: 2022/06/21 19:08:06 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	freedom_cmd(t_data *data)
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
