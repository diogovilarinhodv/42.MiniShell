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

void	freedom_lst_cmd(t_data *data)
{
	int	inc;

	if (data->lst_cmd->cmd != NULL)
		free(data->lst_cmd->cmd);
	if (data->lst_cmd->args != NULL)
	{
		inc = 0;
		while (inc < data->lst_cmd->qty_args)
		{
			if ((data->lst_cmd->args + inc) != NULL)
				free(*(data->lst_cmd->args + inc));
			inc++;
		}
		free(data->lst_cmd->args);
	}
	data->lst_cmd->cmd = NULL;
	data->lst_cmd->args = NULL;
	data->lst_cmd->qty_args = 0;
	data->qty_pipes = 0;
}
