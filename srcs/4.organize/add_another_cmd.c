/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_another_cmd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 19:48:18 by dpestana          #+#    #+#             */
/*   Updated: 2022/10/21 11:44:55 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	add_another_cmd(t_data *data)
{
	int		inc;
	t_cmd	*clone;

	inc = 0;
	clone = malloc(sizeof(t_cmd) * (data->table.qty_cmd + 1));
	while (inc < data->table.qty_cmd)
	{
		(clone + inc)->token = (data->table.cmd + inc)->token;
		(clone + inc)->qty_tkn = (data->table.cmd + inc)->qty_tkn;
		inc++;
	}
	(clone + inc)->token = NULL;
	(clone + inc)->qty_tkn = 0;
	if (data->table.cmd != NULL)
		free(data->table.cmd);
	data->table.cmd = clone;
}