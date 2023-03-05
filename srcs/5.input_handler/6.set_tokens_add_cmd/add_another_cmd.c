/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_another_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 19:48:18 by dpestana          #+#    #+#             */
/*   Updated: 2023/03/05 14:49:16 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../incs/minishell.h"

void	add_another_cmd(t_data *data)
{
	int		inc;
	t_cmd	*clone;

	inc = 0;
	clone = malloc(sizeof(t_cmd) * (data->cur.table->qty_cmd + 1));
	while (inc < data->cur.table->qty_cmd)
	{
		(clone + inc)->token = (data->cur.table->cmd + inc)->token;
		(clone + inc)->qty_tkn = (data->cur.table->cmd + inc)->qty_tkn;
		(clone + inc)->is_red = (data->cur.table->cmd + inc)->is_red;
		(clone + inc)->qty_red = (data->cur.table->cmd + inc)->qty_red;
		(clone + inc)->red = (data->cur.table->cmd + inc)->red;
		inc++;
	}
	(clone + inc)->token = NULL;
	(clone + inc)->qty_tkn = 0;
	(clone + inc)->is_red = NO;
	(clone + inc)->qty_red = 0;
	(clone + inc)->red = NULL;
	(clone + inc)->is_heredoc = NO;
	if (data->cur.table->cmd != NULL)
		free(data->cur.table->cmd);
	data->cur.table->cmd = clone;
	data->cur.table->qty_cmd++;
}
