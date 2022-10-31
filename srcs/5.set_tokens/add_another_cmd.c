/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_another_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 19:48:18 by dpestana          #+#    #+#             */
/*   Updated: 2022/10/31 10:45:31 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	add_another_cmd(t_data *data)
{
	int		inc;
	t_cmd	*clone;

	set_cur(data);
	inc = 0;
	clone = malloc(sizeof(t_cmd) * (data->cur.table->qty_cmd + 1));
	while (inc < data->cur.table->qty_cmd)
	{
		(clone + inc)->token = (data->cur.table->cmd + inc)->token;
		(clone + inc)->qty_tkn = (data->cur.table->cmd + inc)->qty_tkn;
		inc++;
	}
	(clone + inc)->token = NULL;
	(clone + inc)->qty_tkn = 0;
	if (data->cur.table->cmd != NULL)
		free(data->cur.table->cmd);
	data->cur.table->cmd = clone;
	data->cur.table->qty_cmd++;
	unset_cur(data);
}