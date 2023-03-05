/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_redirects.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 10:18:53 by dpestana          #+#    #+#             */
/*   Updated: 2023/03/05 16:41:46 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	set_redirects(t_data *data)
{
	int		inc;
	t_red	*cur_red;

	inc = 0;
	if (data->cur.cmd->qty_red < 1)
	{
		data->exit_status = EXIT_SUCCESS;
		return ;
	}
	while (inc < data->cur.cmd->qty_red)
	{
		cur_red = (data->cur.cmd->red + inc);
		if (file_open(cur_red->token, cur_red->type, data->cur.cmd->is_heredoc) == -1)
		{
			data->exit_status = EXIT_FAILURE;
			return ;
		}
		inc++;
	}
	data->exit_status = EXIT_SUCCESS;
}
