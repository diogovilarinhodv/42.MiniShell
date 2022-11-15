/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_another_redirection.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpestana <dpestana@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 10:37:48 by dpestana          #+#    #+#             */
/*   Updated: 2022/11/15 16:02:11 by dpestana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/minishell.h"

void	add_another_redirection(t_data *data)
{
	t_red	*clone;
	int		inc;

	inc = 0;
	clone = malloc(sizeof(t_red) * (data->cur.cmd->qty_red + 1));
	while (inc < data->cur.cmd->qty_red)
	{
		(clone + inc)->token = (data->cur.cmd->red + inc)->token;
		(clone + inc)->type = (data->cur.cmd->red + inc)->type;
		inc++;
	}
	(clone + inc)->token = NULL;
	(clone + inc)->type = NO;
	free(data->cur.cmd->red);
	data->cur.cmd->red = clone;
	data->cur.cmd->is_red = YES;
	data->cur.cmd->qty_red++;
}