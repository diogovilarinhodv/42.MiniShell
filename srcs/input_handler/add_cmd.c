/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 09:44:51 by dpestana          #+#    #+#             */
/*   Updated: 2022/10/05 17:49:59 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	add_cmd(t_data *data)
{
	int		inc;
	t_cmd	*clone;

	inc = 0;
	clone = malloc(sizeof(t_cmd) * (data->line.qty_pipes + 1));
	while (inc < data->line.qty_pipes)
	{
		(clone + inc)->token = (data->line.cmd + inc)->token;
		(clone + inc)->qty_tkn = (data->line.cmd + inc)->qty_tkn;
		inc++;
	}
	(clone + inc)->token = NULL;
	(clone + inc)->qty_tkn = 0;
	if (data->line.cmd != NULL)
		free(data->line.cmd);
	data->line.cmd = clone;
}